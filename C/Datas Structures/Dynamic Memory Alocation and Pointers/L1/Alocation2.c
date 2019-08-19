#include <stdio.h>
#include <stdlib.h>

//Criando o Struct
typedef struct aluno
{
    int matricula;
    char nome[50];
    int dia_nasc;
    int mes_nasc;
    int ano_nasc;
    float nota;

}ALUNO;

//Protótipos das funções usadas no programa
ALUNO *aloca(int n);
void preencheV(ALUNO *V, int n);
void imprimiV(ALUNO *V, int n);

int main()
{
    int n;
    ALUNO *V;
    printf("Digite quantidade de alunos: ");
    do
    {
        scanf("%d", &n);
    }while(n <= 0);
    V = aloca(n);
    preencheV(V, n);
    imprimiV(V, n);
    free(V);
    return 0;
}

//Alocação de memória para o vetor do tipo aluno com o tamanho digitado pelo o usuário (n)
ALUNO *aloca(int n)
{
    ALUNO *V;
    V = (ALUNO*) malloc(n * sizeof(ALUNO));

    if(V == NULL){
        printf("Memória insuficiente!");
    }

    return V;
}

//Preenchendo o vetor que é do tipo Aluno(Struct), ou seja, preenchendo os dados.
void preencheV(ALUNO *V, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("----ALUNO [%d]----\n\n", i+1);

        printf("Matricula: ");
        do{
            scanf("%d", &V[i].matricula);
        }while(V[i].matricula < 0);
        fflush(stdin);

        printf("Nome: ");
        fgets(V[i].nome, 50, stdin);

        printf("Dia do nascimento: ");
        do{
            scanf("%d", &V[i].dia_nasc);
        }while(V[i].dia_nasc < 0 || V[i].dia_nasc > 31);

        printf("Mes do nascimento: ");
        do{
            scanf("%d", &V[i].mes_nasc );
        }while(V[i].mes_nasc < 0 || V[i].mes_nasc > 12);

        printf("Ano do nascimento: ");
        do{
            scanf("%d", &V[i].ano_nasc);
        }while(V[i].ano_nasc < 0);

        printf("Nota: ");
        do{
            scanf("%f", &V[i].nota);
        }while(V[i].nota < 0 || V[i].nota > 10);
        printf("\n");
    }
}

//Imprimindo os dados dos alunos aprovados
//Para os reprovados, só aparecerá uma mensagem.
//Fiz a mensagem de reprovado em outro for, para não aparecer entre os aprovados.
void imprimiV(ALUNO *V, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(V[i].nota >= 6){
            printf("\n--APROVADOS--\n\n");
            printf("Matricula: %d\n", V[i].matricula);
            printf("Nome: %s", V[i].nome);
            printf("Data de nascimento: %d/%d/%d\n", V[i].dia_nasc, V[i].mes_nasc, V[i].ano_nasc);
            printf("Nota: %.2f\n\n", V[i].nota);
        }

    }
    for(int i = 0; i < n; i++)
    {
        if(V[i].nota < 6)
        {
            printf("Os demais alunos estão REPROVADOS!!!\n");
        }
    }
}
