#include "alunos.h"
#include <string.h>


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

FILE *abrirArquivo(char *nomeArquivo, tAluno *A, int &n){
    FILE *arquivo;

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL){
        printf("\nErro ao abrir o arquivo!\n");
    }
    else{
        while (fscanf(arquivo,"%[^0123456789] %d %lf %lf %lf %lf", A[n].nomeAluno, &A[n].RA, &A[n].nP1, &A[n].nP2, &A[n].nTP, &A[n].nPO) != EOF){
            n++;
            
        }
            printf("\nArquivo aberto com sucesso!\n");
            printf("Foram cadastrados %d alunos!\n", n);            
    }
    return arquivo;
}

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
            mediaFinal = calculaMediaFinal(A[i].nP1, A[i].nP2, A[i].nPO, A[i].nTP);
            if(mediaFinal >= 6){               
                qtdAprovados++;
                fprintf(arquivoAprovados,"%s %d %.1f\n",A[i].nomeAluno, A[i].RA, mediaFinal);
            }
           
        }
        fprintf(arquivoAprovados,"\nTotal: %d",qtdAprovados);
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
    else
    {
        ordenaAlunos(A,n);
        for(int i=0;i<n;i++){
            mediaFinal = calculaMediaFinal(A[i].nP1, A[i].nP2, A[i].nPO, A[i].nTP);           
            if(mediaFinal < 6){
                qtdReprovados++;
                fprintf(arquivoReprovados,"%s %d %.1f\n",A[i].nomeAluno, A[i].RA, mediaFinal);
            }          
        }
        fprintf(arquivoReprovados,"\nTotal: %d",qtdReprovados);
        printf("\nArquivo criado com sucesso!\n");
        fclose(arquivoReprovados);
    }
    return arquivoReprovados;
}

void buscarAluno(tAluno* A, char *nomeAluno, int n){
    int i, contador;
    double mediaFinal;
    char *sbstring;
    contador = 0;
    for(i=0;i<n;i++){
        sbstring = strstr(A[i].nomeAluno, nomeAluno);
        if(sbstring != NULL){
            mediaFinal = calculaMediaFinal(A[i].nP1, A[i].nP2, A[i].nPO, A[i].nTP);
            printf("\n%s %d %.1f\n",A[i].nomeAluno, A[i].RA, mediaFinal);
            contador++;
            if(mediaFinal >= 6.0){
                printf("Aprovado!\n");
                }
            else{
                printf("Reprovado!\n");
            }
        }
    }       
    if(contador == 0){
        printf("\nAluno nao encontrado!\n");
    }
    printf("Numero de resultados encontrados: %d\n", contador);
}

float calculaMediaFinal(double nP1, double nP2, double nPO, double nTP){
    float mediaFinal;

        if(nPO >= nP1 && nPO >= nP2) {
            if(nP1 < nP2) {
                nP1 = nPO;
                mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
            }
            else{
                nP2 = nPO;
                mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
            }
        }
        else if(nPO > nP1 && nPO < nP2){
            nP1 = nPO;
            mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
        }
        else if(nPO < nP1 && nPO > nP2){
            nP2 = nPO;
            mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.3));
        }
        else if(nPO < nP1 && nPO < nP2)
        {
            mediaFinal = ((nP1 * 0.35) + (nP2 * 0.35) + (nTP * 0.30));
        }
    return mediaFinal;
}
void ordenaAlunos(tAluno* A, int n){
    int i, j, min;
    tAluno aux;

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(strcmp(A[j].nomeAluno,A[min].nomeAluno) < 0){
                min = j;
            }
            else if(strcmp(A[min].nomeAluno,A[j].nomeAluno) == 0){
                if(A[min].RA > A[j].RA){
                    min = j;
                }
            }

        }
            aux = A[i];
            A[i] = A[min];
            A[min] = aux;
    }
}

FILE *arquivoDadosInseridos(tAluno* A,int &n){
    FILE *arqDadosInseridos;

    arqDadosInseridos = fopen("atual.txt","w");
    if(arqDadosInseridos == NULL){
        printf("\nErro ao abrir o arquivo!\n");
    }
    else{
        for(int i=0;i<n;i++){
            fprintf(arqDadosInseridos,"%s %d %.1f %.1f %.1f %.1f \n",A[i].nomeAluno, A[i].RA, A[i].nP1, A[i].nP2, A[i]. nTP,A[i].nPO);            
            }          
        fprintf(arqDadosInseridos,"\nTotal: %d",n);
        }
        printf("\nArquivo criado com sucesso!\n");
        fclose(arqDadosInseridos);
    return arqDadosInseridos;
}