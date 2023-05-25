#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    float ancho;
    float alto;
}separadas;

typedef struct{
    float xy[2];
    float xy2[2];
}deados;

typedef union{
//    struct{
//        float x;
//        float y;
//        float ancho;
//        float alto;
//    }coord;
    separadas coord1;
    deados coord2;
    float cord3[4];
}coordenadas;

int main()
{
    coordenadas i;

    i.coord1.x=45;

    printf("Hello world!\n");
    return 0;
}
