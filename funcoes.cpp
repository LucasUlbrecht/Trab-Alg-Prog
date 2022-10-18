#include"funcoes.h"

//Funções gerar lista

void trocaCursos(Curso* lcPesosInit, Curso* lcPesosEnd);
int organizaCurso(Curso* lcPesos, int init, int end);
void quickSortCurso(Curso* lcPesos, int init, int end);
void gerarListaCursos(FILE** cursosPesos, FILE** cursosVagas, Curso* lcPesos);
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
    //gerarListaAluno();
    return 0;
}


void gerarListaCursos(FILE** cursosPesos, FILE** cursosVagas, Curso* lcPesos){ // lcPesos = lista curso pesos
    FILE* aux;
    int n;
    aux = *cursosPesos;
    fscanf(aux, "%d", n);
    lcPesos=(Curso*) calloc(n, sizeof(Curso));
    for(int cont = 0; feof(aux) != NULL && cont<n ; cont++){
        fscanf(aux, "%d %[^-] %s %d %d %d %d %d", &lcPesos[cont].codigo, &lcPesos[cont].nome, &lcPesos[cont].tipoCurso, &lcPesos[cont].pRED, &lcPesos[cont].pMAT, &lcPesos[cont].pLIN, &lcPesos[cont].pHUM, &lcPesos[cont].pNAT);
    }
    aux = *cursosVagas;
    quickSortCurso(lcPesos, 0, n-1);
    //for(int cont = 0; feof(aux) != NULL && cont<n ; cont++){
        
    //}
}


void quickSortCurso(Curso* lcPesos, int init, int end){
    int n;
    if (init<end){
        n=organizaCurso(lcPesos, 0, end);
        quickSortCurso(lcPesos, 0, n);
        quickSortCurso(lcPesos, n+1, end);
    }
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




//Funções encerrar lista

void encerrarListaCursos(Curso* lcCurso);
void encerrarPrograma(FILE** acertos, FILE** cursosPesos, FILE** cursosVagas, FILE** dados, Curso* lcCurso){
    fclose(*acertos);
    fclose(*cursosPesos);
    fclose(*cursosVagas);
    fclose(*dados);
    //encerrarListaCursos(lcCurso);
    return;
}