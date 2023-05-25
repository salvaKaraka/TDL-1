#include <stdio.h>
int main()
{
  struct nodo {
    int valor;
    struct nodo * ptr;
    };

   struct nodo *Pila = NULL, *aux;

  int nro;
  //leer nros. hasta que se ingrese cero
  printf("Ingrese un nro :");
  scanf("%d",&nro);

  while (nro != 0){
      // agregar el nro a la pila
      aux = (struct nodo *) malloc(sizeof(struct nodo));
      aux->valor = nro;
      (*aux).ptr = Pila;
      Pila = aux;
      // leer otro número
      printf("Ingrese un nro :");
      scanf("%d",&nro);
  }

  // recorrer la lista visualizando
  // los valores
  aux=Pila;
  while (aux != NULL) {
      printf("%d\n",(*aux).valor);
      aux = aux->ptr;
  }

  return 0;
}
