#include <stdio.h>
#include <stdlib.h>

int reservarMemoria(float** array){
    int cant;
    printf("ingrese la cantidad de elementos: ");
    scanf("%d",&cant);
    *array= (float*) malloc(cant * sizeof(float));
    return cant;
}

void inicializarArreglo(float* array, int cant){
    for (int i=0; i<cant; i++){
        printf("ingrese el numero en la posicion %d : ", i);
        scanf("%f",(array+i));
    }
}

float calcularPromedio(float* array, int cant){
    float tot=0;

    for(int i=0; i<cant; i++){
        tot+=array[i];
    }

    return tot / cant;
}



int main()
{
    float* array;
    int cant;

    cant = reservarMemoria(&array);
    inicializarArreglo(array,cant);

    printf("el valor promedio es: %.2f", calcularPromedio(array,cant));

    free(array);
    return 0;
}
