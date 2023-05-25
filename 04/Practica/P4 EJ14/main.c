#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para reservar memoria para una matriz triangular inferior de enteros
int** reservarMemoria(int n) {
    int** matriz = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*) malloc((i + 1) * sizeof(int));
    }
    return matriz;
}

// Función para inicializar la matriz con valores aleatorios entre 0 y 20
void inicializarMatriz(int** matriz, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            matriz[i][j] = rand() % 21;  // Valores aleatorios entre 0 y 20
        }
    }
}

// Función para imprimir la matriz en pantalla
void imprimirMatriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para liberar la memoria reservada para la matriz
void liberarMemoria(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int n;
    printf("Ingrese el valor de n: ");
    scanf("%d", &n);

    int** matriz = reservarMemoria(n);

    inicializarMatriz(matriz, n);

    printf("Matriz triangular inferior:\n");
    imprimirMatriz(matriz, n);

    liberarMemoria(matriz, n);

    return 0;
}
