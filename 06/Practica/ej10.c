/*
b.  Una  vez  implementadas  todas  las  funciones  de  biblioteca,  escriba  un  programa  que  lea  números 
enteros  y  los  inserte  en  una  pila.  A  continuación,  desapile  los  elementos  para  verificar  si  funciona 
correctamente. La lectura finaliza con el ingreso del 0.*/

#include <stdio.h>
#include <stdlib.h>
#include "istack.h"

int main() {
    int n;
    Stack* s = s_create();
    printf("Ingrese n: ");
    scanf("%d", &n);

    while (n != 0) {
        s_push(&s, n);
        printf("Ingrese n: ");
        while(getchar() != '\n'); // Limpiar el búfer del teclado
        scanf("%d", &n);
    }

    while (!s_empty(s)) {
        printf("\nSe desapilo: %d", s_pop(&s));
        printf("\nes vacia: %d", s_empty(s));
    }

    return 0;
}