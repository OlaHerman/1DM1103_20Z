#include <stdio.h>
#include <stdlib.h>
#define N 3


struct macierz
{
    float elementy[N][N];

};

struct macierz dodaj(struct macierz A, struct macierz B)
{
    struct macierz suma;
    for(int wiersz = 0; wiersz < N; wiersz ++)
        for(int kolumna = 0; kolumna < N;  kolumna ++)
        {
             suma.elementy[wiersz][kolumna] = A.elementy[wiersz][kolumna] + B.elementy[wiersz][kolumna];
        }
       
return suma;
}

struct macierz pomnoz (struct macierz A, struct macierz B)
{
    struct macierz wynik = {{0, 0, 0, 0, 0, 0, 0, 0, 0}};
    for(int wiersz = 0; wiersz < N; wiersz++)
    {
        for(int kolumna = 0; kolumna < N; kolumna ++)
        {
            for(int x = 0; x<N; x++)
            {
                wynik.elementy[wiersz][kolumna] += A.elementy[wiersz][x] * B.elementy[x][kolumna];
            }
        }
    }return wynik;
} 

void wypisz(struct macierz A)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%4.0f", A.elementy[i][j]);
        }
        printf("\n ");
    }
}

int main()
{
    struct macierz wynik = pomnoz((struct macierz) {0, 1, 2, 3, 4, 5, 6, 7, 8}, (struct macierz) {8, 7, 6, 5, 4, 3, 2, 1, 0});
    wypisz (wynik);
    return 0;
}

int main()
{
    FILE * fp;

    fp = fopen("file.txt", "wt");
    fprintf(fp, "%s", macierz_A);

    fclose(fp);

    return 0;
}

int wczytaj_macierz(FILE *fin, float tablica[][100])
{
    int wiersz = 0;
    int kolumna = 0;
    float liczba;


    fscanf(fin, "%d %d", &wiersze,&kolumny);

    for (int i=0; i<wiersz; i++)
    {
        for(int j=0; j<kolumna; j++)
        {
          fscanf(fin, "%f", &liczba);
          
           tablica[i][j] = liczba;
        }
    }
    return wiersz;
}