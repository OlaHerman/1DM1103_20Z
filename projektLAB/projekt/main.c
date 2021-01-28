#include "podstawa.h"
#include "interfejs.h"
#include "zamiana.h"

int main(int argc, char **argv)
{
    Gra *ot = (Gra *)malloc(sizeof(Gra));

    warunek1(atoi(argv[1]));
    stworz(ot, atoi(argv[1]));
    wypisz(*ot);

    ruchy(ot);
    zakonczenie(*ot);
    ocena(*ot);
    
    free(ot->pole);
    free(ot);
    return 0;
}