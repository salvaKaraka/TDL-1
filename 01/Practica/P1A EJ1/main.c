/* Escriba un programa que lea información relativa a la cantidad de especies de aves de 14 países
de América. De cada país se lee el código de país y la cantidad de especies. Informar los 2 países
con menor cantidad de especies. Además, se desea saber qué porcentaje de países tienen más de
40 especies.*/

#include <stdio.h>
#include <stdlib.h>

const int DimL = 14;

struct pais{
    int codigo;
    int especies;
};

void cargarArreglo(struct pais *paises){

    int codigo, especies;

    for (int i=0; i<DimL; i++){
        printf("codigo del pais %d:\n",i+1);
        scanf(" %d",&codigo);
        printf("cantidad de especies del pais %d\n",i+1);
        scanf(" %d",&especies);
        paises[i].codigo=codigo;
        paises[i].especies=especies;
    }
}

void imprimirArreglo(struct pais paises[DimL]){

    printf("Paises: \t");
    for (int i=1; i<DimL+1; i++){
        printf("%d \t", i);
    }

    printf("\nCodigo: \t");
    for (int i=0; i<DimL; i++){
        printf("%d \t", paises[i].codigo);
    }

    printf("\nEspecies: \t");
    for (int i=0; i<DimL; i++){
        printf("%d \t", paises[i].especies);
    }

}

void analizarDatos(struct pais paises[DimL], struct pais *min, struct pais *min2, float *per){
    int cant = 0;
    min->especies = 99999;
    min2->especies = 99999;

    for (int i = 0; i<DimL; i++){
            if (paises[i].especies < min->especies){
                *min2=*min;
                *min=paises[i];
            } else if (paises[i].especies < min2->especies){
                *min2=paises[i];
            }
            if(paises[i].especies > 40) cant++;
    }

    *per = ((float)cant/DimL)*100;

}

int main()
{
    struct pais min, min2;
    float per;
    struct pais paises[DimL];

    cargarArreglo(&paises);
    imprimirArreglo(paises);
    analizarDatos(paises,&min,&min2,&per);

    printf("\nMenos Especies: %d", min.especies);
    printf("\nSegundo menos Especies: %d", min2.especies);
    printf("\n%.2f porciento de los paises tienen mas de 40 especies", per);

    return 0;
}
