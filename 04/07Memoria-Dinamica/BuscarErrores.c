#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double *pd;
    int i;

    pd[0] = 1.2;
    pd[1] = 5.6;

    for (i=0; i<3; i++){
       printf("%d  %g\n", i, *pd);
       pd++;
    }

    free(pd);
    return(0);
}
