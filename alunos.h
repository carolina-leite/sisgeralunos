#include <stdio.h>
#include <string.h>
#define TAMSTR 80
#define MAX 60

struct tAluno
{
    char nomeAluno[TAMSTR];
    int RA;
    double nP1;
    double nP2;
    double nTP;
    double nPO;
};

void cadastroAluno(tAluno* A,int &n,char* nomeAluno,int RA,double nP1,double nP2,double nTP,double nPO);
//void inserirAluno(tAluno* M,int &tamA,int pos,char nomeAluno,int RA,double nP1,double nP2,double nTP, nPO);
void imprimirAluno(tAluno* A,int n);
float calculaMediaFinal(double nP1, double nP2, double nPO, double nTP);
void ordenaAlunos(tAluno* A, int n);
FILE *abrirArquivo(char *nomeArquivo, tAluno *A, int &n);
//FILE *aprovados(FILE *arquivo, tAluno *A, int n);
FILE *aprovados(tAluno* A, int n);
FILE *reprovados(tAluno* A, int n);
void buscarAluno(tAluno* A, char *nomeAluno, int n);
FILE *arquivoDadosInseridos(tAluno* A,int n);