#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct destino {
 int codProv;
 int codLoc;
 char nomLoc[30];
 int nHab;
};

int main(){
    FILE *destinos = fopen("habitantes.txt","r");
    if(destinos == NULL){
        printf("error al abrir el archivo");
        return -1;
    }

    FILE* destinosBIN = fopen("destinosBIN.dat","wb+");
    if (destinosBIN == NULL) {
        printf("Error al abrir el archivo de destinoBIN.\n");
        return -1;
    }

    struct destino* destino = (struct destino*)malloc(sizeof(struct destino));
    int CP, CL, NH;
    char* NOM = malloc(30*sizeof(char));

    while(fscanf(destinos,"%d %d %s %d", &CP, &CL, NOM, &NH)==4){
        destino->codProv=CP;
        destino->codLoc=CL;
        strcpy(destino->nomLoc,NOM);
        destino->nHab=NH;

        fwrite(destino, sizeof(struct destino), 1, destinosBIN);
    }

    struct destino masHab;
    masHab.nHab=-1;

    rewind(destinosBIN);

    while(fread(destino,sizeof(struct destino),1,destinosBIN)==1){
        if (destino->nHab > masHab.nHab)masHab=*destino;
    }
    
    printf("mas habitantes:%d\n",masHab.nHab);
    printf("localidad:%s",masHab.nomLoc);

    free(destino);
    free(NOM);
    if(fclose(destinos) || fclose(destinosBIN)) 
        printf("error al cerrar archivo(s)");

    return 0;
}