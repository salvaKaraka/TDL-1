#include <stdio.h>
#include <stdlib.h>

// Estructura de datos para representar la pirámide de Pascal
typedef struct {
    int** matriz;
    int filas;
} PiramidePascal;

// Función para crear una pirámide de Pascal de n filas
PiramidePascal crearPiramidePascal(int n) {
    PiramidePascal piramide;
    piramide.filas = n;
    piramide.matriz = (int**) malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        piramide.matriz[i] = (int*) malloc((i + 1) * sizeof(int));

        piramide.matriz[i][0] = 1;  // Primer elemento de cada fila es 1
        piramide.matriz[i][i] = 1;  // Último elemento de cada fila es 1

        for (int j = 1; j < i; j++) {
            piramide.matriz[i][j] = piramide.matriz[i - 1][j - 1] + piramide.matriz[i - 1][j];
        }
    }

    return piramide;
}

// Función para imprimir la pirámide de Pascal en forma de triángulo isósceles
void imprimirPiramidePascal(PiramidePascal piramide) {
    int espacios = piramide.filas - 1;

    for (int i = 0; i < piramide.filas; i++) {
        for (int j = 0; j < espacios; j++) {
            printf("  ");  // Imprimir espacios
        }

        for (int j = 0; j <= i; j++) {
            printf("%4d", piramide.matriz[i][j]);  // Imprimir elementos de la pirámide
        }

        espacios--;
        printf("\n");
    }
}

// Función para destruir la pirámide de Pascal y liberar la memoria
void destruirPiramidePascal(PiramidePascal piramide) {
    for (int i = 0; i < piramide.filas; i++) {
        free(piramide.matriz[i]);
    }
    free(piramide.matriz);
}

int main() {
    int n;
    printf("Ingrese el número de filas para la pirámide de Pascal: ");
    scanf("%d", &n);

    PiramidePascal piramide = crearPiramidePascal(n);

    printf("Pirámide de Pascal:\n");
    imprimirPiramidePascal(piramide);

    destruirPiramidePascal(piramide);

    return 0;
}
