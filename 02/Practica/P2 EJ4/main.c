#include <stdio.h>
#include <stdlib.h>
#define DimFH 3
#define DimFV 4

void transponer(int (*matriz)[DimFH], int (*matriz_transpuesta)[DimFV]){

    for (int i=0; i<DimFV; i++){
        for(int j=0; j<DimFH; j++){
            matriz_transpuesta[j][i]=matriz[i][j];
        }
    }
}

int main()
{
    int matriz[DimFV][DimFH]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int matriz_transpuesta[DimFH][DimFV];

    transponer(matriz,matriz_transpuesta);

    for (int i=0; i<DimFH; i++){
        for(int j=0; j<DimFV; j++){
            printf("%d ",matriz_transpuesta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
