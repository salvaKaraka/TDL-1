#include <stdio.h>
#include <stdlib.h>
void cargarMatriz(int *, int, int);
void verMatriz(int *, int, int);

int main()
{  int N, M, *Mat;

   printf("Ingrese la cant. de filas :");
   scanf("%d", &N);
   printf("Ingrese la cant. de columnas :");
   scanf("%d", &M);

   Mat = malloc(N*M*sizeof(int));

   cargarMatriz(Mat, N, M);

   verMatriz(Mat, N, M);

   free(Mat);

   return 0; /* indica terminación exitosa */
}

void cargarMatriz(int *matriz, int FIL, int COL)
{ int i,j;
 /* for (i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
           matriz[i*COL+j] = i*COL+j;
  */
  for(i=0; i<FIL*COL; i++)
     matriz[i] = i;
}

void verMatriz(int *matriz, int FIL, int COL)
{ int i,j;

  for (i=0; i<FIL; i++){
        for(j=0; j<COL; j++)
           printf("%2d  ", matriz[i*COL+j]);
        printf("\n");
  }
}
