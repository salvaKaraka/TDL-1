#include <stdio.h>
#include <stdlib.h>

int factorialIterativo(int n){
    int f=1;

    for (int i=1; i<=n; i++){
        f*=i;
    }

    return f;
}

int factorialRecursivo(int n){
    int f=1;

    if(n==1)
        return 1;
    else
        return n * factorialRecursivo(n-1);
}

int main()
{
    printf("%d\n",factorialIterativo(5));
    printf("%d",factorialRecursivo(4));
    return 0;
}
