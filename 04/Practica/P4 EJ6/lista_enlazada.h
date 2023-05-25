#ifndef LISTA_ENLAZADA_H_INCLUDED
#define LISTA_ENLAZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo* sig;
};
typedef struct nodo nodo;


void inicializar(nodo** lista){
    *lista=NULL;
}


void vaciar(nodo** lista){
    nodo* aux;
    while(*lista != NULL){
        aux = *lista;
        *lista=(*lista)->sig;
        free(aux);
    }
    free(*lista);
}

void agregarInicio(nodo** lista, nodo* nuevo){
    if(*lista==NULL){
        *lista=nuevo;
    }else{
        nuevo->sig=*lista;
        *lista=nuevo;
    }
}

void agregarFinal(nodo** lista, nodo* nuevo){
    if(*lista==NULL){
        *lista=nuevo;
    }else{
        nodo* aux = *lista;

        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
}

nodo* nuevoNodo(int dato){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo));
    nuevo->dato=dato;
    nuevo->sig=NULL;
    return nuevo;
}

int tamanio(nodo* lista){
    nodo* aux = lista;
    int cont=0;
    while(aux!=NULL){
        cont++;
        aux=aux->sig;
    }
    return cont;
}


#endif // LISTA_ENLAZADA_H_INCLUDED
