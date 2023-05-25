#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("../Practica-5---Recursos/apuestas.txt","r");

    if(!f){
        printf("error al abrir el archivo");
        return 1;
    }

    int c;
    float a;
    float tot_a=0;


    while(fscanf(f,"%d|%f;",&c,&a)==2){
        tot_a+=a;
    }

    if(fclose(f)){
        printf("error al cerrar archivo");
        return 1;
    }

    printf("el monto tottal apostado es de: %.2f",tot_a);

    return 0;
}
