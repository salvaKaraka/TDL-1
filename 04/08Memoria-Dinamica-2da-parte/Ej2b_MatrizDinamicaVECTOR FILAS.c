#include <stdio.h>
#include <stdlib.h>
void cargarMatriz(int **, int, int);
void verMatriz(int **, int, int);

int main()
{  int N, M, **Mat;
   int fila;
   printf("Ingrese la cant. de filas :");
   scanf("%d", &N);
   printf("Ingrese la cant. de columnas :");
   scanf("%d", &M);

   Mat = (int **) malloc(N * sizeof(int *));
   for (fila=0; fila<N; fila++)
       Mat[fila] = (int *) malloc( M * sizeof(int));

   cargarMatriz(Mat, N, M);

   verMatriz(Mat, N, M);

   for (fila=0; fila<N; fila++)
       free(Mat[fila]);
   free(Mat);

   return 0; /* indica terminación exitosa */
}

void cargarMatriz(int **matriz, int FIL, int COL)
{ int i,j;
  for (i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
           matriz[i][j] = i*COL+j;
  /*
  for(i=0; i<FIL*COL; i++)
     matriz[i] = i; */
}

void verMatriz(int **matriz, int FIL, int COL)
{ int i,j;

  for (i=0; i<FIL; i++){
        for(j=0; j<COL; j++)
           printf("%2d  ", *(matriz[i]+j));
        printf("\n");
  }
}
