# Sesión 14 
## Arbol de Busqueda Binaria (Continuación)


## Borrado de nodos en arboles de busqueda binaria

Tenemos tres casos que debemos analizar al momento de borrar un nodo de un arbol de busqueda binaria, de tal manera que el arbol resultante siga siendo un arbol de busqueda binaria.

### Borrar un nodo que es de hecho una hoja del arbol.

Para hacer esto basta con hacer null este nodo(el apuntador a este nodo se hace nulo, y se libera la memoria de dicho nodo).
Consideremos el arbol generado al insertar
`{43, 10, 79, 90, 12, 54, 11, 9, 50}`

![borrado1](images/binary-search-tree-02.png)

Ahorra borraremos los nodos `90` y `9` que son nodos hojas.

Para ello creamos una nueva funcion `Search` que nos dira en que nodo esta el valor que buscamos y quien es su nodo padre.

```
template <typename T>
Node<T> *Search(Node<T> *root, const T &val, Node<T> * &parentNode) {
    Node<T> *currentNode = root;
    Node<T> *tempNode = NULL;
    while(currentNode != NULL && currentNode->data != val){
        tempNode = currentNode;
        if(currentNode->data > val){
            currentNode = currentNode->left;
        }else{
            currentNode = currentNode->right;
        }
    }
    if(currentNode != NULL){
        parentNode = tempNode;
        return currentNode;
    }else{
        return NULL;
    }
}
``` 
![borrado1](images/binary-search-tree-03.png)

[implementacion caso 1](codigos/clase_13_practica_02.cpp)


### Borrado de un nodo con un solo nodo hijo

- En este caso remplazamos el valor del nodo con el valor de su nodo hijo, y reasignamos apuntadores para que el nodo izquierdo del padre apunte al nodo izquierdo del hijo y el nodo derecho del padre apunte al nodo derecho del hijo, entonces estamos listos para borrar el nodo hijo.


![borrado2](images/binary-search-tree-04.png)


### Borrado de un nodo con dos nodos hijos

El nodo que será borrado es remplazado con su inorden sucesor o predecesor de manera recursiva, hasta que el nodo se convierte en un nodo hijo donde dicho nodo es remplazado con un apuntador nulo(`NULL`) y se libera la memoria de dicho nodo.

En el ejemplo, el nodo 79 será borrado. Su recorrido inorden es:

`9 10 11 12 43 50 54 79 90`

remplazamos 79 con su sucedor en este recorrido inorden(90).
Ahora 50 es una hoja del arbol que sabemos como borrar.

![borrado3](images/binary-search-tree-05.png)


## Ejercicios

- Implementar versión recursiva de funcion `Search `

`Node<T> *Search(Node<T> *root, const T &val, Node<T> * &parentNode)`

- Implementar versión recursiva de funcion `Delete `

`Node<T> *Delete(Node<T> *root, const T &val)`

