#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int reservarMemoria(int** array);

void inicializarArreglo(int* array, int);

calcularMaximo(int* array, int);

int main()
{
    int* array = NULL;
    int cant = 0;

    cant = reservarMemoria(&array);
    if (array == NULL || cant==0)printf("error en la reserva de memoria");

    inicializarArreglo(array, cant);

    printf("el valor maximo es: %d",calcularMaximo(array, cant));

    free(array);

    return 0;
}

int reservarMemoria(int** array){
    int cant;
    printf("ingrese la cantidad de elementos de su arreglo:");
    scanf("%d",&cant);

    *array = (int*) malloc(cant * sizeof(int));

    return cant;
}

void inicializarArreglo(int* array, int cant){
    srand(time(NULL));

    for (int i=0; i<cant; i++){
        *(array+i)=rand();
        printf("[%d]->",array[i]);
    }
}

int calcularMaximo(int* array, int cant){
    int max=*array;
    for (int i=0; i<cant; i++){
        if(*(array+i)>max)
            max= *(array+i);
    }
    return max;
}
