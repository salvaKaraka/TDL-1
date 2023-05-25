#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum{bluetooth=1<<0, wifi=1<<1, gps=1<<2, datos=1<<3, frontal=1<<4, trasera=1<<5, linterna=1<<6, vibrar=1<<7}modulos;

typedef struct{
    unsigned e:8;
}estado;

int main()
{
    char booleano;
    estado estado1={datos + bluetooth};
    estado estado2= {bluetooth|wifi|gps|datos|frontal|trasera|linterna|vibrar};


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

void verBits(estado estado){
    unsigned mascara = 1<<7;
    for(int i=1; i<=8; i++){
        putchar(estado.e & mascara ? '1' : '0');
        estado.e <<=1;
    }
    putchar('\n');
}

int esActivo(estado estado, modulos modulo){
    return (estado.e & modulo)? 1 : 0;
}

void activar(estado *estado, modulos modulo){
    estado->e |= modulo;
}

void desactivar(estado *estado, modulos modulo){
    estado->e &= ~modulo;
}

void invertir(estado *estado, modulos modulo){
    estado->e ^= modulo;
}
