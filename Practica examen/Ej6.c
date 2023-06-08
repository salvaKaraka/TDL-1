#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc==1){
        printf("ERROR");
        return -1;
    }

    char* cadena =  malloc(100);

    strcpy(cadena, argv[1]);

    for (int i=2; i<argc; i++){
        strcat(cadena, " ");
        strcat(cadena,argv[i]);
    }

    printf("cadena: %s", cadena);

    return 0;
}