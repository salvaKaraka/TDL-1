#include <stdio.h>
#include <stdlib.h>

typedef enum{LUN, MAR, MIER, JUE, VIE, SAB, DOM}dias;

int main()
{
    dias d = MIER;
    printDay(d);
    return 0;
}

void printDay1(dias d){
    const char *nombresDias[]={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
    printf("%s",nombresDias[d]);
}
