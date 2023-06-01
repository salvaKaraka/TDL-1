/*a.  Stack*  s_create  ()  –  Retorna  una  nueva  pila.  Se  debe  invocar  antes  de 
manipular cualquiera de ellas. 
b.  int s_push(stack* s, int n) – Apila n en s. Retorna el elemento apilado. 
c.  int s_pop (stack* s) – Desapila un elemento de s. 
d.  int s_top (stack s) – Retorna el próximo elemento que será desapilado. 
e.  int s_empty(stack s) – Retorna 1 si s está vacía, 0 en caso contrario. 
f.  int s_length(stack s) – Retorna la cantidad de elementos apilados en s. 
 Taller de Lenguajes I – Ingeniería en Computación – UNLP 
4  
 
b.  Una  vez  implementadas  todas  las  funciones  de  biblioteca,  escriba  un  programa  que  lea  números 
enteros  y  los  inserte  en  una  pila.  A  continuación,  desapile  los  elementos  para  verificar  si  funciona 
correctamente. La lectura finaliza con el ingreso del 0. 
c.    Manteniendo  la  misma  interfaz,  modifique  el  tipo  de  datos  stack  y  reimplemente  la  biblioteca  para 
que la función s_length retorne la cantidad de elementos sin recorrer la pila.*/

#ifndef __ISTACK_H__
#define __ISTACK_H__

#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int data;
    int size;
    struct Stack *next;
};
typedef struct Stack Stack;

Stack* s_create(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->size=0;
    s->next=NULL;
    s->data=0;
    return s;
}

int s_empty(Stack* s){
    if (s->size==0){
        return 1;
    }
    return 0;
}

int s_length(Stack* s){
    return s->size;
}

int s_push(Stack** s, int n){
    if (s_empty(*s)){
        (*s)->data = n;
        (*s)->size++;
        return n;
    }
    Stack *aux=(Stack*)malloc(sizeof(Stack));
    aux->data = n;
    aux->size = (*s)->size;
    aux->next = *s;
    *s = aux;
    (*s)->size++;
    return n;
}

int s_pop(Stack** s){
    if (s_empty(*s)){
        return -1; // Otra opción podría ser devolver un valor especial para indicar error
    }
    int n = (*s)->data;
    if((*s)->next==NULL){
        (*s)->size=0;
        (*s)->data=0;
    }else{
    Stack *aux = *s;
    *s = (*s)->next;
    free(aux);
    }
    return n;
}

int s_top(Stack* s){
    if (s_empty(s)){
        return -1;
    }
    return s->data;
}

#endif /*__ISTACK_H__*/
//path Practica\istack.h