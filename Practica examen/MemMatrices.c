#include <stdio.h>
#include <stdlib.h>

#define FIL 3
#define COL 4

int sumaUltimaFila(int *, int, int);

int main()
{
    int V[FIL][COL] = {0}, *ptr;
    int *m = (int*) calloc(FIL*COL,sizeof(int));

    printf("%zu %zu\n", sizeof(V), sizeof(m));

    V[1][1] = 10;
    m[1*COL+1] = 10;

    ptr = &V[1][0];
    *(ptr-2) = 21;
    *(m+5) = 21;
    *(ptr+5) = 22;
    *(m+12*COL/4-1) = 22;

    printf("La suma de los nros. ");
    printf("de la ultima fila de m es = %d\n", sumaUltimaFila(m, FIL, COL));

    printf("La suma de los nros. ");
    printf("de la ultima fila de V es = %d\n", sumaUltimaFila((int *)V, FIL, COL));

    free(m);
    return 0;
}

int sumaUltimaFila(int *matriz, int filas, int columnas)
{
    int suma = 0;
    int ultimaFila = (filas - 1) * columnas;

    for (int i = 0; i < columnas; i++)
    {
        suma += *(matriz + ultimaFila + i);
    }

    return suma;
}