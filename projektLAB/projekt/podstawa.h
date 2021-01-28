#ifndef PODSTAWA_H
#define PODSTAWA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define B 'B'
#define C 'C'


typedef struct _Gra
{
    int wymiar;
    char *pole;
    char kolor;
} Gra;

int warunek2(Gra g, int x, int y);
int warunek3(Gra *g, char a, int x);

int ile_pionow(Gra g, char kolor);
int przewaga(Gra g);
int ocena(Gra g);

Gra ruch(Gra g, int x, int y);
Gra *stworz(Gra *g, int w);
void wypisz(Gra g);
Gra * ruchy(Gra *g);


Gra * zamiany(Gra *g, int x, int y);
int mozliwe_ruchy(Gra *g);
int negmax(Gra* sz, int glebokosc, int alfa, int beta);

#endif