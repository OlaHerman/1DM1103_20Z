#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// wczytywanie  macierzy z pliku i zapisywanie w innym pliku
struct macierz 
{
    int wiersze;
    int kolumny;
    float *elementy;
};

struct macierz utworz(int wiersze, int kolumny)
{
    struct macierz m = {wiersze,kolumny,calloc(wiersze*kolumny,sizeof(float))};
    
    return m;
}

void wypisz(struct macierz m) 
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.wiersze; i++)
    {
        for (j=0; j < m.kolumny; j++) 
        {
        printf("%6.1f ", m.elementy[i*m.kolumny+j]);
        }
        if (i < (m.wiersze-1))
        printf("\n  ");
    }
    printf("]\n");
}



struct macierz wczytaj(char *nazwa) 
{   
    struct macierz m;
    FILE *fin;
    fin=fopen(nazwa,"r");
    fscanf(fin, "%d%d", &m.wiersze,&m.kolumny);
    
    m=utworz(m.wiersze,m.kolumny);

    for (int i=0; i < m.wiersze; i++) {
        for (int j=0; j < m.kolumny; j++) {
            fscanf(fin, "%f", &m.elementy[i*(m.kolumny)+j]);
        }
    }
     fclose(fin); 
     return m;
}
     

void wypisztxt(char *nazwa,struct macierz m) 
{
    FILE *fin= fopen(nazwa,"w+");
    int i, j;
    fprintf(fin,"%d\n%d\n",m.wiersze,m.kolumny);
    for (i = 0; i < m.wiersze; i++)
    {
        for (j=0; j < m.kolumny; j++) 
        {
        fprintf(fin,"%.1f ",m.elementy[i*m.kolumny+j]);
        }
        fprintf(fin,"\n");
    }
    fclose(fin);
}

void zniszcz_macierz(struct macierz m)
{
    free(m.elementy);
}

int main(int argc, char *argv[])
{   
    //FILE *fin;
   // fin=fopen("macierz.txt","w+");
  
    struct macierz M;
    M=wczytaj("liczby.txt");
    wypisz(M);
    
    wypisztxt("macierz.txt", M);
    zniszcz_macierz(M);
  
    return 0;
  
}