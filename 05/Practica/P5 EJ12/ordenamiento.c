/*
a) Realice un programa que permita generar un índice para acceder por DNI de manera eficiente a
la información del archivo de texto “personas.csv”. Este archivo contiene los datos de una persona
(identificador, dni, nombre, apellido, correo, ciudad, país y trabajo que desarrolla) en formato CSV.
El índice debe generarse en memoria y estar ordenado por DNI para finalmente almacenarlo en el
archivo binario “personas.idx”. Este archivo binario deberá tener por cada línea del archivo
“personas.csv” una entrada que contenga el DNI de la persona junto con la posición absoluta dentro
del archivo a los datos asociados a dicho DNI. Diseñe una estructura de datos adecuada para el
índice y tenga en cuenta al momento de generarlo que la primera línea del archivo CSV es de
encabezado. 
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Indice
{
    int dni;
    long int pos;
    struct Indice* siguiente;
} Indice;

void insertarOrdenado(Indice** cabeza, Indice* nuevoNodo) {
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL || nuevoNodo->dni < (*cabeza)->dni) {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
    } else {
        Indice* actual = *cabeza;
        while (actual->siguiente != NULL && nuevoNodo->dni > actual->siguiente->dni) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

int main() {
    FILE* personas, * indice;
    personas = fopen("personas.csv", "r");
    indice = fopen("personas.idx", "wb");

    if (personas == NULL || indice == NULL) {
        printf("Error al abrir los archivos");
        return 1;
    }

    Indice* ind = NULL;
    Indice* aux = NULL;
    char linea[MAX];
    long int pos = ftell(personas);  // Obtener la posición antes del bucle

    fgets(linea, MAX, personas); // Leer la primera línea (encabezado)

    while (fgets(linea, MAX, personas)) {
        aux = (Indice*)malloc(sizeof(Indice));
        sscanf(linea, "%*d;%d", &aux->dni);
        aux->pos = pos;  // Almacenar la posición obtenida previamente
        insertarOrdenado(&ind, aux);
        pos = ftell(personas);  // Actualizar la posición para la siguiente línea
    }

    while (ind != NULL) {
        aux = ind;
        fwrite(aux, sizeof(Indice), 1, indice);
        ind = ind->siguiente;
        free(aux);
    }

    fclose(personas);
    fclose(indice);

    return 0;
}