#include <stdio.h>
#include <stdlib.h>

/*El formato de color RGB es el más extendido para uso en imágenes como en displays. Este formato
utiliza 3 componentes (Red, Green, Blue) de 8 bits para codificar un píxel de color, requiriendo 3 bytes
o 24 bits de memoria. Hace muchos años cuando surgieron los primeros teléfonos a color se utilizó un
formato RGB reducido a 2 bytes o 16 bits (Red:5 bits, Green:6 bits, Blue: 5 bits) para reducir el espacio
de almacenamiento y mejorar las velocidades de transferencia. Actualmente en el ámbito de los
microcontroladores estos displays siguen siendo utilizados. Teniendo en cuenta lo anterior
implemente un programa que:
a. Defina el tipo RGB24 y RGB16 de forma eficiente.
b. Implemente 2 funciones de conversión de un formato a otro y viceversa.*/

typedef struct {
    unsigned int Red;
    unsigned int Green;
    unsigned int Blue;
}RGB24;

typedef struct {
    unsigned int Red:5;
    unsigned int Green:6;
    unsigned int Blue:5;
}RGB16;

void verBits( unsigned );
void conversion(RGB24* ,RGB16);
void conversion2(RGB16*, RGB24);
int main()
{
    RGB24 colorG={255,255,255};
    RGB24 colorGAux={127,127,127};

    RGB16 colorC={31,63,31};
    RGB16 colorCAux={15,31,15};

    printf("Es rojizo:");
    verBits(colorG.Red);
    printf("Es AZulado:");
    verBits(colorG.Blue);
    printf("Es Green:");
    verBits(colorG.Green);

    conversion(&colorG,colorCAux);

    printf("Es rojizo:");
    verBits(colorG.Red);
    printf("Es AZulado:");
    verBits(colorG.Blue);
    printf("Es Green:");
    verBits(colorG.Green);

    printf("\n");

    printf("Es rojizo:");
    verBits(colorC.Red);
    printf("Es AZulado:");
    verBits(colorC.Blue);
    printf("Es Green:");
    verBits(colorC.Green);

    conversion2(&colorC,colorGAux);

    printf("Es rojizo:");
    verBits(colorC.Red);
    printf("Es AZulado:");
    verBits(colorC.Blue);
    printf("Es Green:");
    verBits(colorC.Green);

    return 0;
}
void conversion(RGB24 *colorG,RGB16 colorC){
    colorG->Blue=((colorC.Blue*255)/31);
    colorG->Green=((colorC.Green*255)/63);
    colorG->Red=((colorC.Red*255)/31);

}

void conversion2(RGB16 *colorC,RGB24 colorG){
    colorC->Blue=((colorG.Blue*31)/255);
    colorC->Green=((colorG.Green*63)/255);
    colorC->Red=((colorG.Red*31)/255);

}
void verBits(unsigned valor)
{
  unsigned Mascara = 1 << 31;

  printf("%10u = ", valor);
int i;
  for ( i=1; i <= 32 ; i++){
    putchar( valor & Mascara ? '1' : '0');
    valor = valor << 1;

    if (i % 8 == 0)
        putchar(' ');
  }
  putchar('\n');
}
