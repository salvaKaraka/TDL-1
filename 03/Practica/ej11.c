#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned int seg:5;
    unsigned int min:6;
    unsigned int hora:5;

}horario;

void leerHorario(horario*);
void imprimirHorario(const horario);

int main()
{
    horario h1;
    printf("%d\n",sizeof(h1));
    leerHorario(&h1);
    imprimirHorario(h1);
    return 0;
}

void leerHorario(horario *h1){
    unsigned int horaAux,minAux,segAux;
    printf("Ingrese la hora\n");
    scanf("%d",&horaAux);
    h1->hora=horaAux;
    printf("Ingrese el minuto\n");
    scanf("%d",&minAux);
    h1->min=minAux;
    printf("Ingrese los segundos\n");
    scanf("%d",&segAux);
    h1->seg=(segAux/2);
}

void imprimirHorario(const horario h1){
    printf("El horario es %d:%d:%d",h1.hora,h1.min,(h1.seg)*2);
}
