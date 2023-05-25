#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned red:5;
    unsigned green:6;
    unsigned blue:5;
}RGB16;

typedef struct{
    unsigned red:8;
    unsigned green:8;
    unsigned blue:8;
}RGB24;

RGB24 de16a24(RGB16 pixel){
    RGB24 resultado = {
    .red=pixel.red<<3,
    .green = pixel.green<<2,
    .blue = pixel.blue<<3
    };
    return resultado;
}

RGB16 de24a16(RGB24 pixel){
    RGB16 resultado = {
    .red = pixel.red>>3,
    .green= pixel.green>>2,
    .blue= pixel.blue>>3
    };
    return resultado;
}

int main()
{
    RGB16 pixel1 = {15,31,15};
    RGB24 pixel2 = {255,255,255};
    RGB16 pixel3;
    RGB24 pixel4;

    printf("R:%d\tG:%d\tB:%d\n",pixel1.red,pixel1.green,pixel1.blue);
    printf("R:%d\tG:%d\tB:%d\n",pixel2.red,pixel2.green,pixel2.blue);

    printf("intercambiados:\n");
    pixel3=de24a16(pixel2);
    pixel4=de16a24(pixel1);

    printf("R:%d\tG:%d\tB:%d\n",pixel3.red,pixel3.green,pixel3.blue);
    printf("R:%d\tG:%d\tB:%d\n",pixel4.red,pixel4.green,pixel4.blue);
    return 0;
}
