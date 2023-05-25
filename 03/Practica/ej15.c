#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DIMF 50

typedef struct{
   unsigned radio;
}circulo;

typedef struct{
   unsigned rMax;
   unsigned rMin;
}elipse;

typedef struct{
   unsigned lado1;
   unsigned lado2;
   unsigned lado3;
}triangulo;

typedef struct{
   unsigned lado;
}cuadrado;

typedef struct{
   unsigned base;
   unsigned altura;
}rectangulo;

typedef union{
    circulo ci;
    elipse e;
    triangulo t;
    cuadrado cu;
    rectangulo r;
}uni;

typedef struct{
    unsigned tipo:3;
    uni f;
}figura;

enum {circulo,elipse,triangulo,cuadrado,rectangulo};

int main()
{

    return 0;
}
