#include"funcoes.h"

void trocaCursos(Curso* lcPesosInit, Curso* lcPesosEnd){
    Curso aux;
    aux = *lcPesosInit;
    *lcPesosInit = *lcPesosEnd;
    *lcPesosEnd = aux;
    return;
}

int organizaCurso(Curso* lcPesos, int init, int end){
    int aux, i, j; 
    i= init-1;
    j= end+1;
    Curso auxTroca;
    aux=lcPesos[init].codigo;
    while(1){
        do{
            j--;
        } while (lcPesos[j].codigo > aux);
        do {
            i++;
        } while (lcPesos[i].codigo <aux);
        if(init<end){
            trocaCursos(&lcPesos[init], &lcPesos[end]);
            auxTroca=lcPesos[init];
            lcPesos[init]=lcPesos[end];
            lcPesos[end]=auxTroca;
        }
        else{
            return end;
        }
    }
}

void quickSortCurso(Curso* lcPesos, int init, int end){
    int n;
    if (init<end){
        n=organizaCurso(lcPesos, 0, end);
        quickSortCurso(lcPesos, 0, n);
        quickSortCurso(lcPesos, n+1, end);
    }
}

void gerarListaCursos(FILE** cursosPesos, FILE** cursosVagas, Curso* lcPesos){ // lcPesos = lista curso pesos
    FILE* aux;
    int n;
    aux = *cursosPesos;
    fscanf(aux, "%d", n);
    lcPesos=(Curso*) calloc(n, sizeof(Curso));
    for(int cont = 0; feof(aux) != NULL && cont<n ; cont++){
        fscanf(aux, "%d", lcPesos[cont].codigo);
        fscanf(aux, "%[^-]", lcPesos[cont].nome);
        fscanf(aux, "%s", lcPesos[cont].tipoCurso);
        fscanf(aux, "%d", lcPesos[cont].pRED);
        fscanf(aux, "%d", lcPesos[cont].pMAT);
        fscanf(aux, "%d", lcPesos[cont].pLIN);
        fscanf(aux, "%d", lcPesos[cont].pHUM);
        fscanf(aux, "%d", lcPesos[cont].pNAT);
    }
    aux = *cursosVagas;
    quickSortCurso(lcPesos, 0, n-1);
    //for(int cont = 0; feof(aux) != NULL && cont<n ; cont++){
        
    //}
}

void gerarListaAluno();

int lerArquivos(FILE* acertos, FILE* cursosPesos, FILE* cursosVagas, FILE* dados, Curso* lcCurso){
    acertos = fopen("acertos.txt", "r");
    if(acertos==NULL){
        return 1;
    }
    cursosPesos = fopen("cursos_e_pesos.txt", "r");
        if(cursosPesos==NULL){
            fclose(acertos);
            return 1;
    }
    cursosVagas = fopen("cursos_e_vagas.txt", "r");
        if(cursosVagas==NULL){
            fclose(acertos);
            fclose(cursosPesos);
            return 1;
    }
    dados = fopen("dados.txt", "r");
        if(dados==NULL){
            fclose(acertos);
            fclose(cursosPesos);
            fclose(cursosVagas);
            return 1;
    }
    gerarListaCursos(&cursosPesos, &cursosVagas, lcCurso);
    gerarListaAluno();
    return 0;
}







void encerrarPrograma(FILE** acertos, FILE** cursosPesos, FILE** cursosVagas, FILE** dados){
    fclose(*acertos);
    fclose(*cursosPesos);
    fclose(*cursosVagas);
    fclose(*dados);
    return;
}