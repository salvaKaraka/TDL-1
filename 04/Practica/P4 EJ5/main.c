#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char *string = (char*) malloc(100 * sizeof(char));

    int minus, mayus;

    for (int i = 0; i<10; i++){
        printf("escriba una oracion:");
        gets(string);

        minus = 0;
        mayus = 0;

        for(int j=0; string[j]!='\0'; j++){
            if (islower(string[j])) minus++;
            else if (isupper(string[j])) mayus++;
        }

        printf("cadena: %s\n", string);
        printf("minusculas:%d \n mayusculas:%d \n", minus, mayus);
    }
    free(string);
    return 0;
}
