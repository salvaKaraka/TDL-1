/*7. Utilizando la estructura y funciones del ejercicio anterior escriba un programa que lea números
enteros positivos desde teclado hasta ingresar el número 0. Los números leídos deben ser almacenados
en orden ingresado por teclado. Generar una nueva lista con el orden invertido. Imprimir los
elementos de cada lista junto con la cantidad de elementos de cada una. Por último, libere la memoria
reservada dinámicamente. */
#include <stdio.h>
#include <stdlib.h>
#include "lista_enlazada.h"

nodo* invertirLista(nodo* lista){
    nodo* inversa;
    inicializar(&inversa);

    while(lista!=NULL){
        agregarInicio(&inversa, nuevoNodo(lista->dato));
        lista=lista->sig;
    }
    return inversa;
}

int main()
{
    nodo* lista;
    inicializar(&lista);

    cargarLista(&lista);

    imprimir(lista);

    nodo* inversa = NULL;
    inversa = invertirLista(lista);

    printf("\n");

    imprimir(inversa);

    vaciar(&lista);
    vaciar(&inversa);

    return 0;
}
