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

void imprimir(nodo* lista){
    if (lista != NULL){
        while(lista->sig!=NULL){
            printf("%d,",lista->dato);
            lista=lista->sig;
        }
        printf("%d",lista->dato);
    }else printf("lista vacia");
}


void cargarLista(nodo** lista){
    int dato;
    printf("ingrese un numero(0 para finalizar):");
    scanf("%d",&dato);
    while(dato!=0){
        agregarFinal(lista,nuevoNodo(dato));
        printf("ingrese un numero(0 para finalizar):");
        scanf("%d",&dato);
    }
}

nodo* invertirLista(nodo* lista){
    nodo* inversa;
    inicializar(&inversa);

    while(lista!=NULL){
        agregarInicio(&inversa, nuevoNodo(lista->dato));
        lista=lista->sig;
    }
    return inversa;
}


void eliminarNodo(nodo** lista,int dato){
    if (*lista!=NULL){
       nodo* aux=*lista;

       if (aux->dato == dato){
            *lista=aux->sig;
            free(aux);
       } else {

           while (aux->sig != NULL){
                if (aux->sig->dato == dato){
                    nodo* aux2 = aux -> sig;
                    aux->sig = aux2 -> sig;
                    free(aux2);
                }
                aux=aux->sig;
           }
       }
    }
}

#endif // LISTA_ENLAZADA_H_INCLUDED
