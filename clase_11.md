# Sesión 11

## Arbol Binario

Un árbol binario es aquel en el que cada elemento apunta a otros 2 elementos, comúnmente llamados hijo izquierdo y hijo derecho (que podrían o no ser nulos).

## Arbol  Binario de Busqueda

Un árbol binario de buqueda normalmente llamado **ABB**, es un árbol binario en el cual para todo elemento, los elementos mayores a él, se ubican en su rama derecha, mientras que los elementos menores van en su rama izquierda. Cada elemento se almacena una sola vez por lo que no existen elementos repetidos(pueden llegar a existir pero entonces hay que definir un par de operaciones extras).


Cada elemento(nodo) de un árbol ABB cuenta con tres campos:
- Variable `data`, donde guardamos un dato que puede ser número, letra, string, ....
- Puntero al nodo derecho usualmente llamado `right` 
- Puntero al nodo izquierdo usualmente llamado `left`

Por ejemplo:

```
template<typename T>
struct Node{
    T data;
    Node *right;
    Node *left;
};
```

Al igual que en las listas ligadas, estos punteros son variables que guardarán en la memoria la dirección de otra variable en este caso la de una estructura llamado `Node`.


## Recorridos de árboles

Los punteros son variables que guardaran en la memoria la dirección de otra variable en este caso la de una estructura llamado nodo.

- Inorden: Visitamos primero hijo izquierdo, luego el padre y finalmente el hijo derecho.
- Preorden: Visitamos el padre, luego el hijo izquierdo y finalmente el hijo derecho.
- Postorden: Visitamos al hijo izquierdo, luego el hijo derecho y finalmente el padre
