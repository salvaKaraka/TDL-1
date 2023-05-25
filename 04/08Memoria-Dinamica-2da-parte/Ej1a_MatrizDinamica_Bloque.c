#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FIL 3
#define COL 5

void VerMatriz(int *, int f, int c);
int main()
{  int M[FIL][COL]={{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15}};
   int *Dinamica = (int *) malloc(FIL*COL*sizeof(int));

   memcpy(Dinamica, M, sizeof(M));
   printf("Inicio de la matriz en : %p\n", Dinamica);
   VerMatriz(Dinamica, FIL,COL);
   printf("Inicio de la matriz en : %p\n", Dinamica);
   free(Dinamica);
   return(0);
}

void VerMatriz(int *M, int fil, int col)
{ int f,c;

  for (f=0; f<fil; f++) {
    for(c=0; c<col; c++)
        printf("%2d ", *(M+col*f+c) );   // es correcto
        // printf("%2d ", *M++ );   // es correcto
        // printf("%2d ", M[f][c] );   // es INCORRECTO
    printf("\n");
  }
}
