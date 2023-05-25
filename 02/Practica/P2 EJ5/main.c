#include <stdio.h>
#include <stdlib.h>
#define DimFH 3
#define DimFV 4

void sumar(int (*A)[DimFH], int (*B)[DimFH], int (*C)[DimFH]){

    for (int i=0; i<DimFV; i++){
        for(int j=0; j<DimFH; j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

int main()
{
    int A[DimFV][DimFH]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int B[DimFV][DimFH]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    int C[DimFV][DimFH]={0};

    sumar(A,B,C);

    for (int i=0; i<DimFV; i++){
        for(int j=0; j<DimFH; j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
