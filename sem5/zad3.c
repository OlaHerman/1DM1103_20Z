#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz
{
    int r;
    int c;
    float tab[200][200];
};

void wczytaj(FILE *fin, struct Macierz *m)
{
    int i,j;
    fscanf(fin, "%d", &(*m).r);
    fscanf(fin, "%d", &(*m).c);

    for(i = 0; i < (*m).r; i++)
    {
        for(j = 0; j < (*m).c; j++)
        {
            fscanf(fin, "%f", &(*m).tab[i][j]);
        }
    }
    printf("]\n");
}

void wypisz(struct Macierz m)
{
    int i,j;
    printf("[ ");
    for(i = 0; i < m.r; i++)
    {
        for(j = 0; j < m.c; j++)
        {
           printf("%5.1f", m.tab[i][j]);
        }
        if (i < (m.r-1))
            printf("\n ");
    }
    printf(" ]\n");
}

struct Macierz dodaj(struct Macierz n, struct Macierz m)
{
    struct Macierz suma;
    suma.c = n.c;
    suma.r = n.r;

    if (n.r == m.r && n.c == m.c)
    {
        for(int i = 0; i < n.r; i++)
        {
            for(int j = 0; j < n.c; j++)
            {
                suma.tab[i][j] + m.tab[i][j];
            }
        }return suma;
    }
    else
        {
        printf("Nie można dodać macierzy.\n");
        }
    

    struct Macierz odejmij(struct Macierz m, struct Macierz n);
    {
        struct Macierz odejmij;
        odejmij.c = n.c;
        odejmij.c = n.r;
    
      if (n.r == m.r && n.c == m.c)
         {
              for(int i = 0; i < n.r; i++)
              for(int j = 0; j < n.c; j++)
                odejmij.tab[i][j]= m.tab[i][j] - n.tab[i][j];
        }return odejmij;

         if ((n.r != m.r) || (n.c != m.c))
        {
             printf("Nie można odjąć macierzy.\n");
        }

    }

    struct Macierz mnozenie(struct Macierz m, struct Macierz n);
    {
    struct Macierz pomnoz;
    pomnoz.r = n.r;
    pomnoz.c = m.c;
    if(m.c!= n.r )
    {
        printf("Zły rozmiar macierzy \n");
        exit(-1);
    }
    for(int i = 0; i < n.r; i++)
    {
        for(int j = 0; j < m.c; j++)
        {
            pomnoz.tab[i][j] = 0;
            for (int k = 0; k < n.c; k++)
            {
                pomnoz.tab[i][j] += n.tab[i][k] * m.tab[k][j];
            }
        }
    }return pomnoz;

    }
    
}
struct Macierz mnozenie_przez_skalar(struct Macierz m, double k)
    {
        struct Macierz mnozenie_przez_skalar;
        mnozenie_przez_skalar.r = m.r;
        mnozenie_przez_skalar.c = m.c;
        for(int i = 0; i < m.r; i++)
        {
            for(int j = 0; j < m.c; j++)
            {
                mnozenie_przez_skalar.tab[i][j] = m.tab[i][j] *k;
            }
        }
        return mnozenie_przez_skalar;
    }

float norm(struct Macierz m) 
{
    float s = 0;
    int i,j;

    for (i = 0; i < m.r; i++) 
    {
        for (j=0; j < m.c; j++) 
        {
            s += m.tab[i][j] * m.tab[i][j];
        }
    }
    return sqrt(s);
}

void zapisz(char nazwa[], struct Macierz m)
 {
    FILE * fout = fopen(nazwa, "w");
    int i,j;
    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for(i = 0; i < m.r; i++)
    {
        for(j = 0; j < m.c; j++)
        {
           fprintf(fout, "%f\n", m.tab[i][j]); 
        }
    }
    fclose(fout);
 }

int main(int argc, char *argv[])
{
    struct Macierz macA;
    struct Macierz macB;
    FILE *finA;
    FILE *finB;
    
    if(strcmp(argv[1], "norm") == 0)
    {
        finA = fopen(argv[2], "r");
        wczytaj(finA, &macA);
        if(argc == 3)
        {
            printf("norma macierzy z pliku %s = %f\n", argv[2], norm(macA));
        }
        if(argc == 4)
        {
            zapisz(argv[3], norm(macA));
        }

    }

    else if(strcmp(argv[1], "prod") == 0)
    {
        
        finA = fopen(argv[2], "r");
        finB = fopen(argv[3], "r");
        wczytaj(finA, &macA);
        wczytaj(finB, &macB);

        if(argv==5)
        {
            zapisz(argv[3], mnozenie(macA, macB));
        }
        if(argv==4)
        {
            printf("Wynik mnozenia macierzy z pliku %s i %s = %f\n", argv[2], argv[3, pomnoz(macA, macB)]);
        }
    }

    else if(strcmp(argv[1], "multiply") == 0)
    {
        finA = fopen(argv[2], "r");
        wczytaj(finA, &macA);

        if(argc == 3)
        {
            printf( "wynik mnozenia macierzy z pliku %s = %f\n", argv[2], mnozenie_przez_skalar(macA,));
        }
        if(argc==4)
        {
            zapisz(argv[3], mnozenie_przez_skalar(macA));
        }
    }

    else if(strcmp(argv[1], "subtract") == 0)
    {
        finA = fopen(argv[2], "r");
        finB = fopen(argv[3], "r");

        wczytaj(finA, &macA);
        wczytaj(finB, &macB);

        if(argc == 5)
        {
            zapisz(argv[4], odejmij(macA));
        }
        if (argc == 4)
        {
            printf("wynik odejmowania macierzy = %f\n", odejmij(macA, macB));
        }

    }

    else if (strcmp(argv[1], "sum") ==0)
    {
        finA = fopen(argv[2], "r");
        finB = fopen(argv[3], "r");

        wczytaj(finA, &macA);
        wczytaj(finB, &macB);
        if(argc == 5)
        {
            zapisz(argv[4], dodaj(macA, macB));
        }
        if(argc == 4)
        {
            printf("wynik dodawania macierzy = %f\n", suma(macA, macB));
        }
    }
    fclose(finA);
    fclose(finB);
    return 0;
}

