#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 8
#define COLUMNAS 8
#define MINAS 10

typedef enum {
    OCULTA,
    DESCUBIERTA,
    MARCADA,
    BOMBA
} EstadoCasilla;

typedef struct {
    EstadoCasilla estado;
    bool bomba;
    int numeroBombasVecinas;
} Casilla;

void desvelarCasillasVecinas(Casilla tablero[][COLUMNAS], int fila, int columna) {
    if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS ||
        tablero[fila][columna].estado != OCULTA) {
        return;
    }

    tablero[fila][columna].estado = DESCUBIERTA;

    if (tablero[fila][columna].numeroBombasVecinas == 0) {
        desvelarCasillasVecinas(tablero, fila - 1, columna - 1);
        desvelarCasillasVecinas(tablero, fila - 1, columna);
        desvelarCasillasVecinas(tablero, fila - 1, columna + 1);
        desvelarCasillasVecinas(tablero, fila, columna - 1);
        desvelarCasillasVecinas(tablero, fila, columna + 1);
        desvelarCasillasVecinas(tablero, fila + 1, columna - 1);
        desvelarCasillasVecinas(tablero, fila + 1, columna);
        desvelarCasillasVecinas(tablero, fila + 1, columna + 1);
    }
}

void mostrarTablero(Casilla tablero[][COLUMNAS]) {
    printf("    ");
    for (int j = 0; j < COLUMNAS; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < FILAS; i++) {
        printf(" %c  ", 'A' + i);
        for (int j = 0; j < COLUMNAS; j++) {
            char caracter;

            switch (tablero[i][j].estado) {
                case OCULTA:
                    caracter = '#';
                    break;
                case DESCUBIERTA:
                    if (tablero[i][j].bomba) {
                        caracter = '*';
                    } else if (tablero[i][j].numeroBombasVecinas > 0) {
                        caracter = '0' + tablero[i][j].numeroBombasVecinas;
                    } else {
                        caracter = ' ';
                    }
                    break;
                case MARCADA:
                    caracter = '?';
                    break;
                case BOMBA:
                    caracter = '*';
                    break;
            }

            printf("%c ", caracter);
        }
        printf("\n");
    }
}

void generarTablero(Casilla tablero[][COLUMNAS]) {
    // Inicializar el tablero
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            tablero[i][j].estado = OCULTA;
            tablero[i][j].bomba = false;
            tablero[i][j].numeroBombasVecinas = 0;
        }
    }

    // Colocar las minas de forma aleatoria
    int minasColocadas = 0;
    while (minasColocadas < MINAS) {
        int fila = rand() % FILAS;
        int columna = rand() % COLUMNAS;

        if (!tablero[fila][columna].bomba) {
            tablero[fila][columna].bomba = true;
            minasColocadas++;
        }
    }

    // Calcular el número de bombas vecinas para cada casilla
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (!tablero[i][j].bomba) {
                int contadorBombas = 0;

                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int filaVecina = i + x;
                        int columnaVecina = j + y;

                        if (filaVecina >= 0 && filaVecina < FILAS &&
                            columnaVecina >= 0 && columnaVecina < COLUMNAS &&
                            tablero[filaVecina][columnaVecina].bomba) {
                            contadorBombas++;
                        }
                    }
                }

                tablero[i][j].numeroBombasVecinas = contadorBombas;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    Casilla tablero[FILAS][COLUMNAS];

    generarTablero(tablero);

    bool juegoTerminado = false;

    while (!juegoTerminado) {
        mostrarTablero(tablero);

        char fila;
        int columna;
        char accion;

        printf("Ingrese su jugada (por ejemplo, A3 o B7?): ");
        scanf(" %c%d", &fila, &columna);

        fila = toupper(fila) - 'A';
        columna--;

        printf("¿Desea marcar/desmarcar la casilla? (S/N): ");
        scanf(" %c", &accion);

        if (accion == 'S' || accion == 's') {
            if (tablero[fila][columna].estado == OCULTA) {
                tablero[fila][columna].estado = MARCADA;
            } else if (tablero[fila][columna].estado == MARCADA) {
                tablero[fila][columna].estado = OCULTA;
            }
        } else {
            if (tablero[fila][columna].bomba) {
                tablero[fila][columna].estado = BOMBA;
                juegoTerminado = true;
                printf("¡Has perdido! Se encontró una bomba en la casilla seleccionada.\n");
            } else {
                tablero[fila][columna].estado = DESCUBIERTA;

                if (tablero[fila][columna].numeroBombasVecinas == 0) {
                    desvelarCasillasVecinas(tablero, fila, columna);
                }
            }
        }
    }

    mostrarTablero(tablero);

    return 0;
}
