#include <stdio.h>
#include <stdlib.h>

int decaBinR(int n){
    if (n == 0) {
        return 0;
    } else {
        return (n % 2 + 10 * decaBinR(n / 2));
    }
}

int decaBinI(int n){

    return bin;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
