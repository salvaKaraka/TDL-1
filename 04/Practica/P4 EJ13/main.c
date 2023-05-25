#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=2, y=3;

    int size= x*y;

    int * m= (int*) malloc(size*sizeof(int));

    for(int i=0; i<size; i++){
        int row=i / y;
        int col=i % y;

        printf("ingrese un numero en la posicion (%d,%d): ",row,col);
        scanf("%d",m+i);
    }

    printf("\nMattriz:\n",x,y);

    for (int i = 0; i < size; i++) {
        int row = i / y;
        int col = i % y;
        printf("[%d]", m[i]);
        if (col == y - 1) {
            printf("\n");
        }
    }

    free(m);

    return 0;
}
