#ifndef liczydlo_h
#define liczydlo_h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "wczytajpliki.h"

float norm(macierz m1);

macierz dodaj(macierz m1, macierz m2);

macierz odejmij (macierz m1, macierz m2);

macierz pomnoz(macierz m1, float k);

macierz iloczyn (macierz m1, macierz m2);


#endif