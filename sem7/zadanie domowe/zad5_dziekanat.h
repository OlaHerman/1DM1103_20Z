#ifndef _zad5_dziekanat_h
#define _zad5_dziekanat_h

#include "zad5_studenci.h"

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

void najlepszy_student(student dane[100], int ile_rekordow);
void najlepszy_przedmiot(student dane[100], int ile_rekordow);
void najgorszy_przedmiot(student dane[100], int ile_rekordow);
int znajdz_p(char *szukany_nr, char kod_przed[100][10], int n);
int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n);

#endif