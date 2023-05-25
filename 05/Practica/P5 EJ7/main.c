/*Escriba un programa que copie el contenido de un archivo de texto en otro nuevo.
a) Utilizando las funciones fgetc y fputc.
b) Utilizando las funciones fgets y fputs.
c) Utilizando las funciones fread y fwrite.
*/

#include <stdio.h>
#include <stdlib.h>

void fgetcCopy(FILE* f, FILE* n){
    char* c=(char*)malloc(sizeof(char));
    while((*c=fgetc(f)) != EOF) fputc(*c, n);
    free(c);
}

void fgetsCopy(FILE* f, FILE* n){
    char* linea=(char*)malloc(1000*sizeof(char));
    while(fgets(linea,500,f) != NULL) fputs(linea, n);
    free(linea);
}

void freadCopy(FILE* f, FILE* n){
    char *c = malloc(sizeof(char));
    while(fread(c, sizeof(char), 1, f) != 0) fwrite(c, sizeof(char), 1, n);
    free(c);
}

int main(){
    FILE* f = fopen("leer.txt", "r");
    FILE* n = fopen("escribir.txt", "w");
    if(!f || !n){
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    int opcion;

    opciones:
    printf("copiar con fgetc:1 \t fgets:2 \t fread:3\n");
    scanf("%d",&opcion);

    switch(opcion){
        case 1: fgetcCopy(f,n);
        break;

        case 2: fgetsCopy(f,n);
        break;

        case 3: freadCopy(f,n);
        break;

        default: printf("opcion no valido");
        goto opciones;
    }

}