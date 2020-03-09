# Estructuras de Datos

## Estructras de datos lineales (Continuaci&oacute;n...)

## Stack (Pila)

Un stack o LIFO (last in, first out) es un tipo de dato abstracto que sirve como una colecci&oacute;n de elementos, que tiene dos operaciones.
- `push` agrega un elemento a la colecci&oacute;n .
- `pop` remueve el &uacute;ltimo elemento que fue agregado.

Ambas operaciones traajan sobre el mismo elemento que es el que se encuentra al final y mas arriba en el stack (pila).

Para implementar una pila podemos utilizar tanto un arreglo como una lista ligada.

### Complejidad de los stacks
Inserci&oacute;n : `O(1)`
Borrado :  `O(1)`
Acceso : `O(n)` [Peor de los casos]
Tanto la inserci&oacute;n como el borrado solo se permiten al final.

Uno de los usos m&aacute;s comunes de los stacks es para remover recursiones de un programa. Si recuerdan como funciona una recursi&oacute;n el &uacute;ltimo programa en ser llamado deber ser el primero en terminar. 

## Queue (Colas)

Una queue (cola) o FIFO (first in, first out) es un tipo de dato abstracto que sirve como una colecci&oacute;n de elementos, que tiene dos operaciones:
- enqueue:  Agregar un elemento a la colecci&oacute;n por la parte final.
- dequeue: Remover el elemento del inicio.

Al igual que el stack se puede implementar ya sea usando arreglos o listas ligadas.

### Complejidad
Insercion : `O(1)`
Borrado  : `O(1)`
Acceso : `O(n)` [En el peor de los casos]

Ejemplos:
- Filas de atenci&oacute;n a clientes
- Manejo de recurss del sistema
- El caso particular de colas circulares es para evitar desperdiciar memoria.
