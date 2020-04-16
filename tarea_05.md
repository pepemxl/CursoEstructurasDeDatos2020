# Tarea \#5 (Entregar antes de 23/04/2020)
## Curso de Estructura de Datos

- Problema 1. Dado un arreglo que contiene números positivos, en el rango de 0 a `MAX`. Crear una tabla hash que nos permita saber si algún número está presente en la matriz o no en tiempo constante `O(1)`. (Sugerencia usar arreglo `A[MAX+1][1]`)

- Problema 2. Dado un arreglo que contiene números positivos y negativos, en el rango de `-MAX` a `+MAX`. Crear una tabla hash que nos permita saber si algún número está presente en la matriz o no en tiempo constante `O(1)`. (Sugerencia usar arreglo `A[MAX+1][2]`)

- Problema 3. Crear función recursiva que imprima todos los elementos de una lista simplemente ligada.

- Problema 4. ¿Qué hacen la siguiente función suma?
```
double suma(int n) {
    if(n % 2){
        return impar(n);
    }else{
        return par(n);
    }
}

double par(int n) {
    return impar(n-1)-1/double(n);
}

double impar(int n) {
    if(n == 1){
        return 1;
    }
    return par(n-1)+1/double(n);
}
```