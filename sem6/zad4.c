//obliczanie najlepszej sredniej z bazy studentów i przedmiotów

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student 
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) 
{
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);

        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

int znajdz(char *szukany_nr, char kod_przed[100][10], int n) 
{
    int i;
    for (i=0; i<n; i++) 
    {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)

            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n) 
{
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) 
    {
        if (znajdz(dane[i].kod_przed, kod_przed, ile_znalazlem ) == -1) 
        {
            strncpy(kod_przed[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}

void najlepszy_przedmiot(student dane[100], int ile_rekordow)
{
    char kod_przed[100][10];
    char nazwa_przed[100][200];
    int ile_przedmiotow;
    float srednia[100];
    for (int j = 0; j < 100; j++)
    srednia[j] = 0;
    int ile_dodac[100];
    for (int j = 0; j < 100; j++)
    ile_dodac[100];
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 0.0f;

    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for(i = 0; i < ile_rekordow; i++)
    {
        pozycja = znajdz(dane[i].kod_przed, kod_przed, ile_przedmiotow);
        strcpy(nazwa_przed[pozycja], dane[i].nazwa_przed);
        ile_dodac[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }
    for (i = 0; i < ile_przedmiotow; i++) 
    {
        srednia[i] = srednia[i]/ile_dodac[i];
    }
    

    for (i=0; i < ile_przedmiotow; i++) 
    {
        if (najlepsza < srednia[i]) 
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }
    printf("Najlepsza średnia: %s - %s: %.3f \n", kod_przed[najlepsza_pozycja], nazwa_przed[najlepsza_pozycja], srednia[najlepsza_pozycja]);
}

void najgorszy_przedmiot(student dane[100], int ile_rekordow) 
{
    char kod_przed[100][10];
    char nazwa_przed[100][200];
    int ile_przedmiotow;
    float srednia[100];
    for(int j = 0; j < 100; j++)
    srednia[j]=0;
    int ile_dodac[100];
    for(int j = 0; j < 100; j++)
    ile_dodac[j]=0;
    int i;
    int pozycja;
    int najlepsza_pozycja;
    float najlepsza = 6.0f;

    ile_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (i=0; i < ile_rekordow; i++) 
    {
        pozycja = znajdz( dane[i].kod_przed, kod_przed, ile_przedmiotow );
        strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);
        ile_dodac[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }    

    for (i=0; i < ile_przedmiotow; i++) 
    {
        srednia[i] = srednia[i]/ile_dodac[i];
    }
    

    for (i=0; i < ile_przedmiotow; i++) 
    {
        if (najlepsza > srednia[i]) 
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najgorsza średnia: %s - %s: %.3f \n", kod_przed[najlepsza_pozycja], nazwa_przed[najlepsza_pozycja], srednia[najlepsza_pozycja]);
}



int main(int argc, char ** argv)
{
    student dane[100];
    int ile;
    ile = wczytaj(dane, argv[1]);

    najlepszy_przedmiot(dane, ile);
    najgorszy_przedmiot(dane, ile);

    return 0;
}