#include <stdio.h>
#include <stdlib.h>

//Protótipos das funções
void preencheV(int *V, int l, int c);
void imprimiV(int *V, int l, int c);
void preencheM(int **M, int l, int c, int *V);
void imprimiM(int **M, int l, int c);


int main()
{
    int l, c;
    //Leitura da quantidade linha e coluna
    printf("Digite quantidade de linhas: ");
    do
    {
        scanf("%d", &l);
    }while(l <= 1);
    printf("Digite quantidade de colunas: ");
    do
    {
        scanf("%d", &c);
    }while(c <= 1);

    //declarando vetor e matriz para a alocação dinamica
    int *V, **M;

    //alocando o vetor e matriz
    V = (int*)malloc((l * c) * sizeof(int));
    M = (int**)malloc(l * sizeof(int));
    for(int i = 0; i < c; i++)
    {
        M[i] = (int*)malloc(c * sizeof(int));
    }
    //chamando as funções
    preencheV(V, l, c);
    imprimiV(V, l, c);
    preencheM(M, l, c, V);
    imprimiM(M, l, c);
    free(V);
    free(M);
    return 0;
}

//Preenchendo o vetor
void preencheV(int *V, int l, int c)
{
    printf("Digite valores para o vetor: \n");
    for(int i = 0; i < l * c; i++)
    {
        scanf("%d", &V[i]);
    }
}

//Imprimindo o vetor
void imprimiV(int *V, int l, int c)
{
    printf("Vetor: ");
    for(int i = 0; i < l * c; i++)
    {
        printf("[%d] ", V[i]);
    }
    printf("\n\n");
}

//Preenchendo a matriz com os mesmo valores do vetor
void preencheM(int **M, int l, int c, int *V)
{
    int cont = 0;
    printf("Matriz: \n");
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            M[i][j] = V[cont];
            cont++;
        }
    }
}

//Imprimindo a matriz
void imprimiM(int **M, int l, int c)
{
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("[%d]", M[i][j]);
        }
        printf("\n");
    }
}
