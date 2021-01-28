#include "podstawa.h"
#include "zamiana.h"

int ifzamiana_gora(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    //if (g.pole[(x - 1) * g.wymiar + y] == kolor_przeciwny)
    if (g.pole[(x - 1) * g.wymiar + y] == kolor_przeciwny && (x-1) * g.wymiar + y > 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x - i - 2) * g.wymiar + y] == ' ')
                return 0;

            if (g.pole[(x - i - 2) * g.wymiar + y] == g.kolor)
            {
                return 1;
            }
        }
    }
    return 0;
}

int ifzamiana_dol(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x + 1) * g.wymiar + y] == kolor_przeciwny)
    {
        for (i = 0; i < g.wymiar; i++)
        {

            if (g.pole[(x + i + 2) * g.wymiar + y] == ' ')
                return 0;

            if (g.pole[(x + i + 2) * g.wymiar + y] == g.kolor)
            {
                return 1;
            }
        }
    }
    return 0;
}

int ifzamiana_prawo(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x)*g.wymiar + y + 1] == kolor_przeciwny && (x * g.wymiar + y + 1 - (g.wymiar - 1)) % g.wymiar != 0 && (x * g.wymiar + y - (g.wymiar - 1)) % g.wymiar != 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x)*g.wymiar + y + i + 2] == ' ')
                return 0;
            if ((x * g.wymiar + y + i + 2) % g.wymiar == 0)
                return 0;

            if (g.pole[(x)*g.wymiar + y + i + 2] == g.kolor)
                return 1;
        }
    }
    return 0;
}

int ifzamiana_lewo(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x)*g.wymiar + y - 1] == kolor_przeciwny && (x * g.wymiar + y - 1) % g.wymiar != 0 && (x * g.wymiar + y) % g.wymiar != 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x)*g.wymiar + y - i - 2] == ' ')
                return 0;

            if (g.pole[(x)*g.wymiar + y - i - 2] == g.kolor)
                return 1;
        }
    }
    return 0;
}

int ifzamiana_skosGL(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x - 1) * g.wymiar + y - 1] == kolor_przeciwny && ((x - 1) * g.wymiar + y - 1) % g.wymiar != 0 && (x * g.wymiar + y) % g.wymiar != 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x - i - 2) * g.wymiar + y - i - 2] == ' ')
                return 0;

            if (g.pole[(x - i - 2) * g.wymiar + y - i - 2] != g.kolor)
            {
                if (((x - i - 2) * g.wymiar + y - i - 2) % g.wymiar == 0)
                    return 0;
            }
            else
                return 1;
        }
    }
    return 0;
}

int ifzamiana_skosGP(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x - 1) * g.wymiar + y + 1] == kolor_przeciwny && (((x - 1) * g.wymiar + y + 1) - (g.wymiar - 1)) % g.wymiar != 0 && ((x * g.wymiar + y) - (g.wymiar - 1)) % g.wymiar != 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x - i - 2) * g.wymiar + y + i + 2] == ' ')
                return 0;

            if (g.pole[(x - i - 2) * g.wymiar + y + i + 2] != g.kolor)
            {
                if ((((x - i - 2) * g.wymiar + y + i + 2) - (g.wymiar - 1)) % g.wymiar == 0)
                    return 0;
            }
            else
                return 1;
        }
    }
    return 0;
}

int ifzamiana_skosDL(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x + 1) * g.wymiar + y - 1] == kolor_przeciwny && ((x + 1) * g.wymiar + y - 1) % g.wymiar != 0 && (x * g.wymiar + y) % g.wymiar != 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x + i + 2) * g.wymiar + y - i - 2] == ' ')
                return 0;

            if (g.pole[(x + i + 2) * g.wymiar + y - i - 2] != g.kolor)
            {
                if (((x + i + 2) * g.wymiar + y - i - 2) % g.wymiar == 0)
                    return 0;
            }
            else
                return 1;
        }
    }
    return 0;
}

int ifzamiana_skosDP(Gra g, int x, int y)
{
    int i;
    char kolor_przeciwny;

    if (g.kolor == B)
        kolor_przeciwny = C;
    else if (g.kolor == C)
        kolor_przeciwny = B;

    if (g.pole[(x + 1) * g.wymiar + y + 1] == kolor_przeciwny && (((x + 1) * g.wymiar + y + 1) - (g.wymiar - 1)) % g.wymiar != 0 && ((x * g.wymiar + y) - (g.wymiar - 1)) % g.wymiar != 0)
    {
        for (i = 0; i < g.wymiar; i++)
        {
            if (g.pole[(x + i + 2) * g.wymiar + y + i + 2] == ' ')
                return 0;

            if (g.pole[(x + i + 2) * g.wymiar + y + i + 2] != g.kolor)
            {
                if ((((x + i + 2) * g.wymiar + y + i + 2) - (g.wymiar - 1)) % g.wymiar == 0)
                    return 0;
            }
            else
                return 1;
        }
    }
    return 0;
}

Ruch *lista_ruchow(Gra g)
{
    int i, j;
    int k = 0;
    char c[2];
    char a[2];
    Ruch *ost_ruch = NULL;
    Ruch *glowa = NULL;
    for (i = 0; i < g.wymiar; i++)
    {
        for (j = 0; j < g.wymiar; j++)
        {
            if (ifzamiana_dol(g, i, j) == 1 || ifzamiana_gora(g, i, j) == 1 || ifzamiana_prawo(g, i, j) == 1 || ifzamiana_lewo(g, i, j) == 1 ||
                ifzamiana_skosGL(g, i, j) == 1 || ifzamiana_skosGP(g, i, j) == 1 || ifzamiana_skosDL(g, i, j) == 1 || ifzamiana_skosDP(g, i, j) == 1)
            {
                if (g.pole[i * g.wymiar + j] == ' ')
                {
                    Ruch *nowy = (Ruch *)malloc(sizeof(Ruch));
                    nowy->nast = NULL;

                    if (ost_ruch == NULL)
                        glowa = nowy;
                    else
                        ost_ruch->nast = nowy;
                    ost_ruch = nowy;

                    nowy->ruch = (char *)malloc(sizeof(char) * strlen(c) + 1);

                    sprintf(a, "%c", j + 97);
                    sprintf(c, "%d", i + 1);
                    strcat(nowy->ruch, a);
                    strcat(nowy->ruch, c);

                    k++;
                }
            }
        }
    }

    return glowa;
}
