#include "podstawa.h"
#include "interfejs.h"
#include "zamiana.h"

void warunek1(int w)
{
    if (w < 8)
    {
        printf("Minimalne rozmiary planszy to 8x8!\n");
        exit(0);
    }
    if (w % 2 != 0)
    {
        printf("Wymiary planszy muszą być parzyste!\n");
        exit(0);
    }
}

void komunikat1()
{
    printf("-------------------------------");
    printf("\n");
    printf("Podano niewłaściwe współrzędne! \n");
    printf("Wykonaj inny ruch! \n");
    printf("-------------------------------\n\n");
}

void komunikat2()
{
    printf("-------------------------------");
    printf("\n");
    printf("Wybrane pole jest zajęte!\n");
    printf("Wykonaj inny ruch! \n");
    printf("-------------------------------\n\n");
}

void komunikat3()
{
    printf("-------------------------------");
    printf("\n");
    printf("Wykonano niedozwolony ruch!\n");
    printf("Wykonaj inny ruch! \n");
    printf("-------------------------------\n\n");
}

void wypisz(Gra g)
{
    int i, j;
    int a = 1;
    char l = 'a';
    printf("   ");
    for (int k = 0; k < g.wymiar; k++)
    {
        if (k == g.wymiar - 1)
            printf("+ - +");
        else
            printf("+ - ");
    }
    printf("\n");

    for (i = 0; i < g.wymiar; i++)
    {
        for (j = 0; j < g.wymiar; j++)
        {
            if (j == 0)
            {
                if (a < 10)
                    printf("%d. ", a++);
                else
                    printf("%d.", a++);
            }
            if (j == g.wymiar - 1)
            {
                printf("| %c |", g.pole[i * g.wymiar + j]);
            }
            else
                printf("| %c ", g.pole[i * g.wymiar + j]);
        }

        printf("\n");
        printf("   ");

        for (int k = 0; k < g.wymiar; k++)
        {

            if (k == g.wymiar - 1)
            {
                printf("+ - +");
            }
            else
                printf("+ - ");
        }
        printf("\n");
    }

    printf("   ");

    for (int k = 0; k < g.wymiar; k++)
    {
        printf("%3c ", l++);
    }
    printf("\n");
}

void status_gry(Gra g)
{
    printf("Ilość czarnych: %d\n", ile_pionow(g, C));
    printf("Ilość białych: %d\n\n", ile_pionow(g, B));

}

int wypisz_mozliwosci(Gra g)
{
    int k = 0;
    Ruch *lis_ruch = (Ruch *)malloc(sizeof(Ruch));
    lis_ruch = lista_ruchow(g);
    while (lis_ruch)
    {
        printf("(%s) ", lis_ruch->ruch);
        lis_ruch = lis_ruch->nast;
        k++;
    }
    zniszczliste(lis_ruch);
    free(lis_ruch);
    return k;
}

void zakonczenie(Gra g)
{
        if (ocena(g) == -1)
        printf("Wygrał biały!\n");
    else if (ocena(g) == 1)
        printf("Wygrał czarny!\n");
    else
        printf("Remis!\n");
}