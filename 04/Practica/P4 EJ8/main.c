/*8. Utilizando la estructura y funciones de los ejercicios anteriores escriba un programa que lea n�meros
enteros desde teclado hasta ingresar el n�mero 0. Luego, vuelva a leer otro n�mero entero desde
teclado y elimine de la lista a todos aquellos que sean m�ltiplos del mismo.*/
#include <stdio.h>
#include <stdlib.h>
#include "lista_enlazada.h"



void eliminarMultiplos(nodo** lista,int mult){

    nodo* aux= *lista;
    nodo* nueva;
    inicializar(&nueva);

    while(aux!=NULL){
        if(aux->dato % mult){
            agregarFinal(&nueva,nuevoNodo(aux->dato));
        }
        aux=aux->sig;
    }
    vaciar(lista);
    *lista = nueva;
}

int main()
{
    nodo* lista;
    inicializar(&lista);
    cargarLista(&lista);
    imprimir(lista);

    int mult;

    printf("\n eliminar los multiplos de: ");
    scanf("%d",&mult);

    printf("\n eliminando multiplos de %d...\n",mult);
    eliminarMultiplos(&lista, mult);

    imprimir(lista);

    vaciar(&lista);

    return 0;
}
