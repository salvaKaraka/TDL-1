#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    double *pd;
    int i;

    pd = (double*) malloc(3*sizeof(double));

    pd[0] = 1.2;
    *(pd+1) = 5.6;
    pd[2] = 0.33;

    for (i=0; i<3; i++)
       printf("%d  %g\n", i, pd[i]);

    free(pd);
    return(0);
}
