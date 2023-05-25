#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {Bluetooth=128,Wifi=64,GPS=32,Datos=16,Frontal=8,Trasera=4,Linterna=2,Vibrar=1} modulo;

typedef struct{
    unsigned bits:8;
}celular;

void verBits(unsigned);
void marcarActivo(celular *,modulo);
void marcarInactivo(celular *,modulo);
void invertirModulo(celular *,modulo);
int estaActivo(unsigned,modulo);

int main()
{
    celular celu1,celu2;
    celu1.bits=Bluetooth+Wifi+GPS+Datos+Frontal+Trasera+Linterna+Vibrar;
    celu2.bits=0;

    printf("Celu1: ");
    verBits(celu1.bits);
    printf("Celu2: ");
    verBits(celu2.bits);

    printf("%d\n",estaActivo(celu1.bits,GPS));
    printf("%d\n",estaActivo(celu2.bits,GPS));

    marcarActivo(&celu2,Trasera);
    printf("Celu2: ");
    verBits(celu2.bits);

    marcarInactivo(&celu1,Wifi);
    printf("Celu1: ");
    verBits(celu1.bits);

    invertirModulo(&celu2,Trasera);
    printf("Celu2: ");
    verBits(celu2.bits);

    invertirModulo(&celu1,Wifi);
    printf("Celu1: ");
    verBits(celu1.bits);

    return 0;
}

void verBits(unsigned valor)
{
  unsigned Mascara = 1 << 7;
  int i;
  for (i=1; i <= 8 ; i++){
    putchar( valor & Mascara ? '1' : '0');
    valor = valor << 1;
  }
  putchar('\n');
}

void marcarActivo(celular *c,modulo mod){
    c->bits|=mod;
}

void marcarInactivo(celular *c,modulo mod){
    c->bits&=(~mod);
}

void invertirModulo(celular *c,modulo mod){
    c->bits^=mod;
}

int estaActivo(unsigned c,modulo mod){
    if((c&mod)==mod)
        return 1;
    else
        return 0;
}

