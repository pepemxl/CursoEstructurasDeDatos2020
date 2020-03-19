# Tarea \#3 (Entregar antes de 26/03/2020)
## Curso de Estructura de Datos

- Problema 1.- Crear una función recursiva que imprima todos los elementos de una lista ligada. Considerar que:
    - Se le pasará la cabeza de la lista.
    - Deberá imprimirlos desde el primer elemento al último elemento. Por ejemplo si la lista ligada es: 1->2->3->4->5->NULL, debera imprimir: 1 2 3 4 5

considerando la siguiente clase base:
```
template <typename T>
struct Node{
    T data;
    Node<T> *next;
};
```

- Problema 2.- Crear una función recursiva que imprima todos los elementos de una lista ligada. Considerar que:
    - Se le pasará la cabeza de la lista.
    - Deberá imprimirlos desde del último elemento al primer elemento. Por ejemplo si la lista ligada es: 1->2->3->4->5->NULL, debera imprimir 5 4 3 2 1

considerando la siguiente clase base:
```
template <typename T>
struct Node{
    T data;
    Node<T> *next;
};
```

- Problema Extra(No Obligatorio): Hacer la sobrecarga del operador `[]` como se discutio en clase para poder accesar a un nodo apartir del nodo cabeza `head`.
