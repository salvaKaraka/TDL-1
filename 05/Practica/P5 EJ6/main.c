/*Un archivo csv (Comma Separated Values) contiene información separada por comas. Cada renglón 
(fila) contiene un registro de información. Cada columna contiene un campo particular de 
información. La primera fila es especial ya que contiene los nombres de los campos.
Se desea obtener información a partir del archivo llamado vinos.csv (el cual se encuentra en la 
Sección “Ing. Gral. y Contenidos” del curso de la cátedra en WebUNLP). El programa debe generar 
un archivo de texto con un resumen que indique el valor máximo, mínimo y promedio para cada 
uno de los campos del archivo. Este archivo debe llamarse reporte_vinos.txt y debe guardarse en la 
misma ruta que el archivo vinos.csv.*/

#include <stdlib.h>
#include <stdio.h>
#define LONG 300

int main() {
    FILE * f = fopen("vinos.csv", "r");
    FILE * n = fopen("reporte_vinos.txt", "a");
    if (f == NULL || n == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    float* prom = (float*)calloc(8, sizeof(float));
    float* max = (float*)calloc(8, sizeof(float));
    float* min = (float*)calloc(8, sizeof(float));
    min[0] = min[1] = min[2] = min[3] = min[4] = min[5] = min[6] = min[7] =99999;
    
    float* actual = (float*)malloc(8* sizeof(float));
    char* line = (char*)malloc(LONG* sizeof(char));
    int tot = 0;


    fgets(line, LONG, f);
    while (fscanf(f, "%f;%f;%f;%f;%f;%f;%f;%f;%s", &actual[0], &actual[1], &actual[2], &actual[3], &actual[4], &actual[5], &actual[6], &actual[7], line) == 9) {
        for (int i = 0; i < 8; i++) {
            if (actual[i] > max[i]) max[i] = actual[i];
            if (actual[i] < min[i]) min[i] = actual[i];
            prom[i] += actual[i];
        }
        tot++;
        printf("Vino %s\n", line); // marca de fin de procesamiento de vino
    }

    for(int i = 0; i < 8; i++) prom[i] /= tot;

    fprintf(n, "Atributo  |\t Acidez Fija\t Acidez Volatil\t Acido Citrico\t Azucares Residuales\t PH   \t Sulfatos\t Alcohol\t Calidad\n");
    fprintf(n, "Promedio  |\t %.2f       \t %.2f          \t %.2f         \t %.2f               \t %.2f  \t %.2f    \t %.2f  \t %.2f  \n", prom[0], prom[1], prom[2], prom[3], prom[4], prom[5], prom[6], prom[7]);
    fprintf(n, "Maximos   |\t %.2f       \t %.2f          \t %.2f         \t %.2f               \t %.2f  \t %.2f    \t %.2f  \t %.2f  \n", max[0], max[1], max[2], max[3], max[4], max[5], max[6], max[7]);
    fprintf(n, "Minimos   |\t %.2f       \t %.2f          \t %.2f         \t %.2f               \t %.2f  \t %.2f    \t %.2f  \t %.2f  \n", min[0], min[1], min[2], min[3], min[4], min[5], min[6], min[7]);
    
    free(prom);
    free(max);
    free(min);
    free(actual);
    free(line);

    fclose(n);
    fclose(f);
    return 0;
}