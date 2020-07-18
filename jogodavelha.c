#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
//Definição dos jogadores
typedef struct
{
    char nome[20];
    char opcao;
    char vencedor[7];
} Jogador;
Jogador player[2];
int i, j;
//Prototipos
void Menu();
void Inicio();
void analise();
int main()
{
    setlocale(LC_ALL, "Portuguese");
    Menu();
    return (0);
}
//Funções
void Menu()
{
    int opcao = 0;
    char tabuleiro[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    do
    {
        system("cls");
        printf("---------------JOGO DA VELHA---------------\n");
        printf("1 - Começar o jogo!\n0 - Finalizar o jogo.\n");
        fflush(stdin);
        scanf("%d", &opcao);
    } while (opcao != 0 && opcao != 1);
    system("cls");
    switch (opcao)
    {
    case 0:
        printf("Jogo finalizado.\n");
        system("pause");
        exit(-1);
    case 1:
        for (i = 0; i < 2; i++)
        {
            printf("Player %d, digite o seu nome: \n", i + 1);
            fflush(stdin);
            scanf("%s", player[i].nome);
        }
        system("cls");
        player[0].opcao = 'X';
        player[1].opcao = 'O';
        strcpy(player[0].vencedor, "LOSER");
        strcpy(player[1].vencedor, "LOSER");
        printf("%s voce sera representado por X\n\n%s voce sera representado por O\n\n", player[0].nome, player[1].nome);
        system("pause");
        Inicio(tabuleiro);
        break;
    }
    Menu();
}
void Inicio(char matriz[3][3])
{
    system("cls");
    char select;
    int controle[9] = {0, 1, 0, 1, 0, 1, 0, 1, 0};
    int indice = 0;
    do
    {
        printf("Selecione uma coordenada %s: \n", player[controle[indice]].nome);
        for (i = 0; i < 3; i++)
        {
            if (i == 1 || i == 2)
            {
                printf("-----------\n");
            }
            for (j = 0; j < 3; j++)
            {
                if (j < 2)
                {
                    printf(" %c |", matriz[i][j]);
                }
                else
                {
                    printf(" %c  ", matriz[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n%s:", player[controle[indice]].nome);
        fflush(stdin);
        scanf("%c", &select);
        system("cls");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (select == matriz[i][j])
                {
                    matriz[i][j] = player[controle[indice]].opcao;
                }
            }
        }
        analise(matriz);
        indice++;
        if (indice == 9)
        {
            printf("Empate!\n");
            strcpy(player[0].vencedor, "WINNER");
            strcpy(player[1].vencedor, "WINNER");
        }
    } while ((strcmp(player[0].vencedor, "WINNER") != 0) && (strcmp(player[1].vencedor, "WINNER") != 0));
    printf("%s: %s \n%s: %s\n", player[0].nome, player[0].vencedor, player[1].nome, player[1].vencedor);
    system("pause");
}
void analise(char matriz[3][3])
{
    for(i=0;i<=1;i++){

        if (matriz[0][0] == player[i].opcao && 
            matriz[0][1] == player[i].opcao && 
            matriz[0][2] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[1][0] == player[i].opcao && 
            matriz[1][1] == player[i].opcao && 
            matriz[1][2] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[2][0] == player[i].opcao && 
            matriz[2][1] == player[i].opcao && 
            matriz[2][2] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[0][0] == player[i].opcao && 
            matriz[1][1] == player[i].opcao && 
            matriz[2][2] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[2][0] == player[i].opcao && 
            matriz[1][1] == player[i].opcao && 
            matriz[0][2] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[0][1] == player[i].opcao && 
            matriz[1][1] == player[i].opcao && 
            matriz[2][1] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[0][0] == player[i].opcao && 
            matriz[1][0] == player[i].opcao && 
            matriz[2][0] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");

        if (matriz[0][2] == player[i].opcao && 
            matriz[1][2] == player[i].opcao && 
            matriz[2][2] == player[i].opcao)
                strcpy(player[i].vencedor, "WINNER");
	}
}
