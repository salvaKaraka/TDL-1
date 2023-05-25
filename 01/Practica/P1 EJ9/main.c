#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char c;


    printf("numero 1:");
    scanf("%d",&a);

    printf("numero 2:");
    scanf(" %d",&b);

    printf("operacion (+,-,x,/):");
    scanf(" %c",&c);

    switch(c){
    case '+': printf("%d + %d=%d",a,b,a+b); break;
    case '-': printf("%d - %d=%d",a,b,a-b); break;
    case 'x': printf("%d x %d=%d",a,b,a*b); break;
    case '/': printf("%d / %d=%f",a,b,(float)a/b); break;
    default: printf("%c no es un operador valido",c);
    }

    return 0;
}
