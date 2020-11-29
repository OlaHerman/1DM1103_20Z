#ifndef _zad5_studenci_h
#define _zad5_studenci_h

#include "zad5_dziekanat.h"


int wczytaj(student dane[100], char *fnazwa);
void wypisz(student dane[100], int n) ;
int znajdz_s(char *szukany_nr, char nr_albumow[100][10], int n);
int znajdz_studentow(char nr_albumow[100][10], student dane[100], int n);


#endif