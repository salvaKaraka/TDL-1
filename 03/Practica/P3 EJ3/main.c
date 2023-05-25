#include <stdio.h>
#include <stdlib.h>

#define DimF1 50
#define DimF2 40
#define DimF3 30
#define DimF4 8

typedef struct dir{
    char calle[DimF1];
    char ciudad[DimF3];
    int codigo_postal;
    char pais[DimF2];
}direccion;

typedef struct alu{
    char apellido[DimF1];
    char nombre[DimF1];
    char legajo[DimF4];
    float promedio;
    direccion domicilio;
} alumno;

void cargarAlumno(alumno *a);
void cargarDireccion(direccion *d);

int main()
{
    alumno alumnos[DimF3];

    float max_prom = -1;
    char max_nom[DimF1]={};
    char max_ap[DimF1]={};

    for(int i=0; i<DimF3; i++){
        cargarAlumno(&alumnos[i]);
        if(alumnos[i].promedio>max_prom){
            max_prom=alumnos[i].promedio;
            strcpy(max_nom,alumnos[i].nombre);
            strcpy(max_ap,alumnos[i].apellido);
        }
    }

    printf("Nombre: \t %s \n Apellido: \t %s",max_nom,max_ap);

    return 0;
}

void cargarDireccion(direccion *d){

    printf("Ingrese su calle:");
    scanf("%s",&d->calle);

    printf("Ingrese su ciudad:");
    scanf("%s",&d->ciudad);

    printf("Ingrese su codigo postal:");
    scanf("%d",&d->codigo_postal);

    printf("Ingrese su pais:");
    scanf("%s",&d->pais);

}

void cargarAlumno(alumno *a){

    printf("Ingrese su apellido:");
    scanf("%s",&a->apellido);

    printf("Ingrese su nombre:");
    scanf("%s",&a->nombre);

    printf("Ingrese su legajo:");
    scanf("%s",&a->legajo);

    printf("Ingrese su promedio:");
    scanf("%f",&a->promedio);

    cargarDireccion(&a->domicilio);
}
