#include "podstawa.h"
#include "zamiana.h"

Gra *zamiana_gora(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x - 1) * g->wymiar + y] == kolor_przeciwny && (x-1) * g->wymiar + y > 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x - i - 2) * g->wymiar + y] != ' ')
                ;
            else
                return g;

            if (g->pole[(x - i - 2) * g->wymiar + y] == g->kolor)
            {
                while ((x - i - 1 - j) * g->wymiar + y != x * g->wymiar + y)
                {
                    g->pole[(x - i - 1 - j) * g->wymiar + y] = g->kolor;
                    j--;
                }
                return g;
            }
        }
    }
    return g;
}

Gra *zamiana_dol(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;
    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x + 1) * g->wymiar + y] == kolor_przeciwny)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x + i + 2) * g->wymiar + y] != ' ')
                ;
            else
                return g;

            if (g->pole[(x + i + 2) * g->wymiar + y] == g->kolor)
            {
                while ((x + i + 1 + j) * g->wymiar + y != x * g->wymiar + y)
                {
                    g->pole[(x + i + 1 + j) * g->wymiar + y] = g->kolor;
                    j--;
                }
                return g;
            }
        }
    }
    return g;
}

Gra *zamiana_prawo(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x)*g->wymiar + y + 1] == kolor_przeciwny && (x * g->wymiar + y + 1 - (g->wymiar - 1)) % g->wymiar != 0 && (x * g->wymiar + y - (g->wymiar - 1)) % g->wymiar != 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x)*g->wymiar + y + i + 2] != ' ')
                return g;

            if (g->pole[(x)*g->wymiar + y + i + 2] == g->kolor)
            {
                while ((x)*g->wymiar + y + i + 1 + j != x * g->wymiar + y)
                {
                    g->pole[(x)*g->wymiar + y + i + 1 + j] = g->kolor;
                    j--;
                }
                return g;
            }
        }
    }
    return g;
}

Gra *zamiana_lewo(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x)*g->wymiar + y - 1] == kolor_przeciwny && (x * g->wymiar + y - 1) % g->wymiar != 0 && (x * g->wymiar + y) % g->wymiar != 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x)*g->wymiar + y - i - 2] != ' ')
                ;
            else
                return g;

            if (g->pole[(x)*g->wymiar + y - i - 2] == g->kolor)
            {
                while ((x)*g->wymiar + y - i - 1 - j != x * g->wymiar + y)
                {
                    g->pole[(x)*g->wymiar + y - i - 1 - j] = g->kolor;
                    j--;
                }
                return g;
            }
        }
    }
    return g;
}

Gra *zamiana_skosGL(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x - 1) * g->wymiar + y - 1] == kolor_przeciwny && ((x - 1) * g->wymiar + y - 1) % g->wymiar != 0 && (x * g->wymiar + y) % g->wymiar != 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x - i - 2) * g->wymiar + y - i - 2] != ' ')
                ;
            else
                return g;

            if (g->pole[(x - i - 2) * g->wymiar + y - i - 2] != g->kolor)
            {
                if (((x - i - 2) * g->wymiar + y - i - 2) % g->wymiar == 0)
                    return g;
            }
            else
                while ((x - i - 1 - j) * g->wymiar + y - i - 1 - j != x * g->wymiar + y)
                {
                    g->pole[(x - i - 1 - j) * g->wymiar + y - i - 1 - j] = g->kolor;
                    j--;
                }
        }
    }
    return g;
}

Gra *zamiana_skosGP(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x - 1) * g->wymiar + y + 1] == kolor_przeciwny && (((x - 1) * g->wymiar + y + 1) - (g->wymiar - 1)) % g->wymiar != 0 && ((x * g->wymiar + y) - (g->wymiar - 1)) % g->wymiar != 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x - i - 2) * g->wymiar + y + i + 2] != ' ')
                ;
            else
                return g;

            if (g->pole[(x - i - 2) * g->wymiar + y + i + 2] != g->kolor)
            {
                if ((((x - i - 2) * g->wymiar + y + i + 2) - (g->wymiar - 1)) % g->wymiar == 0)
                    return g;
            }
            else
                while ((x - i - 1 - j) * g->wymiar + y + i + 1 + j != x * g->wymiar + y)
                {
                    g->pole[(x - i - 1 - j) * g->wymiar + y + i + 1 + j] = g->kolor;
                    j--;
                }
        }
    }
    return g;
}

Gra *zamiana_skosDL(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x + 1) * g->wymiar + y - 1] == kolor_przeciwny && ((x + 1) * g->wymiar + y - 1) % g->wymiar != 0 && (x * g->wymiar + y) % g->wymiar != 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x + i + 2) * g->wymiar + y - i - 2] != ' ')
                ;
            else
                return g;

            if (g->pole[(x + i + 2) * g->wymiar + y - i - 2] != g->kolor)
            {
                if (((x + i + 2) * g->wymiar + y - i - 2) % g->wymiar == 0)
                    return g;
            }
            else
                while ((x + i + 1 + j) * g->wymiar + y - i - 1 - j != x * g->wymiar + y)
                {
                    g->pole[(x + i + 1 + j) * g->wymiar + y - i - 1 - j] = g->kolor;
                    j--;
                }
        }
    }
    return g;
}

Gra *zamiana_skosDP(Gra *g, int x, int y)
{
    int i;
    int j = 0;
    char kolor_przeciwny;

    if (g->kolor == B)
        kolor_przeciwny = C;
    else if (g->kolor == C)
        kolor_przeciwny = B;

    if (g->pole[(x + 1) * g->wymiar + y + 1] == kolor_przeciwny && (((x + 1) * g->wymiar + y + 1) - (g->wymiar - 1)) % g->wymiar != 0 && ((x * g->wymiar + y) - (g->wymiar - 1)) % g->wymiar != 0)
    {
        for (i = 0; i < g->wymiar; i++)
        {
            if (g->pole[(x + i + 2) * g->wymiar + y + i + 2] != ' ')
                ;
            else
                return g;

            if (g->pole[(x + i + 2) * g->wymiar + y + i + 2] != g->kolor)
            {
                if ((((x + i + 2) * g->wymiar + y + i + 2) - (g->wymiar - 1)) % g->wymiar == 0)
                    return g;
            }
            else
                while ((x + i + 1 + j) * g->wymiar + y + i + 1 + j != x * g->wymiar + y)
                {
                    g->pole[(x + i + 1 + j) * g->wymiar + y + i + 1 + j] = g->kolor;
                    j--;
                }
        }
    }
    return g;
}

Gra *zamiany(Gra *g, int x, int y)
{
    zamiana_dol(g, x - 1, y - 1);
    zamiana_gora(g, x - 1, y - 1);
    zamiana_lewo(g, x - 1, y - 1);
    zamiana_prawo(g, x - 1, y - 1);
    zamiana_skosGL(g, x - 1, y - 1);
    zamiana_skosGP(g, x - 1, y - 1);
    zamiana_skosDL(g, x - 1, y - 1);
    zamiana_skosDP(g, x - 1, y - 1);

    return g;
}

 /*void zniszczliste(Ruch *glowa)
 {
     Ruch *current = glowa;
     Ruch *next;

    while (current != NULL)
    {
         next = current->nast;
         free(current);
         current = next;
     }

     glowa = NULL;
}*/

void zniszczliste(Ruch* glowa)
{
   Ruch* tmp;

   while (glowa != NULL)
    {
       tmp = glowa;
       glowa = glowa->nast;
       free(tmp);
    }
}