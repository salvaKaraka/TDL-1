#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    unsigned horas:5;
    unsigned minutos:6;
    unsigned segundos:5;
}horario;

void verHora(horario hs){
    printf("%02d:%02d:%02d",hs.horas,hs.minutos,(hs.segundos*2));

};


int main()
{
    time_t now;

    struct tm *local = localtime(&now);
    horario hs;

    hs.horas = local->tm_hour;
    hs.minutos = local->tm_min;
    hs.segundos = (local->tm_sec)/2;

    printf("Horario actual (peso de %d)\n", sizeof(hs));
    verHora(hs);

    return 0;
}
