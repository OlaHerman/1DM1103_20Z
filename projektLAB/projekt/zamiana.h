#ifndef ZAMIANA_H
#define ZAMIANA_H

typedef struct _Ruch
{
    char *ruch;
    struct _Ruch *nast;
} Ruch;


Gra *zamiana_gora(Gra *g, int x, int y);
Gra *zamiana_dol(Gra *g, int x, int y);
Gra *zamiana_prawo(Gra *g, int x, int y);
Gra *zamiana_lewo(Gra *g, int x, int y);
Gra *zamiana_skosGL(Gra *g, int x, int y);
Gra *zamiana_skosGP(Gra *g, int x, int y);
Gra *zamiana_skosDL(Gra *g, int x, int y);
Gra *zamiana_skosDP(Gra *g, int x, int y);
Gra *zamiany(Gra *g, int x, int y);

int ifzamiana_gora(Gra g, int x, int y);
int ifzamiana_dol(Gra g, int x, int y);
int ifzamiana_prawo(Gra g, int x, int y);
int ifzamiana_lewo(Gra g, int x, int y);
int ifzamiana_skosGL(Gra g, int x, int y);
int ifzamiana_skosGP(Gra g, int x, int y);
int ifzamiana_skosDL(Gra g, int x, int y);
int ifzamiana_skosDP(Gra g, int x, int y);

Ruch *lista_ruchow(Gra g);
void zniszczliste(Ruch *glowa);
#endif
