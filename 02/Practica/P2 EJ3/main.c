#include <stdio.h>
#include <stdlib.h>
#define DimFH 3
#define DimFV 2

void multiplicar(int (*matriz)[DimFH], int c){

    for (int i=0; i<DimFV; i++){
        for(int j=0; j<DimFH; j++){
            matriz[i][j]*=2;
        }
    }

}

int main()
{
    int matriz[DimFV][DimFH]={{1,2,3},{4,5,6}};
    int c=2;

    multiplicar(matriz, c);

    for (int i=0; i<DimFV; i++){
        for(int j=0; j<DimFH; j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
