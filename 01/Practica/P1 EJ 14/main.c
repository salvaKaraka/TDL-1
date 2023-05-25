#include <stdio.h>
#include <stdlib.h>

int invertirDigitos(int n){
    int b=0;

    while (n>0){
        b= b*10 + n % 10;
        n/=10;
    }


    return b;
}

int main()
{
    printf("%d",invertirDigitos(9273));
    return 0;
}
