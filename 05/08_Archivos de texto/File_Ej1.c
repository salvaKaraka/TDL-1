#include <stdio.h>
int main()
{  FILE * arch;

   arch = fopen("prueba.txt", "w");
   if (arch==NULL)
      fprintf(stdout, "Error al abrir el archivo!\n");
   else
      fprintf(stdout, "El archivo est� abierto\n");

   fprintf(arch, "Este es mi primer archivo \n");
   fprintf(arch, "creado desde un programa C.");

   fclose(arch);
   printf("El archivo est� cerrado\n");

   return 0;
}

