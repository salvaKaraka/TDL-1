#include <stdio.h>
#include <stdlib.h>
#define DimF 5


float valorPromedio(float array[DimF]){

    float prom=0;

    for (int i=0; i<DimF; i++){
        prom+=array[i];
    }

    prom/=DimF;

    return prom;
}

float valorMinimo(float array[DimF]){

    float min=99999999;

    for (int i=0; i<DimF; i++){
        if (array[i]<min){
            min=array[i];
        }
    }
    return min;
}

int posicionMaximo(float array[DimF]){

    float max=-99999999999;
    int pos;

    for (int i=0; i<DimF; i++){
        if (array[i]>max){
            max=array[i];
            pos=i;
        }
    }
    return pos;
}


int main()
{
    float array[DimF]={5.4, 23.5, 2345.2, 56.4, 45};

    printf("Valor Promedio: %.2f \n", valorPromedio(array));
    printf("Valor Minimo: %.2f \n", valorMinimo(array));
    printf("Posicion de Valor Maximo: %d \n", posicionMaximo(array));

    return 0;
}
