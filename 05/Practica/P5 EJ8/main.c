/*
1- lea desde teclado números enteros de una cifra (del 0 al 9)
2- cree dos archivos, los cuales almacenen los números leídos. El primer archivo debe llamarse “numeros.txt” y
contener en formato texto todos los números leídos en forma consecutiva. 
El segundo archivo debe llamarse “numeros.dat” y contener todos los números leídos en formato binario.
3- responda:
▪ Una vez ejecutado el programa, utilice un editor de texto (como por ejemplo: el Bloc de notas
en MS Windows, o Gedit en GNU/Linux) para abrir el archivo de texto y corroborar que la
información almacenada sea la correcta. Usando el mismo editor, intente abrir el archivo
binario. ¿Es posible visualizar los números? ¿Por qué cree que no es posible?

no es posible visualizar los numeros porque el archivo binario no es legible para el usuario, solo para la computadora.

▪ Compare los tamaños que ocupan cada archivo. ¿Cuál es más grande? ¿En qué ocasiones
cree usted que sería mejor utilizar cada tipo de archivos?

el archivo de texto es significativamente mas pesado que el archivo binario, por lo que es mejor utilizar el archivo de texto 
cuando se quiere que el usuario pueda leer el archivo, y el archivo binario cuando solo se quiere que la computadora pueda leer el archivo.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fTxt, *fBin;
    int* num=(int*)malloc(sizeof(int));

    fTxt = fopen("numeros.txt", "wt");
    fBin = fopen("numeros.dat", "wb");

    if (fTxt == NULL || fBin == NULL)
    {
        printf("Error al abrir los archivos");
        exit(1);
    }

    printf("Ingrese un numero del 1 al 9: ");
    scanf("%d", num);

    while (*num >= 0 && *num <= 9)
    {
        fprintf(fTxt, "%d", *num);
        fwrite(num, sizeof(int), 1, fBin);
        printf("Ingrese un numero del 1 al 9: ");
        scanf("%d", num);
    }

    fclose(fTxt);
    fclose(fBin);

    return 0;
}