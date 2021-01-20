//wyznacznik macierzy z pliku

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct macierz 
{
    int wiersze, kolumny;
    float *elementy;
};

struct macierz utworz (int wiersze, int kolumny)
{
    struct macierz m = {wiersze,kolumny, calloc(wiersze*kolumny, sizeof(float))};
    
    return m;
}

void wypisz(struct macierz m) 
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.wiersze; i++)
    {
        for (j = 0; j < m.kolumny; j++) 
        {
            printf("%6.1f ", m.elementy [i*m.kolumny+j]);
        }
        printf("]\n");
    }
    
    printf("\n  ");
}

struct macierz wczytaj(char *nazwa) 
{   
    struct macierz m;
    FILE *fin;
    fin = fopen("liczby.txt","r");
    fscanf(fin, "%d%d", &m.wiersze,&m.kolumny);
    
    m = utworz (m.wiersze, m.kolumny);

    for (int i = 0; i < m.wiersze; i++) 
    {
        for (int j = 0; j < m.kolumny; j++)
        {
            fscanf(fin, "%f", &m.elementy [i*(m.kolumny)+j]);
        }
    }
     fclose(fin); 
     return m;
}
     

struct macierz zmniejszona_m (int wiersz, int kolumna, struct macierz m)
{
    struct macierz w = utworz(m.wiersze-1, m.kolumny-1);
    int iw = 0;
    int jw = 0;
    int i,j;
    
    for(int i = 0; i < m.wiersze; i++)
    {
        if(i!= wiersz);
        {    
            for(int j = 0; j < m.kolumny; j++);
            {
                if(j!= kolumna)
                {
                    w.elementy[iw*w.kolumny + jw] = m.elementy [i*m.kolumny+j];
                    iw ++;
                }    
            }
        }  
        else if
        {
            w.elementy[jw] = m.elementy[iw]
            iw++;
            jw++;
        }
    }
    return w;

}


void zniszcz_macierz(struct macierz m)
{
    free(m.elementy);
}

float wyznacznik(struct macierz m)
{   
    
    float suma = 0;
    if (m.kolumny != m.wiersze)
    {
        printf("nie mozna policzyc wyznacznika");
    }
        
    else
    {   
        if(m.kolumny == 1) 
        {
          return m.elementy[0];    
        }
        else 
        {
            for(int i=0; i < m.wiersze; i++)
            {   
                struct macierz M1 = zmniejszona_m ( m, 0, i);
                suma= suma + (powf(-1, i)* m.elementy[i] * wyznacznik(m));
                zniszcz (m1);

                // if(i%2 ==0)
                // {
                //    suma+= (m.elementy[i] *wyznacznik(M1));
                //  }
                //  else 
                // {
                //  suma+=(m.elementy[i]* wyznacznik(M1)) * (-1);  
                // }
                // printf("%f", suma);
                // zniszcz_macierz(M1);

            }
        }
        
    }
    return suma;
}

struct macierz dopelnien(struct macierz m)
{
    struct macierz M1 = {m.wiersze, m.kolumny, calloc(m.wiersze*m.kolumny, sizeof(float))};
    for (int i = 0; i < m.wiersze*m.kolumny; i++)
    {
        if((int)(i/m.kolumny)%2 == 0)
        {
            if(i%2 == 0)
            {
                M1.elementy[i] = wyznacznik(zmniejszona_m(i%m.kolumny, i%m.kolumny, m));
            }
            else 
            {
                M1.elementy[i] = (-1) * wyznacznik(zmniejszona_m(i%m.kolumny, i%m.kolumny, m));
            }
        }
        else
        {
            if(i%2 == 0)
            {
                M1.elementy[i] = (-1) * wyznacznik(zmniejszona_m(i%m.kolumny, i%m.kolumny, m));
            }
            else
            {
               M1.elementy[i] = wyznacznik(zmniejszona_m(i%m.kolumny, i%m.kolumny, m));
            }
            
        }
        
    }
    return M1;
}

int main(int argc, char *argv[])
{   
    struct macierz M = wczytaj ("liczby.txt");
    printf("%f\n",suma);
    zniszcz_macierz(M);
    
    return 0;
}