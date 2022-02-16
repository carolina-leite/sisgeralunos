#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alunos.h"


// constantes
#define MAX 60

// funcao principal
int main()
{
    int n;
    tAluno A[MAX];
    int tamA = 0;
    char nomeAluno[TAMSTR];
    char nomeAlunoBuscado[TAMSTR];
    int RA;
    double nP1;
    double nP2;
    double nTP;
    double nPO;
    char nomeArquivo[MAX];


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
        }
        else if(n == 3)
        {
            printf("Ler arquivo com listagem de alunos\n");
            printf("Digite o nome do arquivo para realizar a leitura: \n");
            scanf("%s", nomeArquivo);
            abrirArquivo(nomeArquivo, A, tamA);
        }
        else if(n == 4)
        {
            printf("Gerar arquivo com dados dos alunos aprovados, ordenados em ordem alfabetica\n");
            aprovados(A, tamA);

        }
        else if(n == 5)
        {
            printf("Gerar arquivo com dados dos alunos reprovados, ordenados em ordem alfabetica\n");
            reprovados(A, tamA);
        }
    }while(n != 6);
    arquivoDadosInseridos(A, tamA);
        
    return 0;
}