#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct{
    unsigned int Bluetooth:1;
    unsigned int Wifi:1;
    unsigned int GPS:1;
    unsigned int Datos:1;
    unsigned int Frontal:1;
    unsigned int Trasera:1;
    unsigned int Linterna:1;
    unsigned int Vibrar:1;
} celular;

enum {Bluetooth,Wifi,GPS,Datos,Frontal,Trasera,Linterna,Vibrar};

void imprimir(const celular);
void marcarActivo(celular *,int);
void marcarInactivo(celular *,int);
void invertirModulo(celular *,int);
int estaActivo(const celular,int);

int main()
{
    celular celu1,celu2;
    int i;
    for(i=0;i<8;i++){
        marcarActivo(&celu1,i);
        marcarInactivo(&celu2,i);
    }

    printf("Celu1: ");
    imprimir(celu1);
    printf("\nCelu2: ");
    imprimir(celu2);
    printf("\n\n");

    printf("%d\n",estaActivo(celu1,GPS));
    printf("%d\n\n",estaActivo(celu2,GPS));

    marcarActivo(&celu2,Trasera);
    printf("Celu2: ");
    imprimir(celu2);
    printf("\n\n");

    marcarInactivo(&celu1,Wifi);
    printf("Celu1: ");
    imprimir(celu1);
    printf("\n\n");

    invertirModulo(&celu2,Trasera);
    printf("Celu2: ");
    imprimir(celu2);
    printf("\n\n");

    invertirModulo(&celu1,Wifi);
    printf("Celu1: ");
    imprimir(celu1);
    printf("\n\n");

    return 0;
}

void imprimir(const celular c)
{
    printf("%u",c.Bluetooth);
    printf("%u",c.Wifi);
    printf("%u",c.GPS);
    printf("%u",c.Datos);
    printf("%u",c.Frontal);
    printf("%u",c.Trasera);
    printf("%u",c.Linterna);
    printf("%u",c.Vibrar);
}

void marcarActivo(celular *c, int mod){
    switch(mod)
    {
        case 0: c->Bluetooth=1;
        break;
        case 1: c->Wifi=1;
        break;
        case 2: c->GPS=1;
        break;
        case 3: c->Datos=1;
        break;
        case 4: c->Frontal=1;
        break;
        case 5: c->Trasera=1;
        break;
        case 6: c->Linterna=1;
        break;
        default: c->Vibrar=1;
        break;
    }
}

void marcarInactivo(celular *c, int mod){
    switch(mod)
    {
        case 0: c->Bluetooth=0;
        break;
        case 1: c->Wifi=0;
        break;
        case 2: c->GPS=0;
        break;
        case 3: c->Datos=0;
        break;
        case 4: c->Frontal=0;
        break;
        case 5: c->Trasera=0;
        break;
        case 6: c->Linterna=0;
        break;
        default: c->Vibrar=0;
        break;
    }
}

void invertirModulo(celular *c,int mod){
    switch(mod)
    {
        case 0: c->Bluetooth^=1;
        break;
        case 1: c->Wifi^=1;
        break;
        case 2: c->GPS^=1;
        break;
        case 3: c->Datos^=1;
        break;
        case 4: c->Frontal^=1;
        break;
        case 5: c->Trasera^=1;
        break;
        case 6: c->Linterna^=1;
        break;
        default: c->Vibrar^=1;
        break;
    }
}

int estaActivo(const celular c,int mod){
    switch(mod)
    {
        case 0: return c.Bluetooth;
        break;
        case 1: return c.Wifi;
        break;
        case 2: return c.GPS;
        break;
        case 3: return c.Datos;
        break;
        case 4: return c.Frontal;
        break;
        case 5: return c.Trasera;
        break;
        case 6: return c.Linterna;
        break;
        default: return c.Vibrar;
        break;
    }
}

