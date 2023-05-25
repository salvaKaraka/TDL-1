#include <stdio.h>
#include <stdlib.h>
void cargarMatriz(int **, int, int);
void verMatriz(int **, int, int);

int ** reservar(int, int);
void reservar2(int ***, int, int);

void liberar(int **, int);

int main()
{  int N, M, **Mat;
   printf("Ingrese la cant. de filas :");
   scanf("%d", &N);
   printf("Ingrese la cant. de columnas :");
   scanf("%d", &M);

//   Mat = reservar(N, M);
   reservar2(&Mat, N, M);

   cargarMatriz(Mat, N, M);

   verMatriz(Mat, N, M);

   liberar(Mat, N);

   return 0; /* indica terminación exitosa */
}
int ** reservar(int FILA, int COL)
{  int fila;
   int ** aux = (int **) malloc(FILA * sizeof(int *));

   for (fila=0; fila<FILA; fila++)
       aux[fila] = (int *) malloc( COL * sizeof(int));

   return(aux);
}

void reservar2(int ***Mat, int FILA, int COL)
{  int fila;
   *Mat = (int **) malloc(FILA * sizeof(int *));

   for (fila=0; fila<FILA; fila++)
       *(*Mat+fila) = (int *) malloc( COL * sizeof(int));
 //       *Mat[fila] = (int *) malloc( COL * sizeof(int));
}

void liberar(int ** Mat, int FILA)
{  int fila;
   for (fila=0; fila<FILA; fila++)
       free(Mat[fila]);
   free(Mat);
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
