#include <stdio.h>
#include <conio.h>

int main()
{
    int linhas=20, colunas=46, i, j, player_x=2, player_y=7, pltfrm_y;
    char tela[linhas][colunas], bckgrnd=' ', jato='*', fog_meio=219, fog_esq=218, fog_dir=191, move=33, start, restart, esc;

    // definindo tela

    // - moldura
    for (i=0; i<linhas; i++)
    {
        for (j=0; j<colunas; j++)
        {
            if ((i == 0)||(i == linhas-1))
            {
                tela[i][j] = 205;
            }
            else
            {
                if ((j == 0)||(j == colunas-1))
                {
                    tela[i][j] = 186;
                }
                else
                {
                    tela[i][j] = bckgrnd;
                }
            }
        }
    }
    tela[0][0] = 201;
    tela[0][colunas-1] = 187;
    tela[linhas-1][0] = 200;
    tela[linhas-1][colunas-1] = 188;

    // imprimir tela
    printf("\n  ESC to exit\n");
    tela[9][16] = 'E';
    tela[9][17] = 'N';
    tela[9][18] = 'T';
    tela[9][19] = 'E';
    tela[9][20] = 'R';
    tela[9][21] = ' ';
    tela[9][22] = 't';
    tela[9][23] = 'o';
    tela[9][24] = ' ';
    tela[9][25] = 's';
    tela[9][26] = 't';
    tela[9][27] = 'a';
    tela[9][28] = 'r';
    tela[9][29] = 't';

    tela[12][18] = 'W';
    tela[13][16] = 'A';
    tela[13][17] = ' ';
    tela[13][18] = 'S';
    tela[13][19] = ' ';
    tela[13][20] = 'D';
    tela[13][21] = ' ';
    tela[13][22] = ' ';
    tela[13][23] = 't';
    tela[13][24] = 'o';
    tela[13][25] = ' ';
    tela[13][26] = 'm';
    tela[13][27] = 'o';
    tela[13][28] = 'v';
    tela[13][29] = 'e';

    for (i=0; i<linhas; i++)
    {
        for (j=0; j<colunas; j++)
        {
            if (j == 0)
            {
                printf("  %c", tela[i][j]);
            }
            else
            {
                printf("%c", tela[i][j]);
            }

            if ((j+1)%colunas == 0)
            {
                printf("\n");
            }
        }
    }

    // esperar o start
    while ((start = getch()) != -1)
    {
        if (start == 27)
        {
            return 0;
        }
        else if (start == 13)
        {
            break;
        }
    }

    // - chao
    for (i=linhas-4; i<=linhas-2; i++)
    {
        for (j=1; j<=colunas-2; j++)
        {
            tela[i][j] = 177;
        }
    }
    // - plataforma
    pltfrm_y = colunas-8;
    tela[linhas-4][pltfrm_y-1] = 178;
    tela[linhas-4][pltfrm_y] = 178;
    tela[linhas-4][pltfrm_y+1] = 178;
    // - foguete
    tela[player_x-1][player_y] = fog_meio;
    tela[player_x][player_y] = fog_meio;
    tela[player_x][player_y-1] = fog_esq;
    tela[player_x][player_y+1] = fog_dir;


    // limpar mensagem de start
    for (i=3; i<linhas-3; i++)
    {
        for (j=3; j<colunas-3; j++)
        {
            tela[i][j] = bckgrnd;
        }
    }







    // jogo - movimentos
    while (move != 27)
    {
        // limpar tela
        system("cls");

        if (player_x != linhas-5)
        {
            tela[player_x+1][player_y] = bckgrnd;
        }


        if (kbhit())   //  se clicar, sobe
        {
            move = getch();

            if ((move == 'w')&&(player_x == 2))
            {
                tela[player_x+1][player_y] = jato;
            }
            else if ((move == 'w')&&(player_x != 2))
            {
                tela[player_x-1][player_y] = bckgrnd;
                tela[player_x][player_y] = bckgrnd;
                tela[player_x][player_y-1] = bckgrnd;
                tela[player_x][player_y+1] = bckgrnd;
                player_x = player_x - 1;
                tela[player_x-1][player_y] = fog_meio;
                tela[player_x][player_y] = fog_meio;
                tela[player_x][player_y-1] = fog_esq;
                tela[player_x][player_y+1] = fog_dir;
                tela[player_x+1][player_y] = '*';
            }
            else if ((move == 'a')&&(player_y != 2)&&(player_x != linhas-5))
            {
                tela[player_x-1][player_y] = bckgrnd;
                tela[player_x][player_y] = bckgrnd;
                tela[player_x][player_y-1] = bckgrnd;
                tela[player_x][player_y+1] = bckgrnd;
                player_y = player_y - 1;
                player_x = player_x + 1;
                tela[player_x-1][player_y] = fog_meio;
                tela[player_x][player_y] = fog_meio;
                tela[player_x][player_y-1] = fog_esq;
                tela[player_x][player_y+1] = fog_dir;
                tela[player_x+1][player_y] = jato;
            }
            else if ((move == 'a')&&(player_y == 2)&&(player_x != linhas-5))
            {
                tela[player_x+1][player_y] = jato;
            }
            else if ((move == 'd')&&(player_y != colunas-3)&&(player_x != linhas-5))
            {
                tela[player_x-1][player_y] = bckgrnd;
                tela[player_x][player_y] = bckgrnd;
                tela[player_x][player_y-1] = bckgrnd;
                tela[player_x][player_y+1] = bckgrnd;
                player_y = player_y + 1;
                player_x = player_x + 1;
                tela[player_x-1][player_y] = fog_meio;
                tela[player_x][player_y] = fog_meio;
                tela[player_x][player_y-1] = fog_esq;
                tela[player_x][player_y+1] = fog_dir;
                tela[player_x+1][player_y] = jato;
            }
            else if ((move == 'd')&&(player_y == colunas-3)&&(player_x != linhas-5))
            {
                tela[player_x+1][player_y] = jato;
            }
        }
        else    // se nao clicar, cai
        {
            if (player_x <= linhas-6)
            {
                tela[player_x-1][player_y] = bckgrnd;
                tela[player_x][player_y] = bckgrnd;
                tela[player_x][player_y-1] = bckgrnd;
                tela[player_x][player_y+1] = bckgrnd;
                player_x = player_x + 1;
                tela[player_x-1][player_y] = fog_meio;
                tela[player_x][player_y] = fog_meio;
                tela[player_x][player_y-1] = fog_esq;
                tela[player_x][player_y+1] = fog_dir;
            }

            if (player_x == linhas-5)
            {
                if ((player_y == colunas-7)||(player_y == colunas-6)||(player_y == colunas-5))
                {
                    tela[player_x+1][player_y] = 178;
                }
                else
                {
                    tela[player_x+1][player_y] = 177;
                }
            }
            else
            {
                tela[player_x+1][player_y] = bckgrnd;
            }

        }


        // casos de final de jogo
        if (player_x != linhas-5)
        {
            // - chao
            for (i=linhas-4; i<=linhas-2; i++)
            {
                for (j=1; j<=colunas-2; j++)
                {
                    tela[i][j] = 177;
                }
            }
            // - plataforma
            tela[linhas-4][pltfrm_y-1] = 178;
            tela[linhas-4][pltfrm_y] = 178;
            tela[linhas-4][pltfrm_y+1] = 178;
            // imprimir tela
            printf("\n  ESC to exit\n");
            for (i=0; i<linhas; i++)
            {
                for (j=0; j<colunas; j++)
                {
                    if (j == 0)
                    {
                        printf("  %c", tela[i][j]);
                    }
                    else
                    {
                        printf("%c", tela[i][j]);
                    }

                    if ((j+1)%colunas == 0)
                    {
                        printf("\n");
                    }
                }
            }
        }
        else if ((player_x == linhas-5)&&(player_y != pltfrm_y))
        {
            // mensagem de restart
            tela[9][15] = 'E';
            tela[9][16] = 'N';
            tela[9][17] = 'T';
            tela[9][18] = 'E';
            tela[9][19] = 'R';
            tela[9][20] = ' ';
            tela[9][21] = 't';
            tela[9][22] = 'o';
            tela[9][23] = ' ';
            tela[9][24] = 'r';
            tela[9][25] = 'e';
            tela[9][26] = 's';
            tela[9][27] = 't';
            tela[9][28] = 'a';
            tela[9][29] = 'r';
            tela[9][30] = 't';
            // - chao
            for (i=linhas-4; i<=linhas-2; i++)
            {
                for (j=1; j<=colunas-2; j++)
                {
                    tela[i][j] = 177;
                }
            }
            // - plataforma
            tela[linhas-4][pltfrm_y-1] = 178;
            tela[linhas-4][pltfrm_y] = 178;
            tela[linhas-4][pltfrm_y+1] = 178;
            // imprimir tela
            printf("\n  ESC to exit\n");
            for (i=0; i<linhas; i++)
            {
                for (j=0; j<colunas; j++)
                {
                    if (j == 0)
                    {
                        printf("  %c", tela[i][j]);
                    }
                    else
                    {
                        printf("%c", tela[i][j]);
                    }

                    if ((j+1)%colunas == 0)
                    {
                        printf("\n");
                    }
                }
            }

            // esperar o restart
            while ((restart = getch()) != -1)
            {
                if (restart == 27)
                {
                    return 0;
                }
                else if (restart == 13)
                {
                    // apagar foguete
                    tela[player_x-1][player_y] = bckgrnd;
                    tela[player_x][player_y] = bckgrnd;
                    tela[player_x][player_y-1] = bckgrnd;
                    tela[player_x][player_y+1] = bckgrnd;

                    //reiniciar foguete
                    player_x=2;
                    player_y=7;

                    //limpar mensagem de restart
                    for (i=15; i<31; i++)
                    {
                        tela[9][i] = bckgrnd;
                    }
                    break;
                }
            }
        }
        else if ((player_x == linhas-5)&&(player_y == pltfrm_y))
        {
            // mensagem de game over
            tela[9][21] = 'G';
            tela[9][22] = 'A';
            tela[9][23] = 'M';
            tela[9][24] = 'E';
            tela[10][21] = 'O';
            tela[10][22] = 'V';
            tela[10][23] = 'E';
            tela[10][24] = 'R';

            // - chao
            for (i=linhas-4; i<=linhas-2; i++)
            {
                for (j=1; j<=colunas-2; j++)
                {
                    tela[i][j] = 177;
                }
            }
            // - plataforma
            tela[linhas-4][pltfrm_y-1] = 178;
            tela[linhas-4][pltfrm_y] = 178;
            tela[linhas-4][pltfrm_y+1] = 178;
            // imprimir tela
            printf("\n  ESC to exit\n");
            for (i=0; i<linhas; i++)
            {
                for (j=0; j<colunas; j++)
                {
                    if (j == 0)
                    {
                        printf("  %c", tela[i][j]);
                    }
                    else
                    {
                        printf("%c", tela[i][j]);
                    }

                    if ((j+1)%colunas == 0)
                    {
                        printf("\n");
                    }
                }
            }

            // esperar o esc
            while ((esc = getch()) != -1)
            {
                if (esc == 27)
                {
                    return 0;
                }
            }
        }

    }





    return 0;
}

