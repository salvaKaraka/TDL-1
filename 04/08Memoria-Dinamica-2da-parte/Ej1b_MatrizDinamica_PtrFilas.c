#include <stdio.h>
#include <stdlib.h>
#define FIL 3
#define COL 5
void VerMatriz(int **, int , int);
void Liberar(int **, int);
int main()
{  int f;
   int M[FIL][COL]={{1,2,3,4,5},
                    {6,7,8,9,10},
                    {11,12,13,14,15}};

   int **Dinamica = (int **) malloc(FIL*sizeof(int *));

   for (f=0; f<FIL; f++){
     Dinamica[f]=(int *) malloc(COL*sizeof(int));
     // memcpy(Dinamica[f], M[f], sizeof(M[f]));  // es correcto
     memcpy(Dinamica[f], M[f], COL*sizeof(int));
   }
   VerMatriz(Dinamica, FIL,COL);
   Liberar(Dinamica, f); //falta implementar
   return(0);
}



void VerMatriz(int **M, int fil, int col)
{ int f,c;

  for (f=0; f<fil; f++) {
    for(c=0; c<col; c++)
        // printf("%2d ", *(M+col*f+c) );   // es INCORRECTO
        // printf("%2d ", *M++ );   // es INCORRECTO
        printf("%2d ", M[f][c] );   // es CORRECTO
    printf("\n");
  }
}

void Liberar(int **M, int fil)
{  int f;
   for (f=0; f<fil; f++) {
       free(M[f]);
   }
   free(M);
}
