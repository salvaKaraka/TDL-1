#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    int n = 5;

    // Asignar memoria utilizando malloc y calloc

    //ptr = (int*) malloc(n * sizeof(int));

    ptr = (int*) calloc(n, sizeof(int));

    printf("%d\n",*ptr);

    // Inicializar valores
    for (int i = 0; i < n; i++) {
        ptr[i] = i;
        printf("%d\n",*(ptr+i));
    }

    // Cambiar el tama�o del bloque utilizando realloc
    n = 10;
    ptr = (int*) realloc(ptr, n * sizeof(int));
    printf("%d\n",*(ptr+6));
    // Liberar la memoria asignada

    free(ptr);
    printf("%d\n",*ptr);


    return 0;
}

//1. Responda:
//a. �En qu� se diferencia la funci�n malloc de la funci�n calloc? �y de la funci�n realloc?
//malloc se utiliza para reservar un espacio de memoria y devuelve un puntero void a la primera
//celda de memoria de ese espacio. calloc, ademas de hacer esto, inicializa el bloque a cero. realloc cambia
//el tamanio del bloque asignado por malloc o calloc.

//b. �Puede utilizarse la funci�n realloc en lugar de la funci�n malloc? �Se requiere alguna
//condici�n? �Qu� sucede si realloc se invoca con el valor 0 como par�metro?
//si, podemos utilizar un puntero a null como primer argumento y el tamano a reservar como segundo.
//si la llamamos con el valor cero puede comportarse como free();

//c. �Qu� utilidad tiene el operador sizeof a la hora de reservar memoria din�micamente?
//nos permite distinguir entre tipos de datos a la hora de reservar memoria y asi asignar el espacio necesario.

