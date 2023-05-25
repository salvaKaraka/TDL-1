#include <stdio.h>
int main()
{  FILE * arch;
   int v[10], i;

   arch = fopen("AccesoDirecto", "rb");

   if (arch==NULL)
         printf("Error al abrir!");
   else {
         fread(v, sizeof(int), 10, arch);

         for( i=0; i<10; i++)
            printf("v[%d] = %d\n", i,v[i]);

         fclose(arch);
   }
   return 0;
}
