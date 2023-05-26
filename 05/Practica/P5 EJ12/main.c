/*
personas.csv contine la informacion de las personas
personas.idx contiene la posicion de cada persona en el archivo personas.csv ordenadas por dni obtenida con ftell(personas)
b) Realice un programa que muestre en pantalla toda la información de una persona a través de un
DNI ingresado por teclado. Si la persona no existe deberá informar el error.
Tenga en cuenta para la implementación:
• Utilizar una estructura de datos adecuada que permita tener el índice completamente en
memoria.
• Implemente para la búsqueda una función que realice una búsqueda dicotómica.
• Implemente el siguiente prototipo para la función de búsqueda:
int buscar(FILE* personas, Indice indice, int dni, persona * persona)
donde:
• personas es el descriptor del archivo “personas.csv”
• indice es la estructura de datos con la información del archivo “personas.idx”.
• dni es el nro de dni de la persona a buscar
• persona es una estructura con los datos con la información asociada al dni de la
persona.
• El valor de retorno es 0 sino encuentra a la persona y 1 en caso contrario.
c) Reimplemente b) para utilizar en la función de búsqueda el descriptor del archivo índice. Además
modifique el valor de retorno para reflejar la cantidad de veces que se accedió al disco durante la
búsqueda en caso de que lo encuentre. El prototipo de la función de búsqueda quedaría:
int buscar(FILE* personas, FILE* indice, int dni, persona * persona)
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100


typedef short int bool;

typedef struct Indice{
    int dni;
    long int pos;
} Indice;
typedef struct Persona{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    char correo[30];
    char ciudad[20];
    char pais[20];
    char trabajo[20];
} persona;

int cargarIndice(FILE* indice, Indice** ind){
    int i = 0;
    *ind = (Indice*)malloc(sizeof(Indice));

    while (fread(&(*ind)[i], sizeof(Indice), 1, indice) != 0) {
        (*ind) = (Indice*)realloc(*ind, sizeof(Indice) * (i + 2));
        i++;
    }

    return i;
}

int buscar(FILE* personas, Indice* ind, int dni, persona* p, int cantidad){
    int i = 0;
    int j = cantidad - 1;
    int m;
    char linea[MAX];

    while (i <= j) {
        m = (i + j) / 2;
        if (ind[m].dni == dni) { 
            fseek(personas, ind[m].pos, SEEK_SET);
            fgets(linea, MAX, personas);
            sscanf(linea, "%d;%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", &p->id, &p->dni, p->nombre, p->apellido, p->correo, p->ciudad, p->pais, p->trabajo);
            return 1;
        } else if (ind[m].dni > dni) {
            j = m - 1;
        } else {
            i = m + 1;
        }
    }
    return 0;
}

int main(){
    FILE* personas, * indice;
    personas = fopen("personas.csv", "r");
    indice = fopen("personas.idx", "rb");

    if (personas == NULL || indice == NULL){
        printf("Error al abrir los archivos");
        return 1;
    }

    Indice* ind = NULL;
    int cantidad = cargarIndice(indice, &ind);

    fclose(indice);

    int dni;
    printf("Ingrese el dni de la persona a buscar: ");
    scanf("%d", &dni);

    persona p;
    if(buscar(personas, ind, dni, &p, cantidad) == 0){
        printf("No se encontró a la persona");
    } else {
        printf("Nombre: %s\n", p.nombre);
        printf("Apellido: %s\n", p.apellido);
        printf("Correo: %s\n", p.correo);
        printf("Ciudad: %s\n", p.ciudad);
        printf("Pais: %s\n", p.pais);
        printf("Trabajo: %s\n", p.trabajo);
    }

    fclose(personas);
    free(ind);

    return 0;
}