#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define MAXNOME 80
#define MAXNOMECURSO 50
#define TIPOCURSO 12
#define TIPOVAGA 2

struct Data{
    int dia;
    int mes;
    int ano;
};

struct Curso{
    int codigo;
    char nome[MAXNOMECURSO+1];
    char tipoCurso[TIPOCURSO+1];
    int pRED;
    int pMAT;
    int pLIN;
    int pHUM;
    int pNAT;
};

struct Aluno{
    int inscrição;
    char nome[MAXNOME+1];
    char vaga[TIPOVAGA+1];
    int LINacertos;
    int MATacertos;
    int NATacertos;
    int HUMacertos;
    int REDacertos;
    int notaFinal;
    char status[10]; //Aprovado || Reprovado
    struct Data dataNasc;
    struct Curso* FK_codCurso;
};


// Funções ler arquivos
int lerArquivos(FILE* acertos, FILE* cursosPesos, FILE* cursosVagas, FILE* dados, struct Curso* lcCurso);
void gerarListaCursos(FILE* cursosPesos, FILE* cursosVagas, struct Curso* lcPesos);
void quickSortCurso(struct Curso* lcPesos, int init, int end);
int organizaCurso(struct Curso* lcPesos, int init, int end);
void trocaCursos(struct Curso* lcPesosInit, struct Curso* lcPesosEnd);



void retornarArquivos();
int pesquisarPessoa();
void listarReprovados();
void listarAprovados();

//Funções encerrar programa
void encerrarPrograma(FILE* acertos, FILE* cursosPesos, FILE* cursosVagas, FILE* dados, struct Curso* lcCurso);
void encerrarListaCursos(struct Curso* lcCurso);