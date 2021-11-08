#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"


// constantes
#define MAX 60

// definicao de tipos
/*struct aluno
{
    char nomeAluno[MAX];
    int RA;
    double nP1;
    double nP2;
    double nTP;
    double nPO;

};*/


// funcao principal
int main()
{
    int n;
    tAluno A[MAX];
    int tamA = 0;
    //aluno vetAluno[MAX];
    char nomeAluno[TAMSTR];
    char nomeAlunoBuscado[TAMSTR];
    //int teste;
    int RA;
    double nP1;
    double nP2;
    double nTP;
    double nPO;
    //FILE *arq;
    //FILE *arqAprovados;
    char nomeArquivo[MAX];
    //aluno infAluno[MAX];


    //menu
    printf("*** Bem Vindo ao Sistema de Gerenciamento de Alunos ***\n");
    printf("Menu: \n");
    printf("1. Cadastrar um novo aluno\n");
    printf("2. Buscar aluno\n");
    printf("3. Ler arquivo com listagem de alunos\n");
    printf("4. Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabetica\n");
    printf("5. Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabetica\n");
    printf("6. Fechar programa\n\n");
    
    n = 0;
    do{
        printf("Digite um numero para realizar uma operacao:\n");
        scanf("%d", &n);   
        if(n == 1)
        {
            
            printf("\nCadastrar um novo aluno\n");
            
            printf("Digite o nome do Aluno:\n");
            scanf(" %[^\n]", nomeAluno);
            printf("Digite o RA do Aluno:\n");
            scanf("%d", &RA);
            printf("Digite a nota da P1 do Aluno:\n");
            scanf("%lf", &nP1);
            printf("Digite a nota da P2 do Aluno:\n");
            scanf("%lf", &nP2);
            printf("Digite a nota da TP do Aluno:\n");
            scanf("%lf", &nTP);
            printf("Digite a nota da PO do Aluno:\n");
            scanf("%lf", &nPO);

            cadastroAluno(A, tamA, nomeAluno, RA, nP1, nP2, nTP, nPO);
            
            
        }
        else if(n == 2)
        {
            printf("Buscar aluno\n");
            printf("Digite o nome do aluno a ser buscado:\n");
            scanf(" %[^\n]", nomeAlunoBuscado);
            buscarAluno(A, nomeAlunoBuscado, tamA);

        //imprimirAluno(A, tamA);
        }
        else if(n == 3)
        {
            printf("Ler arquivo com listagem de alunos\n");
            printf("Digite o nome do arquivo para realizar a leitura: \n");
            scanf("%s", nomeArquivo);

            //arq = fopen(nomeArquivo, "r");
            /*if(arq == NULL)
            {
                printf("Erro ao abrir o arquivo\n");
            }
            else
            {f %lf %lf %lf", nomeAluno, &RA, &nP1, &nP2, &nTP, &nPO);
                    //cadastroAluno(A, tamA, nomeAluno, RA, nP1, nP2, nTP, nPO);
                //}
                //fclose(arq);
            }*/
            
            abrirArquivo(nomeArquivo, A, tamA);
        }
        else if(n == 4)
        {
            printf("Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabetica\n");
            aprovados(A, tamA);

        }
        else if(n == 5)
        {
            printf("Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabética\n");
            reprovados(A, tamA);
        }
    }while(n != 6);
    arquivoDadosInseridos(A, tamA);

    /*node = head;
    while (node != NULL)
    {
        head = node->prox;
        free(node);
        node = head;
    }*/
        
    return 0;
}
/*
void cadastroAluno(TAluno **head)
{
    TAluno *nodeA, *newnode;
    char buffer[MAX];
    char nomeAluno[MAX];
    int RA;
    double nP1;
    double nP2;
    double nTP;
    double nPO;

    printf("Digite o nome do Aluno:\n");
    gets(buffer);
    newnode->nomeAluno = (char *) malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(newnode->nomeAluno, buffer);
    scanf(" %[^\n]", nomeAluno);
    printf("Digite o RA do Aluno:\n");
    scanf("%d", &RA);
    printf("Digite a nota da P1 do Aluno:\n");
    scanf("%lf", &nP1);
    printf("Digite a nota da P2 do Aluno:\n");
    scanf("%lf", &nP2);
    printf("Digite a nota da TP do Aluno:\n");
    scanf("%lf", &nTP);
    printf("Digite a nota da PO do Aluno:\n");
    scanf("%lf", &nPO);
    
    else {
        nodeA = *head;
        while(nodeA->prox != NULL)
        {
            nodeA = nodeA->prox;
        }
        newnode = (TAluno *)malloc(sizeof(TAluno)); //Alocando memoria para um novo nó
        newnode->nomeAluno = nomeAluno;
        newnode->RA = RA;
        newnode->nP1 = nP1;
        newnode->nP2 = nP2;
        newnode->nTP = nTP;
        newnode->nPO = nPO;
        newnode->prox = NULL;
        nodeA->prox = newnode;
    }


}

void imprimeAluno(TAluno *node)
{
    int i = 0;

    while (node != NULL)
    {
        i++;
        printf("\nAluno %d\n", i);
        printf("Nome: %s\n", node->nomeAluno);
        printf("RA: %d\n", node->RA);
        printf("P1: %lf\n", node->nP1);
        printf("P2: %lf\n", node->nP2);
        printf("TP: %lf\n", node->nTP);
        printf("PO: %lf\n", node->nPO);
        node = node->prox;
    }
    
}*/
