#include <stdio.h>
#include <stdlib.h>
struct persona {
   char nom[20];
   int edad;
};
void cargarMatriz(struct persona **, int, int);
void verMatriz(struct persona **, int, int);
void leer(struct persona *);

struct persona ** reservar(int, int);
void liberar(struct persona **, int);

int main()
{  int Equipos=3, Personas=2;
   struct persona **Mat;

   Mat = reservar(Equipos,Personas);

   cargarMatriz(Mat, Equipos,Personas);

   verMatriz(Mat, Equipos,Personas);

   liberar(Mat, Equipos);

   return 0; /* indica terminación exitosa */
}
struct persona ** reservar(int FILA, int COL)
{  int fila;
   struct persona ** aux;

   aux = malloc(FILA * sizeof(struct persona *));

   for (fila=0; fila<FILA; fila++)
       aux[fila] = malloc(COL*sizeof(struct persona));

   return(aux);
}

void liberar(struct persona ** Mat, int FILA)
{  int fila;
   for (fila=0; fila<FILA; fila++)
       free(Mat[fila]);
   free(Mat);
}

void cargarMatriz(struct persona **matriz, int FIL, int COL)
{ int i,j;
  for (i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
           //leer(&(matriz[i][j]));
           //leer(matriz[i]+j);
           leer(*(matriz+i)+j);

}

void leer(struct persona * alguien){
    printf("Ingrese el nombre :");
    scanf("%s", alguien->nom);

    printf("Ingrese la edad :");
    scanf("%d", &(alguien->edad));

}

void verMatriz(struct persona **matriz, int FIL, int COL)
{ int i,j;

  for (i=0; i<FIL; i++)
        for(j=0; j<COL; j++)
           printf("%s   %d\n", (matriz[i]+j)->nom,
                    (matriz[i]+j)->edad);
}
