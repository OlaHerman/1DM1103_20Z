#include "podstawa.h"
#include "interfejs.h"
#include "zamiana.h"

int warunek2(Gra g, int x, int y)
{
    if (x < 1 || y < 1 || x > g.wymiar || y > g.wymiar)
    {
        komunikat1();
        return 1;
    }

    else if (g.pole[(x - 1) * g.wymiar + (y - 1)] == B || (g.pole[(x - 1) * g.wymiar + (y - 1)] == C))
    {
        komunikat2();
        return 2;
    }

    return 0;
}

int warunek3(Gra *g, char a, int x)
{
    Ruch *lis_ruch = (Ruch *)malloc(sizeof(Ruch));
    char wspol[3];
    char c[2];
    char d[2];

    lis_ruch = lista_ruchow(*g);

    sprintf(c, "%d", x);
    sprintf(d, "%c", a);
    strcat(wspol, d);
    strcat(wspol, c);
    while (lis_ruch)
    {
        if (strcmp(lis_ruch->ruch, wspol) == 0)
        {
            return 0;
        }
        else
            lis_ruch = lis_ruch->nast;
    }

    komunikat3();
    return 1;
}

Gra *stworz(Gra *g, int w)
{
    int i, j;
    g->wymiar = w;
    g->pole = (char *)malloc(sizeof(char) * (g->wymiar) * (g->wymiar));
    for (i = 0; i < g->wymiar; i++)
    {
        for (j = 0; j < g->wymiar; j++)
        {
            g->pole[(g->wymiar / 2) * g->wymiar + (g->wymiar / 2)] = B;
            g->pole[(g->wymiar / 2 - 1) * g->wymiar + (g->wymiar / 2 - 1)] = B;
            g->pole[(g->wymiar / 2 - 1) * g->wymiar + (g->wymiar / 2)] = C;
            g->pole[(g->wymiar / 2) * g->wymiar + (g->wymiar / 2 - 1)] = C;
            g->pole[i * g->wymiar + j] = ' ';
        }
    }

    return g;
}

int ile_pionow(Gra g, char kolor)
{
    int ilosc = 0;

    int i, j;
    for (i = 0; i < g.wymiar; i++)
        for (j = 0; j < g.wymiar; j++)
        {
            if (g.pole[i * g.wymiar + j] == kolor)
                ilosc++;
        }
    return ilosc;
}

int przewaga(Gra g)
{
    return ile_pionow(g, C) - ile_pionow(g, B);
}

int ocena(Gra g)
{
    if (przewaga(g) < 0)
        return -1;
    else if (przewaga(g) > 0)
        return 1;
    else
        return 0;
}

Gra ruch(Gra g, int x, int y)
{
    int i, j;

    for (i = 0; i < g.wymiar; i++)
        for (j = 0; j < g.wymiar; j++)
        {
            if (i == x - 1 && j == y - 1)
                g.pole[(x - 1) * g.wymiar + (y - 1)] = g.kolor;
        }
    zamiany(&g, x, y);
    return g;
}

int negmax(Gra *g, int glebokosc, int alfa, int beta)
{
   printf("działam\n");
   
    if (!glebokosc)
        return ocena(*g);
    int nowaocena;
    int ocenawezla = -1; //(-PRZEGRANA)
    int i = 0;

    for (Ruch *lr = lista_ruchow(*g), *ptr = lr; lr; i++, lr = lr->nast, free(ptr), ptr = lr)
    {
        //printf("x: %c, y: %c", ptr->ruch[0], ptr->ruch[1]);
        printf("działam \n");
        Gra dziecko = ruch(*g, ptr->ruch[0], ptr->ruch[1]); //plansza po ruchu to dziecko
        wypisz(dziecko);
        nowaocena = -negmax(&dziecko, glebokosc - 1, -beta, -alfa);
        
        if (nowaocena > ocenawezla)
            ocenawezla = nowaocena;
        if (ocenawezla > alfa)
            alfa = ocenawezla;
        //printf("alfa:%d\n\n", alfa);
        if (alfa > beta)
        {
            //printf("BRAKE___________\n");
            // zwolninenie listy ruchów do końca
            break;
        }
    }
    return ocenawezla;
}

int ruch_kolor(Gra *g, char a, int x)
{
    int y = a - 96;

    if (warunek2(*g, x, y) != 0 /*|| warunek3(g, a, x) != 0*/)
    {
        return 1;
    }
    else
    {
        //negmax(g, 2, 32, -32);
        ruch(*g, x, y);
        wypisz(*g);

    }
    return 0;
}

Gra *ruchy(Gra *g)
{
    int kolej;
    char a;
    int x;
    for (kolej = 0; kolej < (g->wymiar * g->wymiar) - 4; kolej++)
    {
        if (kolej % 2 != 0)
        {
            g->kolor = B;
            printf("Ruch białego \n");
            printf("Możliwe ruchy: ");
            if (wypisz_mozliwosci(*g) == 0)
            {
                printf("brak\n");
                zakonczenie(*g);
                exit(0);
            }

            printf("\n");
            printf("Podaj współrzędne ruchu: ");
            printf("\n");
            scanf(" %c %d", &a, &x);
            printf("\n");

            if (ruch_kolor(g, a, x) != 0)
                kolej--;
        }
        else
        {
            g->kolor = C;
            printf("Ruch czarnego \n");
            printf("Możliwe ruchy: ");
            if (wypisz_mozliwosci(*g) == 0)
            {
                printf("brak\n");
                zakonczenie(*g);
                return 0;
            }
            printf("\n");
            printf("Podaj współrzędne ruchu: ");
            scanf(" %c %d", &a, &x);
            printf("\n");

            if (ruch_kolor(g, a, x) != 0)
                kolej--;
            
        }
    }
    return g;
}