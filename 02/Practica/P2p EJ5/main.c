#include <stdio.h>
#include <stdlib.h>

#define DimF 7

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invertir(int *V) {
    int j=DimF-1;
    for(int i=0; i<j; i++){
        swap((V+i), (V+j));
        j--;
    }
}

int main()
{
    int V[DimF]={1,2,3,4,5,6,7};

    invertir(V);

    for (int i=0; i<DimF; i++){
        printf("%d \t", V[i]);
    }

    return 0;
}
