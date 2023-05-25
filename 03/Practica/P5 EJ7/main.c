#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    char apellido[50];
    char esDni;
    union{
        long int DNI;
        char pasaporte[50];
    }documento;
}estudiante;

void cargarEstudiante(estudiante *est);
void imprimirEstudiante(estudiante est);

int main()
{
    estudiante est;
    cargarEstudiante(&est);
    imprimirEstudiante(est);
    return 0;
}

void imprimirEstudiante(estudiante est){
    printf("nombre \t apellido \t documento \n");
    if (est.esDni == 0)  printf("%s \t %s \t %ld",est.nombre, est.apellido, est.documento.DNI);
    else if (est.esDni == 1)printf("%s \t %s \t %s",est.nombre, est.apellido, est.documento.pasaporte);
    else printf("error");

};

void cargarEstudiante(estudiante *est){

    printf("ingrese el nombre: ");
    scanf("%s", est->nombre);

    printf("ingrese el apellido: ");
    scanf("%s", est->apellido);

    loop:

    printf("ingrese el tipo documento (0:DNI, 1:pasaporte): ");
    scanf("%d", &(est->esDni));

    switch (est->esDni){
        case 0:
                printf("ingrese el DNI: ");
                scanf("%ld", &(est->documento.DNI));
        break;
        case 1:
                printf("ingrese el DNI: ");
                scanf("%s", est->documento.pasaporte);
        break;
        default: printf("tipo no valido \n");
        goto loop;
        break;
    }

};
