#include <stdio.h>
#include <stdlib.h>

#define DimF 10

struct Rectangulo{
    float base;
    float altura;
};

void cargarRectangulo(struct Rectangulo *R);

float calcularArea(struct Rectangulo);

int main()
{
    struct Rectangulo vectorRectangulos[DimF];
    float minArea = 9999999;
    int recMinArea = 0;

    for(int i=0; i<DimF; i++){
        cargarRectangulo(&vectorRectangulos[i]);
        if(calcularArea(vectorRectangulos[i])<minArea){
            minArea = calcularArea(vectorRectangulos[i]);
            recMinArea=i;
        }
    }

    printf("El rectangulo con menor area es: %d , con un area de: %f",recMinArea,minArea);


}

void cargarRectangulo(struct Rectangulo *R){

    printf("Ingrese altura del rectangulo:");
    scanf("%f",&R->altura);

    printf("Ingrese largo del rectangulo:");
    scanf("%f",&R->base);
};

float calcularArea(struct Rectangulo R){
    return (R.altura * R.base);
}
