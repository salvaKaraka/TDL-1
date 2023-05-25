#include <stdio.h>
#include <stdlib.h>
#define N 10
void Mostrar(double * , int );
int main()
{  double peso, *V = NULL;
   int i=0;
   printf("Ingrese un numero en (0,250]):\n");
   scanf("%lf", &peso);
   while ((peso>0) & (peso<=250)){
      if (i % N == 0){
          printf("Pido 10 posiciones mas\n");
          V=(double *)realloc(V,(i+N)*sizeof(double));
          if (V == NULL)  // no hay memoria suficiente!
             exit(-1);
             else printf("Hay lugar para %d valores\n", i+N);
      }
      /* Ya existe suficiente memoria para el sigte.valor*/
      V[i++] = peso;
      scanf("%lf", &peso);
   }
   Mostrar(V, i);
   return(0);
}

void Mostrar(double * p, int n)
{   int i;

    printf("Los datos leidos son :\n");
    for (i=0; i<n; i++){
      printf("%.2lf\n", *(p+i));
    }
}

