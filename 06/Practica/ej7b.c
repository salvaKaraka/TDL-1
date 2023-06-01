#include <stdio.h> 
#include <stdlib.h> 
#define DEBUG 0 
 
int main(){ 
    int x= 15; 
 
    while (x<50){ 
        #if DEBUG 
   printf("x= %d", x); 
   y= y+1; 
        #endif 
        x++; 
    } 
    return 0; 
}

/*
a) ¿El código compila? ¿Por qué? 
sii, porque tras la pcompilacion, el codigo a compilar no presenta ningun error
b) ¿Qué sucedería al cambiar la constante simbólica DEBUG al valor 1? Evalúe el comportamiento del 
código. ¿Qué beneficios trae en este caso la compilación condicional?
en ese caso el codigo no compilara, porque la seccion de codigo que se habilita tras la
precompilacion si tiene errores
c) ¿Es posible cambiar el valor de la constante simbólica DEBUG en tiempo de ejecución?
no, ya que es un parametro seteado en precompilacion
d)  ¿Qué  sucede  si  en  lugar  de  utilizar  la  directiva  #if  se  emplea  #ifdef?  ¿Incide  el  valor  de  la 
constante simbólica DEBUG en el resultado de la compilación
no, ifdef compara si esta o no definida, no importa su valor*/