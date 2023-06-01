#include <stdio.h> 
#include <stdlib.h>
 
#define SQUAREOF(x) (x)*(x) 
 
int main() { 
    int xin=3; 
 
    printf("\nxin=%i",xin); 
    printf("\nSQUAREOF(xin)=%i", SQUAREOF(xin)); 
    printf("\nSQUAREOF(xin+4)=%i", SQUAREOF(xin+4)); 
    printf("\nSQUAREOF(xin+xin)=%i", SQUAREOF(xin+xin)); 
}

/*
a.  ¿Qué es lo que hace? 
calcula la potencia 2 de un numero
b.  La  macro  SQUAREOF  debería  calcular  el  cuadrado  de  un  número.  ¿Los  resultados  son  los  esperados? 
¿Cuál es el problema? 
el problema es que no tieene en cuenta los posibles terminos ya que no los agrupa automaticamente
c. Modifique la macro para que el cálculo sea correcto.
listo, soloo agregue unos parentesis
*/