#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));

    printf("ingrese n:");
    int n;
    scanf("%d",&n);

    int** matrizTriangular = (int**)malloc(n*sizeof(int*));

    for(int i=0; i<n; i++){
        *(matrizTriangular+i)=(int*) malloc((i+1)*sizeof(int));
    } 

    for(int i = 0; i<n; i++){
        for(int j=0; j<=i; j++){
            matrizTriangular[i][j] = rand()%20;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j=0; j<=i; j++){
            printf("%d\t",matrizTriangular[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i<n; i++){
        free(matrizTriangular+i);
    }

    free(matrizTriangular);
}
