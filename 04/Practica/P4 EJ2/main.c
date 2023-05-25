#include <stdio.h>
#include <stdlib.h>
void f (int * p);
int main(){
 int * ptr = NULL;
 f(ptr);
 if (ptr == NULL)
 printf("ptr es NULL\n");
 else
 printf("ptr no es NULL\n");
 return 0;
}
void f (int * p) {
 p = (int *) malloc(10*sizeof(int));
}

//ptr es null ya que el parametro se esta pasando por valor y no por referencia. la referencia es del valor al que apunta el puntero y no a la direccion del puntero en si.
//para que el pasaje sea por referencia se debe utilizar f(int ** p){};
