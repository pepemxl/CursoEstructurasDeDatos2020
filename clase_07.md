# Sesión 07

## Queue (Colas) (Continuación)

Una queue (cola) o FIFO (first in, first out) es un tipo de dato abstracto que sirve como una colecci&oacute;n de elementos, que tiene dos operaciones b&aacute;sicas:
- enqueue:  Agregar un elemento a la colecci&oacute;n por la parte final.
- dequeue: Remover el elemento del inicio.

![queue](images/queue.png)

Al igual que el stack se puede implementar ya sea usando arreglos o listas ligadas. Con la unica diferencia de que insertamos al final de la lista ligada. Como  pueden imaginarse la implementaci&oacute;n es muy parecida. 

Vamos a hacerla como ejercicio en lo que queda de la clase.

### Complejidad
Insercion : `O(1)`

Borrado  : `O(1)`

Acceso : `O(n)` [En el peor de los casos]

Ejemplos:
- Filas de atenci&oacute;n a clientes
- Manejo de recursos del sistema:
    - impresores
    - CPU
    - discos
- transferencia de datos(de manera asincrona, i.e. paginado)
- buffers son implementados con queue
- El caso particular de colas circulares es para evitar desperdiciar memoria.

