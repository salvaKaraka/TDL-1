#include <stdio.h>
#include <stdlib.h>

void inicializarMatriz(int*** matriz, int n, int m){

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("ingrese el numero en la posicion (%d,%d):",i,j);
            scanf("%d",(*(*matriz+i)+j));
        }
    }
}

int** crearMatiz(int n, int m){

    int** matriz = (int**) malloc(n*sizeof(int*));

    for(int i=0; i<n; i++){
        matriz[i] = (int*) malloc(m*sizeof(int));
    }

    return matriz;
}

void imprimirMatriz(int** matriz, int n, int m){
    if(matriz!=NULL){
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                printf("[%d]",matriz[i][j]);
            }
            printf("\n");
        }
    }else printf("matriz vacia");
}

void imprimirMultiplosDe3(int** matriz, int n, int m){
    if(matriz!=NULL){
        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(matriz[i][j]%3 == 0){
                    printf("[%d]",matriz[i][j]);
                }else{
                    printf("[ ]");
                }

            }
            printf("\n");
        }
    }else printf("matriz vacia");
}

void liberarMemoria(int*** matriz, int n, int m){
    for(int i=0; i<n; i++){
        free((*matriz)[i]);
    }
    free(*matriz);
    *matriz=NULL;
}

int main()
{
    int n,m;

    printf("ingrese n:");
    scanf("%d",&n);

    printf("ingrese m:");
    scanf("%d",&m);

    int** matriz = crearMatiz(n,m);

    inicializarMatriz(&matriz, n, m);

    imprimirMatriz(matriz, n, m);

    imprimirMultiplosDe3(matriz, n, m);

    liberarMemoria(&matriz, n, m);

    imprimirMatriz(matriz, n, m);

    return 0;
}
