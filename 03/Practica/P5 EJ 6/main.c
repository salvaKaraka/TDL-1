#include <stdio.h>
#include <stdlib.h>

typedef union{
    struct{
        short int aaaa;
        char mm;
        char dd;
    }fecha;
    int hack;
}unionFecha;


int main()
{
    char caracter;
    short int enteroreducido;
    int entero;
    printf("Caracter: %d \n",sizeof(caracter));
    printf("Short integer: %d \n",sizeof(enteroreducido));
    printf("integer: %d \n",sizeof(entero));

    printf("dia \t mes \t anio \n");

    unionFecha fecha1;
    fecha1.fecha.aaaa=1990;
    fecha1.fecha.dd=26;
    fecha1.fecha.mm=3;

    unionFecha fecha2;
    fecha2.fecha.aaaa=1990;
    fecha2.fecha.dd=26;
    fecha2.fecha.mm=12;

    printf("fecha 1: \t %d \t %d \t %d \n",fecha1.fecha.dd, fecha1.fecha.mm, fecha1.fecha.aaaa);

    printf("fecha 2: \t %d \t %d \t %d \n",fecha2.fecha.dd, fecha2.fecha.mm, fecha2.fecha.aaaa);

    if (fecha1.hack == fecha2.hack) printf("las fechas coinciden");
    else printf("las fechas no coinciden");

    return 0;
}
