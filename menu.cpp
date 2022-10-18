#include"funcoes.h"

int menu(int status);

int main (){
    Curso* lcCurso;
    FILE* acertos,* cursosPesos,* cursosVagas,* dados;
    int resposta, status, aux;
    status=0;
    do{
        resposta=menu(status);
        if(status==0 && resposta==0){
            aux=lerArquivos(acertos, cursosPesos, cursosVagas, dados, lcCurso);
            if(aux=1){
                return 1;
            }
        }
        else if(resposta==1){
            retornarArquivos();
        }
        else if(resposta==2){
            pesquisarPessoa();
        }
        else if(resposta==3){
            listarReprovados();
        }
        else if(resposta==4){
            listarAprovados();
        }
        else{
            encerrarPrograma(&acertos, &cursosPesos, &cursosVagas, &dados);
            return 0;
        }
    }while(1);
}

int menu(int status){
    int resposta;
    do{
        if(status==0){
            printf("Opção 0");
        }
        printf("Opção 1");
        printf("Opção 2");
        printf("Opção 3");
        printf("Opção 4");
        printf("Opção 5");
        scanf("%d", &resposta);
    }while(resposta<-1 && resposta>6);
    return resposta;
}