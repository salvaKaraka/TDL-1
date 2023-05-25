#include <stdio.h>
#include <stdlib.h>

void generarSuma(int *resultado){
    int a = rand()%101;
    int b = rand()%101;

    *resultado=a+b;

    printf("%d + %d =", a, b);
}

char calcularNota(int p){
    switch(p){
        case 0: return ('E');
        case 1: return ('D');
        case 2: return ('C');
        case 3: return ('B');
        case 4: return ('A');
        default: printf("error"); break;
    }

    return '\0';
}



int main()
{
    srand(time(NULL));

    int resultado,respuesta,puntos=0;
    char nota='\0';

    for(int i=0; i<4; i++){
        generarSuma(&resultado);
        scanf("%d",&respuesta);
        if (respuesta==resultado)
            puntos++;
    }

    nota=calcularNota(puntos);

    printf("Su nota es: %c\n",nota);
    return 0;
}
