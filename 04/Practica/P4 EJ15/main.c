#include <stdio.h>
#include <stdlib.h>

// Estructura de datos para representar la pir�mide de Pascal
typedef struct {
    int** matriz;
    int filas;
} PiramidePascal;

// Funci�n para crear una pir�mide de Pascal de n filas
PiramidePascal crearPiramidePascal(int n) {
    PiramidePascal piramide;
    piramide.filas = n;
    piramide.matriz = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        piramide.matriz[i] = (int*) malloc((i + 1) * sizeof(int));

        piramide.matriz[i][0] = 1;  // Primer elemento de cada fila es 1
        piramide.matriz[i][i] = 1;  // �ltimo elemento de cada fila es 1

        for (int j = 1; j < i; j++) {
            piramide.matriz[i][j] = piramide.matriz[i - 1][j - 1] + piramide.matriz[i - 1][j];
        }
    }

    return piramide;
}

// Funci�n para imprimir la pir�mide de Pascal en forma de tri�ngulo is�sceles
void imprimirPiramidePascal(PiramidePascal piramide) {
    int espacios = piramide.filas - 1;

    for (int i = 0; i < piramide.filas; i++) {
        for (int j = 0; j < espacios; j++) {
            printf("  ");  // Imprimir espacios
        }

        for (int j = 0; j <= i; j++) {
            printf("%4d", piramide.matriz[i][j]);  // Imprimir elementos de la pir�mide
        }

        espacios--;
        printf("\n");
    }
}

// Funci�n para destruir la pir�mide de Pascal y liberar la memoria
void destruirPiramidePascal(PiramidePascal piramide) {
    for (int i = 0; i < piramide.filas; i++) {
        free(piramide.matriz[i]);
    }
    free(piramide.matriz);
}

int main() {
    int n;
    printf("Ingrese el n�mero de filas para la pir�mide de Pascal: ");
    scanf("%d", &n);

    PiramidePascal piramide = crearPiramidePascal(n);

    printf("Pir�mide de Pascal:\n");
    imprimirPiramidePascal(piramide);

    destruirPiramidePascal(piramide);

    return 0;
}
