#include "alunos.h"
#include <string.h>
//#include <ctype.h>

void cadastroAluno(tAluno* A,int &n,char* nomeAluno,int RA,double nP1,double nP2,double nTP,double nPO)
{
    strcpy(A[n].nomeAluno,nomeAluno);
    A[n].RA = RA;
    A[n].nP1 = nP1;
    A[n].nP2 = nP2;
    A[n].nTP = nTP;
    A[n].nPO = nPO;
    n++;

    printf("\nAluno cadastrado com sucesso!\n");
}

void imprimirAluno(tAluno* A,int n){
    ordenaAlunos(A,n);
    printf("*** Dados dos Alunos Cadastradas ***\n");
    for(int i=0;i<n;i++){     
        printf("\nNome: %s\n",A[i].nomeAluno);
        printf("RA: %d\n",A[i].RA);
        printf("Nota P1: %.2f\n",A[i].nP1);
        printf("Nota P2: %.2f\n",A[i].nP2);
        printf("Nota TP: %.2f\n",A[i].nTP);
        printf("Nota PO: %.2f\n",A[i].nPO);
    }
}
FILE *abrirArquivo(char *nomeArquivo, tAluno *A, int &n){
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("\nErro ao abrir o arquivo!\n");
    }
    else{         
            if(!feof(arquivo)){
            fscanf(arquivo,"%s %d %lf %lf %lf %lf",A[n].nomeAluno,&A[n].RA,&A[n].nP1,&A[n].nP2,&A[n].nTP,&A[n].nPO);
            cadastroAluno(A,n,A[n].nomeAluno,A[n].RA,A[n].nP1,A[n].nP2,A[n].nTP,A[n].nPO);
                //cadastroAluno(A,n,A->nomeAluno,A->RA,A->nP1,A->nP2,A->nTP,A->nPO);
                n++;
            }
            //fscanf(arquivo,"%s %d %lf %lf %lf %lf",A->nomeAluno,&A->RA,&A->nP1,&A->nP2,&A->nTP,&A->nPO); //verificar pq não le o nome
            
            //n++;
            printf("\nArquivo aberto com sucesso!\n");
            }
    return arquivo;
}

//FILE *aprovados(FILE *arquivo, tAluno *A, int n){
FILE *aprovados(tAluno* A, int n){
    FILE *arquivoAprovados;
    double mediaFinal;
    int qtdAprovados = 0;

    arquivoAprovados = fopen("aprovados.txt","w");
    if(arquivoAprovados == NULL){
        printf("\nErro ao abrir o arquivo!\n");
    }
    else{
        ordenaAlunos(A,n);
        for(int i=0;i<n;i++){  
            mediaFinal = (A[i].nP1, A[i].nP2, A[i].nPO, A[i].nTP);
            if(mediaFinal >= 6){
                qtdAprovados++;
                fprintf(arquivoAprovados,"%s %d %.1f\n",A[i].nomeAluno, A[i].RA, mediaFinal);
            }
           
        }
        fprintf(arquivoAprovados,"Total: %d\n",qtdAprovados);
        printf("\nArquivo criado com sucesso!\n");
        fclose(arquivoAprovados);
    }
    return arquivoAprovados;
}

FILE *reprovados(tAluno* A, int n){
    FILE *arquivoReprovados;
    double mediaFinal;
    int qtdReprovados = 0;

    arquivoReprovados = fopen("reprovados.txt","w");
    if(arquivoReprovados == NULL){
        printf("\nErro ao abrir o arquivo!\n");
    }
    else{
        ordenaAlunos(A,n);
        for(int i=0;i<n;i++){  
            mediaFinal = (A[i].nP1, A[i].nP2, A[i].nPO, A[i].nTP);
            if(mediaFinal < 6){
                qtdReprovados++;
                fprintf(arquivoReprovados,"%s %d %.1f\n",A[i].nomeAluno, A[i].RA, mediaFinal);
            }
           
        }
        fprintf(arquivoReprovados,"Total: %d\n",qtdReprovados);
        printf("\nArquivo criado com sucesso!\n");
        fclose(arquivoReprovados);
    }
    return arquivoReprovados;
}

