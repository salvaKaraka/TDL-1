#include <stdio.h>
#include <stdlib.h>

int damePar(){
    static int ultimoPar = 0;
    int par = ultimoPar;
    ultimoPar += 2;
    return par;
}

int main()
{
    int n;
    printf("cantidad de numeros pares:");
    scanf("%d",&n);

    for(int i=0; i<n ; i++){
        printf("%d\n",damePar());
    }

    return 0;
}
