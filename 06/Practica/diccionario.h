#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <stdlib.h>
#include <string.h>

#define MAX_PALABRAS 100

typedef struct {
    char palabras[MAX_PALABRAS][100];
    int cantidad_palabras;
} Diccionario;

Diccionario* d_crear();
int d_agregar_palabra(Diccionario* diccionario, const char* palabra);
int d_existe_palabra(const Diccionario* diccionario, const char* palabra);
int d_eliminar_palabra(Diccionario* diccionario, const char* palabra);
void d_cargar_desde_archivo(Diccionario* diccionario, const char* nombre_archivo);
void d_guardar_a_archivo(const Diccionario* diccionario, const char* nombre_archivo);
void d_destruir(Diccionario* diccionario);

Diccionario* d_crear() {
    Diccionario* diccionario = (Diccionario*) malloc(sizeof(Diccionario));
    diccionario->cantidad_palabras = 0;
    return diccionario;
}

int d_agregar_palabra(Diccionario* diccionario, const char* palabra) {
    if (d_existe_palabra(diccionario, palabra)) {
        return 0; // La palabra ya existe en el diccionario
    }
    if (diccionario->cantidad_palabras >= MAX_PALABRAS) {
        return 0; // El diccionario está lleno
    }
    strcpy(diccionario->palabras[diccionario->cantidad_palabras], palabra);
    diccionario->cantidad_palabras++;
    return 1; // Palabra agregada exitosamente
}

int d_existe_palabra(const Diccionario* diccionario, const char* palabra) {
    int i;
    for (i = 0; i < diccionario->cantidad_palabras; i++) {
        if (strcmp(diccionario->palabras[i], palabra) == 0) {
            return 1; // La palabra existe en el diccionario
        }
    }
    return 0; // La palabra no existe en el diccionario
}

int d_eliminar_palabra(Diccionario* diccionario, const char* palabra) {
    int i;
    for (i = 0; i < diccionario->cantidad_palabras; i++) {
        if (strcmp(diccionario->palabras[i], palabra) == 0) {
            int j;
            for (j = i; j < diccionario->cantidad_palabras - 1; j++) {
                strcpy(diccionario->palabras[j], diccionario->palabras[j+1]);
            }
            diccionario->cantidad_palabras--;
            return 1; // Palabra eliminada exitosamente
        }
    }
    return 0; // La palabra no existe en el diccionario
}

void d_cargar_desde_archivo(Diccionario* diccionario, const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n", nombre_archivo);
        return;
    }
    char palabra[100];
    while (fgets(palabra, sizeof(palabra), archivo) != NULL) {
        palabra[strcspn(palabra, "\n")] = '\0'; // Eliminar el salto de línea al final
        d_agregar_palabra(diccionario, palabra);
    }
    fclose(archivo);
}

void d_guardar_a_archivo(const Diccionario* diccionario, const char* nombre_archivo) {
    FILE* archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s\n", nombre_archivo);
        return;
    }
    int i;
    for (i = 0; i < diccionario->cantidad_palabras; i++) {
        fprintf(archivo, "%s\n", diccionario->palabras[i]);
    }
    fclose(archivo);
}

void d_destruir(Diccionario* diccionario) {
    free(diccionario);
}

#endif /* DICCIONARIO_H */
