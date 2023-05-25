//Escriba un programa que imprima la raíz cuadrada, el cuadrado y el cubo de los números enteros comprendidos en el rango 1..10.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    for(int i=1; i<=10; i++){
        printf("Raiz cuadrada de %d: %.2f \n",i,(float)sqrt(i));
        printf("Cuadrado de %d: %d \n",i,(int)pow(i,2));
        printf("Cubo de %d: %d \n",i,(int)pow(i,3));
    }
    return 0;
}
