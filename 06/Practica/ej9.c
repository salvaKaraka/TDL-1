/*Una vez implementadas todas las funciones de biblioteca, escriba un programa que lea números enteros e 
imprima  el  cuadrado  y  el  cubo  de  aquellos  números  que  son  pares  y  el  factorial  de  aquellos  que  son 
impares. La lectura finaliza con el ingreso del 0.*/

#include <stdio.h>
#include <stdlib.h>
#include "imath.h"

int main(){
    int n;
    printf("ingrese n:");
    scanf("%d",&n);
    while (n!=0){
        if(n%2){
            printf("factorial:%d",factorial(n));
        }else printf("cuadrado:%d cubo:%d",cuadrado(n),cubo(n));
        printf("\ningrese n:");
        scanf("%d",&n);
    }
    return 0;
}