#include <stdio.h>
int main()
{ /* agregar l�neas al archivo prueba.txt */
  FILE * arch;
  char c;

  /*abre el archivo para lectura*/
  arch = fopen("Lectura1.txt", "r");
  if (arch=NULL) {
      printf("Error al abrir el arch.!!\n");
  }
  else {  /* abri� bien */

    fclose(arch);
  }
  return 0;
}
