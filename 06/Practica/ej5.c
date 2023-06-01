#include <stdio.h> 
#include <stdlib.h> 
 
#define size 25 
 
void imprimir(int * v){ 
    int i; 
    for (i=0; i<size; i++){ 
        printf("v[%d]= %d/n", i, v[i]); 
    } 
} 
 
int main(){ 
    int v[size]={0}; 
    imprimir(v); 
    return 0; 
}
/*
a) ¿El código compila? Lea detenidamente el primer error que se detecta. ¿Cómo se explica? 
el erroor esta en que la macro y el parametro de la funcion no pueden tener el mismo nombre
b) Identifique  las  etapas  de  precompilación  y  compilación.  ¿Qué  es  lo  que  está  ocurriendo  en  cada 
una?
en la precompilacion se incluyen las librerias y la macro.
en la etapa de compilacion se pasa a codigo maquina el programa
c) ¿Cómo podría solucionarse este problema?
este problema se soluciona eliminando el parametro size o en su defecto
cambiandoole el nombre. tambien inicialice el vector a cero.
*/