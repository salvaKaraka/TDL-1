#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f = fopen("../Practica-5---Recursos/precipitaciones.txt","r");

    if(!f){
        printf("error al abrir el archivo");
        return 1;
    }

    int p;
    int max_p = -1;
    int max_d;

    for(int i=1; i<32; i++){
        fscanf(f,"%d-",&p);
        printf("%d\n",p);
        if (p>max_p){
            max_p=p;
            max_d=i;
        }
    }

    if(fclose(f)){
        printf("error al cerrar archivo");
        return 1
    }

    printf("el dia com mayor precipitacion fue el %d con %d c^3",max_d,max_p);

    return 0;
}
