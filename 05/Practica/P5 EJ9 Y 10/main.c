/*9
1-Lea información de 20 jugadores de tenis. De cada jugador se lee nombre y apellido,
edad, cantidad de títulos, ranking actual y fortuna acumulada.
2-Defina una estructura de datos adecuada para la información y almacene la misma en un archivo binario. 
3- procese los datos almacenados en el archivo e informe:
a) Nombre y apellido del jugador con mejor ranking.
b) Nombre y apellido del jugador que más títulos ha ganado.
*/

/*10
Utilizando el archivo binario generado en el ejercicio anterior:
escriba una función que permita actualizar el ranking de un jugador. Dicha función recibe como
parámetros nombre, apellido y nuevo ranking del jugador y retorna 1 si pudo realizar la
modificación y 0 en caso contrario.
*/

#include <stdio.h>
#include <stdlib.h>

#define CANT 2

typedef struct jugador {
    char nombre[20];
    char apellido[20];
    int edad;
    int titulos;
    int ranking;
    float fortuna;
} jugador;

void cargarJugadores(jugador** j, int n);
void almacenarInformacion(jugador* j, int n);
void calcularMejores(jugador* mr, jugador* mt);

int actualizarRanking(char* nombre, char* apellido, int nuevoRanking) {
    FILE* data;
    data = fopen("jugadores.dat", "rb+");
    if (data == NULL) {
        printf("Error al leer el archivo de datos");
        return 0;
    }

    jugador actual;

    while (fread(&actual, sizeof(jugador), 1, data) == 1) {
        if (strcmp(actual.nombre, nombre) == 0 && strcmp(actual.apellido, apellido) == 0) {
            actual.ranking = nuevoRanking;
            fseek(data, -sizeof(jugador), SEEK_CUR);
            fwrite(&actual, sizeof(jugador), 1, data);
            fclose(data);
            return 1;
        }
    }

    fclose(data);
    return 0;
}

int main() {
    jugador* jugadores = malloc(sizeof(jugador) * CANT);

    cargarJugadores(&jugadores, CANT);
    almacenarInformacion(jugadores, CANT);

    jugador mejorRanking;
    mejorRanking.ranking = 0;
    jugador masTitulos;
    masTitulos.titulos = 0;

    char nombre[20]="salva";
    char apellido[20]="karaka";

    actualizarRanking(nombre, apellido,9999);

    calcularMejores(&mejorRanking, &masTitulos);

    printf("\tNombre\t\tApellido\n");
    printf("Mejor ranking:\t%s\t%s\n", mejorRanking.nombre, mejorRanking.apellido);
    printf("Más títulos:\t%s\t%s\n", masTitulos.nombre, masTitulos.apellido);

    free(jugadores);

    return 0;
}

void cargarJugadores(jugador** j, int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingrese el nombre del jugador %d: ", i + 1);
        scanf("%s", (*j)[i].nombre);
        printf("Ingrese el apellido del jugador %d: ", i + 1);
        scanf("%s", (*j)[i].apellido);
        printf("Ingrese la edad del jugador %d: ", i + 1);
        scanf("%d", &((*j)[i].edad));
        printf("Ingrese la cantidad de títulos del jugador %d: ", i + 1);
        scanf("%d", &((*j)[i].titulos));
        printf("Ingrese el ranking del jugador %d: ", i + 1);
        scanf("%d", &((*j)[i].ranking));
        printf("Ingrese la fortuna del jugador %d: ", i + 1);
        scanf("%f", &((*j)[i].fortuna));
    }
}

void almacenarInformacion(jugador* j, int n) {
    FILE* data;
    data = fopen("jugadores.dat", "wb");
    if (data == NULL) {
        printf("Error al crear el archivo de datos");
        return;
    }

    fwrite(j, sizeof(jugador), n, data);

    fclose(data);
}

void calcularMejores(jugador* mr, jugador* mt) {
    FILE* data;
    data = fopen("jugadores.dat", "rb");
    if (data == NULL) {
        printf("Error al leer el archivo de datos");
        return;
    }

    jugador actual;

    while (fread(&actual, sizeof(jugador), 1, data) == 1) {
        if (actual.ranking > mr->ranking) {
            *mr = actual;
        }
        if (actual.titulos > mt->titulos) {
            *mt = actual;
        }
    }

    fclose(data);
}




