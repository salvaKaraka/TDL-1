#include <stdio.h> 
#include <stdlib.h> 
  
int main (int argc, char *argv[]) { 
    printf("\nargc = %d", argc); 
    printf("\nargv[0] => %s", argv[0]);

    printf("\nArgumentos adicionales:\n");
    for (int i = 1; i < argc; i++) {
        printf("argv[%d] => %s\n", i, argv[i]);
    }

    return 0; 
}
//¿Qué imprime? ¿Por qué?
//argc representa la cantidad de argumentos
//argv es un array de punteros a char que contiene los argumentos, 
//el primer argumento es el nombre del programa o ruta del ejecutable