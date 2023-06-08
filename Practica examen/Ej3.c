#include <stdio.h>
#define npares(n1,n2) ((((n1)%2) + ((n2)%2)) == 0) ? 2 : (((((n1)%2) + ((n2)%2)) == 1)?1:0)

int main()
{ int i;
 printf("cantidad de pares:%d",npares(4,4));
 return(0);
}