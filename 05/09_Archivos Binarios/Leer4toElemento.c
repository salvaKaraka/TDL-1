#include <stdio.h>
int main()
{  FILE * arch;
   int valor;

   arch = fopen("AccesoDirecto", "rb");

   if (arch==NULL)
         printf("Error al abrir!");
   else {
         fseek(arch, 3*sizeof(int), SEEK_SET);

         fread(&valor, sizeof(int), 1, arch);

         printf("%d\n", valor);

         fclose(arch);
   }
   return 0;
}
