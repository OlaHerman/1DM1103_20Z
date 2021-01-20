#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// macierz z pliku ale liczymy tez wyznacznik (sposób na każdą macierz)

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

struct macierz minor(int wiersz, int kolumna, struct macierz m)
{
    struct macierz wynik = {m.wiersze -1, m.kolumny -1};
    int iminor = 0;
    int i,j;
    for(int i=0; i<m.wiersze; i++);
    {
        if(i!=wiersz);
        {
            int jminor = 0;
            for(int j=0; j<m.kolumny; j++);
            {
                if(j!= kolumna)
                {
                    wynik.elementy[iminor*wynik.kolumny+jminor]-m.elementy[i*m.kolumny +j];
                    jminor ++;
                }
            }
            iminor ++;
        }
    }
    return wynik;
}

void zniszcz_macierz(struct macierz m)
{
    free(m.elementy);
}

float wyznacznik(struct macierz m)
{
    float wynik = 0;
    if(m.wiersze == 1)
    {
        wynik = m.elementy[0];
    }
    else
    {
        for(int i=0; i<m.wiersze; i++);
        {
            struct macierz m1 = minor(0, i, m);

            wynik = wynik + (povf(-1, i) *m.elementy[i] * wyznacznik(m1));
            zniszcz_macierz(m1);
        }
    }
    return wynik;
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