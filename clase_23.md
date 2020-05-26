# Practica de Arboles

## Ejercicio 1
Crear una función que reciba la raiz de un arbol binario y que imprima lo que se conoce como `level order traversal` que se traduce como recorrido de orden por nivel, esto es, visitamos todos los nodos por nivel de izquierda a derecha.

Por ejemplo el reccorido por nivel del siguiente arbol:
```
     1
      \
       2
        \
         5
        /  \
       3    6
        \
         4 
```
es `1 -> 2 -> 5 -> 3 -> 6 -> 4`.

La estructura de la función seria:
```
template <typename T>
void levelOrder(Node<T> * root) {

}
```

Vamos a darles 25 minutos para resolverlo.

[solucion](codigos/clase_22_practica_04.cpp)

## Ejercicio 2

Binary Search Tree : Lowest Common Ancestor
Dado un BST y dos nodos de este arbol el encontrar el `Lowest Common Ancestor`, es decir, el nodo ancestro común más cercano a ambos nodos.

Dicho de otra manera, dado un arbol de busqueda binaria y dos valores `data1` y `data2` de dicho arbol, crear una función que encuentre el primer ancestro que sea común a ambos nodos(nodo padre o padre del padre o ....).

```
template <typename T>
Node *LowestCommonAncestor(Node<T> *root, int v1,int v2) {
     // Write your code here.
}

```
Ejemplo: `{4, 2, 1, 3, 7, 6}`

![ejemplo](images/LCASample_01.png)


Vamos a darles 25 minutos para resolverlo.

[solucion](codigos/clase_22_practica_05.cpp)