#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
int dato;
struct nodo * siguiente;
} lista;

void quitarNodo(lista** L, int n){
    if(*L==NULL)printf("lista vacia");
    else{
    
        lista* aux = *L;

        if (aux->dato==n){
            *L=(*L)->siguiente;
            free(aux);
        }else{

            while ((aux->siguiente->dato!=n) && (aux->siguiente!=NULL)){
                aux=aux->siguiente;
            }

            if(aux->siguiente->dato == n){
                lista* aux2 = aux->siguiente;
                aux->siguiente = aux2->siguiente;
                free(aux2);
            }else printf("dato no encontrado");
        }
    }
}

void cargarLista(lista** L, int n){
    lista* nuevo = (lista*)malloc(sizeof(lista));
    nuevo->dato = n;
    nuevo->siguiente = NULL;
    if(*L==NULL){
        *L=nuevo;
    }else{
        lista* aux = *L;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
    }
}

void imprimir(lista* L){
    if(L == NULL){
        printf("lista vacia\n");
        return;
    }
    while(L != NULL){
        printf("[%d]->", L->dato);
        L = L->siguiente;
    }
    printf("\n");
}

int main(){

    lista* L =NULL;

    cargarLista(&L, 10);
    cargarLista(&L, 20);
    cargarLista(&L, 30);
    cargarLista(&L, 40);

    imprimir(L);

    quitarNodo(&L,40);
    imprimir(L);

    quitarNodo(&L,30);
    imprimir(L);
    
    quitarNodo(&L,20);
    imprimir(L);

    quitarNodo(&L,10);
    imprimir(L);


    return 0;
}
