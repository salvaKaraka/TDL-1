#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{  char * palabra;

   palabra = (char *) malloc(15);

   strcpy(palabra, "Texto dinamico");

   printf("%s",palabra);

   free(palabra);

   return 0;
}
