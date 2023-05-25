#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum{bluetooth=1<<0, wifi=1<<1, gps=1<<2, datos=1<<3, frontal=1<<4, trasera=1<<5, linterna=1<<6, vibrar=1<<7}modulos;

int main()
{
    char booleano;
    int estado1=datos + bluetooth;
    int estado2= bluetooth|wifi|gps|datos|frontal|trasera|linterna|vibrar;


    //es activo
    booleano = esActivo(estado1,datos);
    verBits(estado1);
    printf("el modulo datos en el estado 1 es activo: %d\n", booleano);

    verBits(estado2);
    booleano = esActivo(estado2,wifi);
    printf("el modulo wifi en el estado 2 es activo: %d\n", booleano);

    activar(&estado2,bluetooth);
    desactivar(&estado1, wifi);
    invertir(&estado2, vibrar);

    verBits(estado1);
    verBits(estado2);

    return 0;
}

void verBits(int estado){
    unsigned mascara = 1<<7;
    for(int i=1; i<=8; i++){
        putchar(estado & mascara ? '1' : '0');
        estado <<=1;
    }
    putchar('\n');
}

int esActivo(int estado, modulos modulo){
    return (estado & modulo)? 1 : 0;
}

void activar(int *estado, modulos modulo){
    *estado |= modulo;
}

void desactivar(int *estado, modulos modulo){
    *estado &= ~modulo;
}

void invertir(int *estado, modulos modulo){
    *estado ^= modulo;
}
