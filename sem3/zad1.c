#include <stdio.h>
#include <stdlib.h>

// argv[0] - nazwa programu
int main(int argc, char *argv[]) {
    float v; 
    float a1;
    a1= 5;
    v = a1 * a1;
    printf("[%f] wynik: %f\n", a1, v);
    //printf("[%s] Suma: %f\n", argv[0]), v);
}