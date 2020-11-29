#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zad5_studenci.h"
#include "zad5_dziekanat.h"


int main (int argc, char **argv)
{
    student dane[100];
    int ile = wczytaj(dane, argv[1]);

    if (strcmp (argv[2], "najgorszy_przedmiot")==0)
    {
        najgorszy_przedmiot(dane, ile);
    }

    if (strcmp (argv[2],"najlepszy_przedmiot") ==0)
    {
        najlepszy_przedmiot(dane, ile);
    }
    if (strcmp (argv[2],"student") ==0)
    {
        najlepszy_student(dane, ile);
    }
    return 0;
}