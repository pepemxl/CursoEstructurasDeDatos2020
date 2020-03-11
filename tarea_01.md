# Tarea \#1 (Entregar antes de 12/03/2020)
## Curso de Estructura de Datos


- Problema 1.- Crear una funciones genéricas para sumar, restar, multiplicar y dividir.
- Problema 2.- Crear una clase que contenga dos atributos de distintos tipos.
    - Crear constructor para inicializar ambos valores al momento de crear la instancia.
    - Crear metodo para cambiar su valor `Set`.
    - Crear metodo para obtener su valor `Get`.
- Problema 3.- Crear una clase que llamaremos `Array`, este deber&aacute; cumplir con lo siguientes puntos:
    - Deberá crear un arreglo dinámico de tipo genérico(usar templates para generar un arreglo que pueda ser de cualquier tipo) .
    - Contendrá dos elementos privados:
        - un apuntador para guardar el arreglo
        - un entero que contendrá el número actual de elementos del arreglo
    - Debera tener dos maneras de instanciarse:
        - la primera será pasandole un arreglo estatico y un entero que será el número de elementos en el arreglo estatico.
        - la segunda será solo pasar el número de elementos que podrá contener
    - Un metodo para imprimir todos los elementos dentro del arreglo.
    - El destructor deberá liberar la memoria dinámicamente.
- Problema 4.- ¿Explicar el funcionamiento del siguiente código?
```
#include <stdio.h>

template<int n>
struct fun {
    enum { val = fun<n-1>::val + fun<n-2>::val};
};

template<> 
struct fun<0> { 
    enum { val = 1 }; 
};

template<> 
struct fun<1> { 
    enum { val = 1 }; 
};

int main(int argc, char *argv[]){
    printf("%d ",fun<0>::val);
    printf("%d ",fun<1>::val);
    printf("%d ",fun<2>::val);
    printf("%d ",fun<3>::val);
    printf("%d ",fun<4>::val);
    printf("%d ",fun<5>::val);
    printf("%d ",fun<6>::val);
    printf("%d ",fun<7>::val);
    printf("%d ",fun<8>::val);
    printf("%d",fun<9>::val);
    return 0; 
} 
```
