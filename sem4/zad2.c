#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wczytaj_macierz(FILE *fin, float tablica[][100])
{
    int wiersze = 0;
    int kolumny = 0;
    float liczba;


    fscanf(fin, "%d %d", &wiersze,&kolumny);

    for (int i=0; i<wiersze; i++)
    {
        for(int j=0; j<kolumny; j++)
        {
          fscanf(fin, "%f", &liczba);
          
           tablica[i][j] = liczba;
        }
    }
    return wiersze;
}

void iloczyn(float macierz[][100], float wektor[][100], int wiersze_1, int wiersze_2)
{
    float suma=0;
    printf("[ ");
    int j=0; 
    for(int i=0; i<wiersze_1; i++)
    {
        for(int k=0; k<wiersze_2; k++)
        {
            suma=suma + (macierz[i][k] * wektor[k][j]);
        }
       printf("%f ", suma);
        suma= 0;

    }
    printf(" ]\n");
}

int main(int argc, char *argv[])
{
    FILE *fin1;
    FILE *fin2;

    float wektor[100][100];
    float macierz[100][100];

    int wiersze_1,wiersze_2;
    fin1 = fopen(argv[1], "r");
    fin2 = fopen(argv[2], "r");

    wiersze_1=wczytaj_macierz(fin1,macierz);
    wiersze_2=wczytaj_macierz(fin2,wektor);

    printf("(%d) ", wiersze_1);
    iloczyn(macierz,wektor,wiersze_1,wiersze_2);
    
        return 0;
}