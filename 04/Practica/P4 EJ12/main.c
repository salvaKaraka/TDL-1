#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=2, y=3;
    int * m= (int*) malloc(x*y*sizeof(int));

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("ingrese un numero en la posicion (%d,%d): ",i,j);
            scanf("%d",m+i*y+j);
        }
    }

    printf("\nMattriz:\n",x,y);

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("[%d]", *(m+i*y+j));
        }
        printf("\n");
    }

    free(m);

    return 0;
}
