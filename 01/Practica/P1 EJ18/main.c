#include <stdio.h>
#include <stdlib.h>

void randomNumbers(){
    for(int i=1; i<=15 ; i++){
        printf("%d\n",rand());
    }
}

int main()
{
    srand(time(NULL));
    randomNumbers();

    return 0;
}
