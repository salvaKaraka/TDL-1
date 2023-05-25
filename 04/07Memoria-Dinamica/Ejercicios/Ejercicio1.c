#include <stdio.h>
#include <stdlib.h>

void Mostrar(int * p, int N);
int main()
{  int i, *vector, Cant;

   printf("Cant.de nros. a leer :\n");
   scanf("%d", &Cant);

   vector = (int *) malloc(Cant * sizeof(int));

   for (i=0; i<Cant; i++){
      scanf("%d", vector+i);
   }
   Mostrar(vector, Cant);
   free(vector);

   return(0);
}

void Mostrar(int * p, int N)
{   int i;

    printf("Los datos leidos son :\n");
    for (i=0; i<N; i++){
      printf("%d\n", *(p+i));
    }
}


