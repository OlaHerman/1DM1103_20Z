#include <stdio.h>
#define N 3

//mnozenie macierzy
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