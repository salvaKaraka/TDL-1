#include <stdio.h>
int main()
{
    struct Persona{
        char nombre[30];
        int edad;
    };

    struct Persona X;

    strcpy(X.nombre,"Alguien");
    X.edad = 24;

    printf("%s tiene %d a�os",
           X.nombre, X.edad);
    return 0;
}
