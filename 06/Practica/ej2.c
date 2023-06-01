/*Escriba un programa que calcule e imprima el promedio los números
que se pasan como argumentos a la función main. 
En caso de no pasar la cantidad necesaria de parámetros, informar al usuario. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    float promedio = 0;

    for(int i=1;i<argc;i++){
        promedio+=atof(argv[i]);
    }
    promedio/=(argc-1);
    printf("el promedio es: %f",promedio);

}