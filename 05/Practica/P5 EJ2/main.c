#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arch = fopen("archivo.txt","r");

    int low=0,up=0,dig=0;

    char ch;

    if(!arch){
        printf("Error al abrir el archivo");
        return 1;
    }

    while((ch=fgetc(arch)) != EOF){
        if(isupper(ch)){
            up++;
        }else if(islower(ch)){
            low++;
        }else if(isdigit(ch)){
            dig++;
        }
    }

    if(fclose(arch)){
        printf("error al cerrar el archivo");
        return 1;
    }

    printf("hay %d mayusculas, %d minusculas y %d digitos",up,low,dig);

    return 0;
}
