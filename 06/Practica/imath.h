/*
a.  int potencia(int x, int y) – Eleva x a la y-ésima potencia. 
b.  int cuadrado(int x) – Eleva x al cuadrado. 
c.  int cubo(int x) – Eleva x al cubo. 
d.  int absoluto(int i) – Retorna el valor absoluto entero de i. 
e.  int factorial (int i) – Retorna el factorial de i. 
f.  int sumatoria (int i) – Retorna la sumatoria de 0 hasta i. 
g.  int multiplo (int x, int y)  – Retorna  1 si y es divisor de x, 0 en otro 
caso. 
h.  int divisor (int x, int y) – Retorna 1 si y es múltiplo de x, 0 en otro 
caso. 
i.  int par (int i) – Retorna 1 si i es par, 0 en otro caso. 
j.  int impar (int i) – Retorna 1 si i es impar, 0 en otro caso.
*/
#ifndef IMATH_H_INCLUDED
#define IMATH_H_INCLUDED

int potencia(int x, int y){
    int i, potencia = 1;
    for(i = 0; i < y; i++){
        potencia *= x;
    }
    return potencia;
}

int cuadrado(int x){
    return potencia(x, 2);
}

int cubo(int x){
    return potencia(x, 3);
}

int absoluto(int i){
    if(i < 0){
        return i * -1;
    }
    return i;
}

int factorial(int i){
    int j, factorial = 1;
    for(j = 1; j <= i; j++){
        factorial *= j;
    }
    return factorial;
}

int sumatoria(int i){
    int j, sumatoria = 0;
    for(j = 0; j <= i; j++){
        sumatoria += j;
    }
    return sumatoria;
}

int multiplo(int x, int y){
    if(x % y == 0){
        return 1;
    }
    return 0;
}

int divisor(int x, int y){
    if(y % x == 0){
        return 1;
    }
    return 0;
}

int par(int i){
    if(i % 2 == 0){
        return 1;
    }
    return 0;
}

int impar(int i){
    if(i % 2 != 0){
        return 1;
    }
    return 0;
}

#endif // IMATH_H_INCLUDED

// Path: Practica\imath.c