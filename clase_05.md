# Estructuras de Datos

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
