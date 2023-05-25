#include <stdio.h>
#define C 1.61

int main(){


float a = 0;
float b = 0;

printf("introduzca distancia en km:");
scanf("%f",&a);

b=a/C;

printf("\n La distancia en millas es: %.2f",b);

return 0;
}
