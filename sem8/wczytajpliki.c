#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "wczytajpliki.h"

void wczytaj(FILE *finA, macierz *m1)
{
    int i,j;
    fscanf(finA, "%d", &(*m1).r);
    fscanf(finA, "%d", &(*m1).c);

    m1->tab = (float **) malloc(sizeof(float *) *m1->r);
    for (i = 0; i < m1; i++)
    m1->tab[i] = (float *)malloc(sizeof(float *) *m1->r);

    for(i = 0; i < (*m1).r; i++)
    {
        for(j = 0; j < (*m1).c; j++)
        {
            fscanf(finA, "%f", &(*m1).tab[i][j]);
        }
    }
}

void wypisz(macierz m1, macierz m2)
{
    int i,j;
    printf("[ ");
    for(i = 0; i < m1.r; i++)
    {
        for(j = 0; j < m1.c; j++)
        {
           printf("%5.1f", m2.tab[i][j]);
        }
        if (i < (m1.r - 1))
            printf(" \n ");
    }
    printf(" ]\n");
}

void zapisz(FILE * finA, macierz m1, macierz m2)
 {
    int i,j;
    fprintf(finA, "[ ");
    for(i = 0; i < m1.r; i++)
    {
        for(j = 0; j < m1.c; j++)
        {
           fprintf(finA, "%5.1f \n", m2.tab[i][j]); 
        }
    }
    
 }

 void free(macierz *m1)
 {
     for (int i = 0; i < m1->r; i++)
        free (m1-> tab[i]);
    free (m1->tab);
    free(m1);
 }
