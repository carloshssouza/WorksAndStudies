#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define u 20

typedef struct vida
{
    int pontosmovimento;
    int pontoescudo;

} VIDA;


void bomb (int  bomba[u][u], char letras[10]); //função pra fazer o mapa da bomba, ponto de movimento e escudo
void jogador(int  bomba[u][u], VIDA *personagem, int *p_l, int *p_c, int *verifica);
void campoprint(char m[][u]); //função pra printar o campo original
void Start(VIDA *personagem, char eren, char m[u][u], int  bomba[u][u], char letras[10]); //inicio
void Update(VIDA *personagem, char eren, char m[u][u], int  bomba[u][u]); //função onde vai ter o movimento do personagem e todos acontecimentos
void entrada();


int main()
{
    setlocale(LC_ALL,"Portuguese");
    VIDA personagem;
    char m[u][u], letras[10] = {"BEP       "}; //campo original e as letras pra preencher o mapa da bomba
    int  bomba[u][u]; //mapa bomba

    char eren = '*'; //personagem

    //Menu inicial

    entrada();
    Start(&personagem, eren, m, bomba, letras);

    Update(&personagem, eren, m, bomba);
    return 0;

}

//Tela inicial
void entrada()
{
    char op;
    do{

        int contador = 0;
        printf("\n\n");
        while (contador < 2){

            for (int i = 0; i < 40; i++)
            {
                printf("#");
            }
            printf("\n");
            contador++;
        }
        contador = 0;
        while (contador < 2){
            printf("# ");
            for (int i = 0; i < 37; i++)
            {
                printf(" ");
            }
            printf("#\n");
            contador++;
        }
        contador = 0;
        printf("#  F I E L D    D E S T R U C T I O N  #\n");
        while (contador < 2){
            printf("# ");
            for (int i = 0; i < 37; i++)
            {
                printf(" ");
            }
            printf("#\n");
            contador++;
        }
        contador = 0;
        while (contador < 2){
            for (int i = 0; i < 40; i++)
            {
                printf("#");
            }
            printf("\n");
            contador++;
        }
        printf("\n\n REGRAS: \n\n");
        printf("\n (w) - cima");
        printf("\n (s) - baixo");
        printf("\n (a) - esquerda");
        printf("\n (d) - direita\n");
        printf("\nUse seus pontos de movimento com cuidado para chegar até o X.\n");
        printf("O campos está repleto de bombas. Um aviso sempre aparecera quando você estiver perto de uma!!\n");
        printf("No campo também há lugares com bonus de 3 pontos de movimento e 1 ponto acumulativo de escudo para te proteger da bomba.\n");
        printf("Se pisar na bomba sem escudo, GAME OVER!!\n");
        printf("\n**BOA SORTE E BOM JOGO**\n");

        printf("\n\n C para começar ou S para sair: ");
        do{
            scanf(" %c", &op);
        }while (op != 'S' && op != 'C');
        if (op == 'S')
        {
            exit(0);
        }

    }while (!op == 'C');


    system ("cls");
}





//Iniciando o jogo e variaveis!! Aqui é quando está tudo do 0
void Start(VIDA *personagem, char eren, char m[u][u], int  bomba[u][u], char letras[10])
{
    //Preenchendo o campo com espaço;
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            m[i][j] = ' ';

        }
    }

    m[0][0] = eren;
    m[19][19] = 'X';
    personagem->pontosmovimento = 50;
    personagem->pontoescudo = 0;

    bomb(bomba, letras);
//     for (int i = 0; i < u; i++)
//    {
//        for (int j = 0; j < u; j++)
//        {
//            printf("[%c]", bomba[i][j]);
//        }
//        printf("\n");
//    }





}


