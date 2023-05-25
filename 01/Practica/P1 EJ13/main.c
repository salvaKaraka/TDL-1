#include <stdio.h>
#include <stdlib.h>

int esPrimo(int n){

    int c=0,i=1;

    while((i<n) && (c<2)){
        if (n%i == 0){
            c++;
        }
        i++;
    }

    if (c==1)
        return 1;
    else
        return 0;
}

int main()
{
    int n,p=0;

    while(p<5){
        printf("ingrese un numero entero:");
        scanf("%d",&n);

        if(esPrimo(n)==1){
            printf("%d es un numero primo\n",n);
            p++;
        } else printf("%d no es un numero primo\n",n);
    }

    return 0;
}


