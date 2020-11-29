#ifndef wczytajpliki_h
#define wczytajpliki_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct macierz
{
    int r;
    int c;
    float **tab;

}macierz;

void wczytaj(FILE *finA, macierz*m1);

void wypisz(macierz m1, macierz m2);

void zapisz(FILE *finA, macierz m1, macierz m2);

void free(macierz *m1);

#endif