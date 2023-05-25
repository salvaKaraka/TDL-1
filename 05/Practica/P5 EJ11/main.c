/*Escriba un programa que abra el archivo binario del ejercicio anterior y que imprima en pantalla el
tamaño en bytes de dicho archivo. ¿Por qué cree Ud. que tiene ese tamaño?*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* f = fopen("../P5 EJ9 Y 10/jugadores.dat","rb");
    fseek(f,0,SEEK_END);
    printf("Tamano del archivo: %ld bytes",ftell(f));
}