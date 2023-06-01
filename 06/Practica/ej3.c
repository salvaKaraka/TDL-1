/*a.  Investigue  las  funciones  de  conversión  de  texto  a  número  y  escriba  un  programa
“calculadora.c”  que reciba dos números enteros y un operador como argumentos
a la función main e imprima en pantalla el resultado  de  la  operación.
El operador  debe  ser:  “+”, “-”, “/”, “.”. Si el operador recibido no es uno de los 
mencionados anteriormente, entonces el programa debe imprimir un mensaje de error.  
b. Utilice una terminal para compilar el programa a través de la línea de comandos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 4){
        printf("cantidad de argumentos incorrecta");
        return -1;
    }

    int resultado;
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[3]);


    if (strcmp(argv[2],"+")==0){
        resultado = num1 + num2;
    } else if (strcmp(argv[2],"-")==0){
        resultado = num1 - num2;
    } else if (strcmp(argv[2],"/")==0){
        resultado = num1 / num2;
    } else if (strcmp(argv[2],".")==0){
        resultado = num1 * num2;
    } else {
        printf("operador incorrecto");
        return -1;
        }

    printf("resultado:%d",resultado);
    return 0;
}