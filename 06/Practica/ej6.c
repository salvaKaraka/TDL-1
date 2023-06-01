#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define pi 3.1416
#define AREA_CIRCULO(r) pi*(r)*(r)
#define RANDOM(n) rand() % n + 1 //genera un numero random de 1 a n

int main() {
    srand(time(NULL));
    int rango = 10;
    for (int i = 0; i < 10; i++) {
        int radio = RANDOM(rango);
        printf("radio = %d, area= %f\n", radio, AREA_CIRCULO(radio));
    }
    return 0;
}