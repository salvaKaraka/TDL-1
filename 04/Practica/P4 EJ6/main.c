/*
6. Defina la estructura de una lista enlazada de enteros. Implemente las siguientes funciones:
a. Inicializar la lista.
b. Eliminar todos los elementos de la lista.
c. Agregar un elemento al principio de la lista.
d. Agregar un elemento al final de la lista.
e. Calcular la cantidad de elementos de la lista.
f. Imprimir todos los elementos separados por coma.
*/


#include <stdio.h>
#include <stdlib.h>
#include "lista_enlazada.h"


void imprimir(nodo* lista){
    if(lista!=NULL){
    while(lista->sig!=NULL){
        printf("%d,",lista->dato);
        lista=lista->sig;
    }
    printf("%d",lista->dato);
    }else
    printf("la lista esta vacia");
}


int main()
{
    nodo* lista;

    inicializar(&lista);

    agregarInicio(&lista, nuevoNodo(2));

    agregarInicio(&lista, nuevoNodo(1));

    agregarFinal(&lista, nuevoNodo(3));

    imprimir(lista);
    printf("\ntamanio = %d\n",tamanio(lista));


    vaciar(&lista);
    imprimir(lista);
    printf("\ntamanio = %d\n",tamanio(lista));

    return 0;
}
