#include <stdio.h>
#include <stdlib.h>

#define DimF 50

void cargarArreglo(int *arreglo, int *pares, int *impares);

void mostrarArreglo(int arreglo[DimF]);

int main()
{
    srand(time(NULL));

    int arreglo[DimF], pares=0, impares=0;

    cargarArreglo(arreglo, &pares, &impares);

    mostrarArreglo(arreglo);

    printf("Numeros pares: %d /n Numeron impares: %d /n", pares, impares);


    return 0;
}


void cargarArreglo(int *arreglo, int *pares, int *impares){

    for (int i; i<DimF; i++){
        arreglo[i] = rand();
        if(((arreglo[i]%2)==0) && ((i%2)!=0)){
            *pares+=1;
        } else
        if(((arreglo[i]%2)!=0) && ((i%2)==0)){
            *impares+=1;
        }
    }
}

void mostrarArreglo(int arreglo[DimF]){
    for (int i; i<DimF; i++){
        printf("%d: %d\n",i,arreglo[i]);
    }
}
