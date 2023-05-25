#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=9;
    int m = n/2;

    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){

            if(abs(j-m)+abs(i-m)<=m){
                printf("*");
            }else printf(" ");
        }
        printf("\n");
    }

    return 0;
}
