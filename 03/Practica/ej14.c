#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DIMF 50

typedef struct{
   unsigned num:4;
   unsigned palo:2;
}carta;

void inicializar(carta[]);
void barajar(carta[],int);
void imprimirMazo(const carta[],int);
carta eliminarCarta(carta[],int *);
void imprimirCarta(const carta);

int main()
{
    srand(time(NULL));

    int dimL=DIMF,i;
    carta mazo[DIMF];

    inicializar(mazo);
    imprimirMazo(mazo,dimL);
    barajar(mazo,dimL);
    printf("\n\n");
    imprimirMazo(mazo,dimL);

    printf("\n\n");
    for(i=0;i<30;i++)
        imprimirCarta(eliminarCarta(mazo,&dimL));
    printf("\n\n");

    imprimirMazo(mazo,dimL);

    return 0;
}

void inicializar(carta m[]){
    int i,j=0;
    for(i=0;i<12;i++){
        m[j].num=i;
        m[j].palo=0;
        j++;
    }
    for(i=0;i<12;i++){
        m[j].num=i;
        m[j].palo=1;
        j++;
    }
    for(i=0;i<12;i++){
        m[j].num=i;
        m[j].palo=2;
        j++;
    }
    for(i=0;i<12;i++){
        m[j].num=i;
        m[j].palo=3;
        j++;
    }
}

void barajar(carta m[],int dimL){
    int i,pos1,pos2;
    carta aux;
    for(i=0;i<50;i++){
        pos1=rand()%dimL;
        pos2=rand()%dimL;
        aux=m[pos1];
        m[pos1]=m[pos2];
        m[pos2]=aux;
    }
}

void imprimirMazo(const carta m[],int dimL){
    int i;
    for(i=0;i<dimL;i++){
        if(m[i].num!=0)
            printf("palo: %u - numero: %u\n",m[i].palo,m[i].num);
    }
}

carta eliminarCarta(carta m[],int * dimL){
    *dimL=*dimL-1;
    return m[*dimL];
}

void imprimirCarta(const carta c){
    printf("palo: %u - numero: %u\n",c.palo,c.num);
}
