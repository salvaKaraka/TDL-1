/*Realice un programa que genere un vector de 1000 enteros al azar y utilice una función para localizar un 
elemento. Se pide: 
a) Implementar la función de búsqueda  que, dado un entero, retorne la posición donde se encuentra. 
En caso de no existir el número retorne -1. 
b) Modificar a) para agregar información de depuración que permita imprimir en consola la cantidad 
de  veces  que  se  debió  acceder  al  arreglo  para  encontrar  (o  no)  el  elemento  en  cada  llamado  a  la 
función.  Utilice  las  directivas  del  procesador  para  activar/desactivar  la  depuración  e  imprimir/no 
imprimir la información en la consola. 
c) Verifique  el  tamaño  del  programa  compilando  con  la  depuración  y  sin  la  depuración.  Explique 
porque difieren.
difieren porque la cantidad de lineas a compilar en cada caso es diferente*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define RANDOM(n) rand() % n + 1 //genera un numero random de 1 a n

#define DEBUG_ENABLED

int busquedaLineal(int* v,int n){
    for (int i = 0; i < SIZE; i++) {
        #ifdef DEBUG_ENABLED
        printf("accedio a v %d veces\n",i);
        #endif
        if(v[i]==n){
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(NULL));
    int v[SIZE];
    for (int i = 0; i < SIZE; i++) {
        v[i]=RANDOM(1000);
    }
    int n = RANDOM(1000);
    printf("elemento:%d encontrado en: %d",n,busquedaLineal(v,n));
    return 0;
}