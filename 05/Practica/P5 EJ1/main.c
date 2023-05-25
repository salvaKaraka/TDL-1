#include <stdio.h>
#include <stdlib.h>
#define LONG 300
int main(){
 FILE *f;
 char linea[LONG];

 // Abrir el archivo
 f = fopen("../Practica-5---Recursos/prueba.txt", "r");

 if (f == NULL){
    printf ("\nError al abrir archivo fuente\n");
 return 1;
 }

 fgets(linea,LONG,f);
 while (!feof(f)){
     puts(linea);
     fgets(linea,LONG,f);
 }

 if (fclose(f)){
    printf("Error al intentar cerrar el archivo");
    return 1;
 }

 return 0;
}
