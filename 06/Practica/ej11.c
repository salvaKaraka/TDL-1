/*prueba de diccionario.h*/

#include <stdio.h>
#include "diccionario.h"

int main() {
    Diccionario* diccionario = d_crear();

    // Agregar palabras al diccionario
    d_agregar_palabra(diccionario, "hola");
    d_agregar_palabra(diccionario, "mundo");
    d_agregar_palabra(diccionario, "programacion");
    d_agregar_palabra(diccionario, "diccionario");

    // Verificar la existencia de palabras
    printf("Existe 'hola': %d\n", d_existe_palabra(diccionario, "hola"));
    printf("Existe 'chau': %d\n", d_existe_palabra(diccionario, "chau"));

    // Eliminar palabras del diccionario
    d_eliminar_palabra(diccionario, "hola");
    d_eliminar_palabra(diccionario, "programacion");

    // Verificar la existencia de palabras después de eliminar
    printf("Existe 'mundo': %d\n", d_existe_palabra(diccionario, "mundo"));
    printf("Existe 'programacion': %d\n", d_existe_palabra(diccionario, "programacion"));

    // Cargar y guardar desde un archivo
    d_cargar_desde_archivo(diccionario, "diccionario.txt");
    d_guardar_a_archivo(diccionario, "diccionario_salida.txt");

    // Destruir el diccionario
    d_destruir(diccionario);

    return 0;
}