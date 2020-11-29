#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "wczytajpliki.h"

float norm(macierz m1) 

{
	float s = 0;
	int i, j;

	for (i = 0; i < m1.r; i++) 
    {
		for (j = 0; j < m1.c; j++) 
        {
			s += m1.tab[i][j] * m1.tab[i][j];
		}
	}
	return sqrt(s);
}

macierz dodaj(macierz m1, macierz m2)
{
    int i, j;
    float s; 
    macierz *suma;
    suma = (macierz *) malloc (sizeof(macierz));

    suma->r = m1.r;
	suma->c = m1.c;

    suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for (int i = 0;i < suma-> r; i++)
         suma->tab[i] = (float*) malloc(sizeof(float) * suma->c);
	
	for (int i = 0; i < suma->r; i++) 
    {
		for (int j = 0; j < suma->c; j++) 
        {
			s = 0;
			s+= m1.tab[i][j] + m2.tab[i][j];

			suma->tab[i][j] = s;
		}
	}
	return *suma;
}

macierz odejmij (macierz m1, macierz m2)

{
    int i, j;
    float s; 
    macierz *roznica;
    roznica = (macierz *) malloc (sizeof(macierz));

    roznica->r = m1.r;
	roznica->c = m1.c;

    roznica->tab = (float**) malloc(sizeof(float*) * roznica->r);
    for (int i = 0;i < roznica-> r; i++)
         roznica->tab[i] = (float*) malloc(sizeof(float) * roznica->c);
	
	for (int i = 0; i < roznica->r; i++) 
    {
		for (int j = 0; j < roznica->c; j++) 
        {
			s = 0;
			s+= m1.tab[i][j] - m2.tab[i][j];

			roznica->tab[i][j] = s;
		}
	}
	return *roznica;
}

macierz pomnoz(macierz m1, float k)
{
	float s;
	macierz *iloczyn;

	iloczyn = (macierz*) malloc(sizeof(macierz));

	iloczyn->r = m1.r;
	iloczyn->c = m1.c;

	iloczyn->tab = (float**) malloc(sizeof(float*) * iloczyn->r);
    for (int i = 0 ;i < iloczyn-> r; i++)
         iloczyn->tab[i] = (float*) malloc(sizeof(float) * iloczyn->c);
	
	for (int i = 0; i < iloczyn->r; i++) 
    {
		for (int j = 0; j < iloczyn->c; j++) 
        {
			s = 0;
			s += m1.tab[i][j] * k;
			iloczyn->tab[i][j] = s;
		}
	}
	return *iloczyn;
}

macierz iloczyn (macierz m1, macierz m2)
{
    int i, j;
    float s; 
    macierz *iloczyn_macierzy;
    iloczyn_macierzy = (macierz *) malloc (sizeof(macierz));

    iloczyn_macierzy->r = m1.r;
	iloczyn_macierzy->c = m1.c;

    iloczyn_macierzy->tab = (float**) malloc(sizeof(float*) * iloczyn_macierzy->r);
    for (int i = 0;i < iloczyn_macierzy-> r; i++)
         iloczyn_macierzy->tab[i] = (float*) malloc(sizeof(float) * iloczyn_macierzy->c);
	
	for (int m = 0; m < iloczyn_macierzy->r; m++) 
    {
		for (int n = 0; n < iloczyn_macierzy->c; n++) 
        {
			float s = 0;
            for (int x = 0; x< m1.r; x++)
			s+= m1.tab[m][x] * m2.tab[x][n];

			iloczyn_macierzy->tab[m][n] = s;

		}
	}
	return *iloczyn_macierzy;
}




