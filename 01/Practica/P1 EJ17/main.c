#include <stdio.h>
#include <stdlib.h>

void minMax(int n, float *min_ptr, float *max_ptr){
    float num;

    // Leer el primer número
    printf("Ingrese un número: ");
    scanf("%f", &num);

    *min_ptr = *max_ptr = num;

    for (int i=1; i<n ; i++){

        // Leer los demas números
        printf("Ingrese un número: ");
        scanf("%f", &num);

        if (num>*max_ptr)
            *max_ptr=num;
        else
        if (num<*min_ptr){
            *min_ptr=num;
        }
    }
}

int main()
{
    int n;
    float min, max;

    // Leer la cantidad de numeros
    printf("Ingrese ls cantidad de numeros: ");
    scanf("%d", &n);

    minMax(n,&min,&max);

    printf("minimo \t maximo \n %.2f \t %.2f",min,max);

    return 0;
}
