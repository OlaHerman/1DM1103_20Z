#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include "liczydlo.h"
#include "wczytajpliki.h"

int main (int argc,char *argv[])
{
    macierz macA;
    macierz macB;
    macierz suma;
    macierz iloczyn;
    macierz roznica;
    macierz iloczyn_macierzy;

    
    if(strcmp(argv[1], "norm") == 0)
    {
        
        if(argc == 3)
        {
            macierz macA;
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);

            norm(macA);
            float a = norm(macA);
            printf("%f", a);
        }
        else if(argc == 4)
        {
            macierz macA;
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);

            FILE *finC = fopen(argv[3], "w");
            float a = norm(macA);
            fprintf(finC, "%f\n", a);

        }

    }

    else if(strcmp(argv[1], "prod") == 0)
    {
        if(argv==5)
        {
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);
            
            FILE *finB = fopen(argv[3], "r");
            wczytaj(finB, &macB);
            fclose(finB);

            iloczyn_macierzy = mnozenie(macA, macB);
            wypisz(macA, macB);
        }
        if(argv==4)
        {
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);
            
            FILE *finB = fopen(argv[3], "r");
            wczytaj(finB, &macB);
            fclose(finB);

            FILE *finC = fopen(argv[4], "w");
            iloczyn_macierzy = mnozenie(macA, macB);
            zapisz(finC, macA, macB);
        }
    }

    else if(strcmp(argv[1], "multiply") == 0)
    {
        if(argc == 4)
        {
            macierz macA;
            float k = atof (argv[3]);

            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);
            

            iloczyn = mnozenie(macA, k);
            wypisz(macA, iloczyn);
        }
        if(argc==5)
        {
            macierz macA;
            float k = atof (argv[3]);

            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);
            
            FILE* finC = fopen(argv[4], "w");
            iloczyn = mnozenie(macA, k);
            zapisz(finC, macA, iloczyn);
        }
    }

    else if(strcmp(argv[1], "subtract") == 0)
    {

        if(argc == 5)
        {
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);
            
            FILE *finB = fopen(argv[3], "r");
            wczytaj(finB, &macB);
            fclose(finB);

            roznica = odejmij(macA, macB);
            wypisz(macA, macB);
        }
        if (argc == 4)
        {
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);
            
            FILE *finB = fopen(argv[3], "r");
            wczytaj(finB, &macB);
            fclose(finB);

            FILE *finC = fopen (argv[4], "w");
            roznica = odejmij(macA, macB);
            zapisz(finC, macA, roznica);
        }

    }

    else if (strcmp(argv[1], "sum") ==0)
    {
        if(argc == 4)
        {
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);

            FILE *finB = fopen(argv[3], "r");
            wczytaj(finB, &macB);
            fclose(finB);

            suma = dodaj (macA, macB);
            wypisz (macA, suma);
        }
        else if(argc == 5)
        {
            FILE *finA = fopen(argv[2], "r");
            wczytaj(finA, &macA);
            fclose(finA);

            FILE *finB = fopen(argv[3], "r");
            wczytaj(finB, &macB);
            fclose(finB);

            FILE *finC = fopen(argv[4], "w");
            suma = dodaj (macA, macB);
            zapisz(finC, macA, suma);
    }
}
free (&macA);
free (&macB);
free (&suma);
free (&roznica);
Free (&iloczyn);
free (&iloczyn_macierzy);
return 0;
