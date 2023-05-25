#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int num;
    int dig;
    int cont[10]={0};

    printf("Ingrese un numero entero:");
    scanf("%ld",&num);

    while(num>0){
        dig= num % 10;
        cont[dig]++;
        num /= 10;
    }

    for (int i=0; i<10; i++){
        printf("%d \t ----> \t %d \n", i, cont[i]);
    }

    return 0;
}