void buscarAluno(tAluno* A, char *nomeAluno, int n){
    int i, contador;
    double mediaFinal;
    contador = 0;
    for(i=0;i<n;i++){
       if(strcmp(A[i].nomeAluno,nomeAluno) == 0){ //Procura o aluno digitado
            contador++;
            printf("\nNome: %s\n",A[i].nomeAluno);
            mediaFinal = calculaMediaFinal(A[i].nP1,A[i].nP2,A[i].nPO, A[i].nTP);
            //calcular media final
            //Se a nota da PO for maior que a nota da P1, a nota da P1 recebe a nota da PO
            /*if(A[i].nPO > A[i].nP1) {
                A[i].nP1 = A[i].nPO;
                mediaFinal = ((A[i].nP1 * 0.35) + (A[i].nP2 * 0.35) + (A[i].nTP * 0.3));
                printf("Media Final: %.2f\n",mediaFinal);

            }
            else if(A[i].nPO > A[i].nP2) {
                A[i].nP2 = A[i].nPO;
                mediaFinal = ((A[i].nP1 * 0.35) + (A[i].nP2 * 0.35) + (A[i].nTP * 0.3));
                printf("Media Final: %.2f\n",mediaFinal);
            }
            else 
            {
                mediaFinal = ((A[i].nP1 * 0.35) + (A[i].nP2 * 0.35) + (A[i].nTP * 0.3));
                printf("Media Final: %.2f\n",mediaFinal);
            }*/
            if(mediaFinal >= 6.0){
                    printf("\nAprovado!\n");
                }
                else{
                    printf("\nReprovado!\n");
                }
            

            //Fazer situacao do aluno

            //Contagem de resultados encontrados
        }
        else{
            printf("\nAluno nao encontrado!\n"); //corrigir, ta imprimindo váriaa vezes
        }
    }
        printf("Numero de resultados encontrados: %d\n", contador);
   // }

}

float calculaMediaFinal(double nP1, double nP2, double nPO, double nTP){
    float mediaFinal;
        if(nPO > nP1) {
            nP1 = nPO;
            mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
            printf("Media Final: %.2f\n",mediaFinal);

        }
        else if(nPO > nP2) {
            nP2 = nPO;
            mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
            printf("Media Final: %.2f\n",mediaFinal);
        }
        else 
        {
            mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
            printf("Media Final: %.2f\n",mediaFinal);
        }
    return mediaFinal;
}
void ordenaAlunos(tAluno* A, int n){
    int i, j;
    tAluno aux;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(A[i].nomeAluno,A[j].nomeAluno) > 0){
                aux = A[i];
                A[i] = A[j];
                A[j] = aux;
            }
            if(strcmp(A[i].nomeAluno,A[j].nomeAluno) == 0){
                if(A[i].RA > A[j].RA){
                    aux = A[i];
                    A[i] = A[j];
                    A[j] = aux;
                }
            }
        }
    }
}

FILE *arquivoDadosInseridos(tAluno* A,int n){
    FILE *arqDadosInseridos;

    arqDadosInseridos = fopen("atual.txt","w");
    if(arqDadosInseridos == NULL){
        printf("\nErro ao abrir o arquivo!\n");
    }
    else{
        ordenaAlunos(A,n);
        for(int i=0;i<n;i++){
            fprintf(arqDadosInseridos,"%s %d %.1f %.1f %.1f %.1f \n",A[i].nomeAluno, A[i].RA, A[i].nP1, A[i].nP2, A[i]. nTP,A[i].nPO);            
            }
           
        }
        printf("\nArquivo criado com sucesso!\n");
        fclose(arqDadosInseridos);
    return arqDadosInseridos;
}