//Jogo iniciado, aqui é onde faz o movimento no campo
void Update(VIDA *personagem, char eren, char m[u][u], int  bomba[u][u])
{
    char movimento;
    int l, c; //l = linha e c = coluna
    int verifica;


    l = 0;
    c = 0;


    while (personagem->pontosmovimento > 0)
    {
        verifica = 0;
        do
        {
            printf("Pontos de movimento: %d | Pontos de escudo: %d\n", personagem->pontosmovimento, personagem->pontoescudo);
            printf("Posição: Linha %d | Coluna %d\n\n", l, c);
            campoprint(m);

            scanf(" %c", &movimento);
            system("cls");


        }
        while (!(movimento == 's' || movimento == 'w' || movimento == 'a' || movimento == 'd'));




        switch (movimento)
        {
            case 's':
                m[l][c] = ' ';

                if(l<u-1)
                {
                    l++;
                    personagem->pontosmovimento--;
                    m[l][c] = eren;
                    jogador(bomba, &personagem, &l, &c, &verifica);
                    bomba[l][c] = ' ';

                }
                else {m[l][c] = eren;}

                break;

            case 'w':
                m[l][c] = ' ';
                if(l > 0)
                {
                    l--;
                    personagem->pontosmovimento--;
                    m[l][c] = eren;
                    jogador(bomba, &personagem, &l, &c, &verifica);
                    bomba[l][c] = ' ';


                }
                else {m[l][c] = eren;}

                break;

            case 'a':
                m[l][c] = ' ';
                if (c > 0)
                {
                    c--;
                    personagem->pontosmovimento--;
                    m[l][c] = eren;
                    jogador(bomba, &personagem, &l, &c, &verifica);
                    bomba[l][c] = ' ';

                }
                else {m[l][c] = eren;}

                break;

            case 'd':
                m[l][c] = ' ';
                if (c < u-1)
                {
                    c++;
                    personagem->pontosmovimento--;
                    m[l][c] = eren;
                    jogador(bomba, &personagem, &l, &c, &verifica);
                    bomba[l][c] = ' ';


                }
                else {m[l][c] = eren;}

                break;

        }


        if (verifica == 1 && personagem->pontoescudo > 0)
        {
            personagem->pontoescudo--;
            printf("Pisou na bomba!!! Você perdeu 1 ponto de escudo\n");
        }

        else if(verifica == 1 && personagem->pontoescudo == 0)
        {
            personagem->pontosmovimento = 0;
            printf("BUMMMM!!! Você pisou na bomba!!\n");
            break;
        }
        else if (verifica == 2)
        {
            personagem->pontosmovimento = personagem->pontosmovimento + 3;
            printf("Você ganhou 3 pontos de movimento\n");
        }
        else if (verifica == 3)
        {
            personagem->pontoescudo++;
            printf("Você ganhou 1 ponto de escudo.\n");
        }
        else if (verifica == 4)
        {
            printf("PARABÉNS!! VOCÊ GANHOU!!!");
            exit(0);
        }

    }



        printf("\n--------G A M E  O V E R!!--------\n");
}


void campoprint(char m[][u])
{
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            printf("[%c]", m[i][j]);
        }
        printf("\n");
    }
}

void bomb(int bomba[u][u], char letras[10]) //aqui é o preenchimento da matriz de bomba, com as letras
{
    char n;
    srand(time (NULL));
    for (int i = 0; i < u; i++)
    {
        for (int j = 0; j < u; j++)
        {
            n = rand() % 9;
            bomba[i][j] = letras[n];
        }
    }
    bomba[0][0] = ' ';
    bomba[0][1] = ' ';
    bomba[1][0] = ' ';
    bomba[1][1] = ' ';
    bomba[18][18] = ' ';
    bomba[18][19] = ' ';
    bomba[19][18] = ' ';
    bomba[19][19] = 'X';

}

void jogador(int bomba[u][u], VIDA *personagem, int *p_l, int *p_c, int *verifica)
{

    int ll, cc;
    ll = *p_l;
    cc= *p_c;



            if (bomba[ll][cc] == 'B')
            {
                *verifica = 1;
            }


            if (bomba[ll+1][cc] == 'B' || bomba[ll-1][cc] == 'B' || bomba[ll][cc-1] == 'B' || bomba[ll][cc+1] == 'B')
            {
                printf("VOCÊ ESTÁ PERTO DE UMA BOMBA!!\n");

            }


            else if (bomba[ll][cc] == 'P')
            {
                *verifica = 2;
            }

            else if (bomba[ll][cc] == 'E')
            {
                *verifica = 3;
            }

            else if (bomba[ll][cc] == 'X')
            {
                *verifica = 4;
                printf("VOCÊ GANHOU!!!!");
                exit(0);
            }

}















