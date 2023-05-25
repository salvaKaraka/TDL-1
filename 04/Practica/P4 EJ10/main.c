#include <stdio.h>
#include <stdlib.h>

int reservarMemoria(double** array, int cant){

    *array= (double*) malloc(cant * sizeof(double));
    return cant;
}

void inicializarArreglo(double* array, int cant){
    *array = NULL;
    for (int i=0; i<cant; i++){
        printf("ingrese el numero en la posicion %d : ", i);
        scanf("%lf",&array[i]);
    }
}

double calcularPromedio(double* array, int cant){
    double tot=0;

    for(int i=0; i<cant; i++){
        tot+=array[i];
    }

    return tot / cant;
}

/*

void inicializarArreglo(double* array, int cant){
    for (int i=0; i<cant; i++){
        printf("ingrese el numero en la posicion %d : ", i);
        scanf("%lf",(array+i));
    }
}

double calcularPromedio(double* array, int cant){
    double tot=0;

    for(int i=0; i<cant; i++){
        tot+=(array+i);
    }

    return tot / cant;
}

*/

int main()
{
    double* array;

    int cant;
    printf("ingrese la cantidad de elementos: ");
    scanf("%d",&cant);

    cant = reservarMemoria(&array, cant);
    inicializarArreglo(array,cant);

    printf("el valor promedio es: %.2lf", calcularPromedio(array,cant));

    free(array);
    return 0;
}
