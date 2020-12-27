# Sesión 07

## Queue (Colas)

Una queue (cola) o FIFO (first in, first out) es un tipo de dato abstracto que sirve como una colecci&oacute;n de elementos, que tiene dos operaciones b&aacute;sicas:
- enqueue:  Agregar un elemento a la colecci&oacute;n por la parte final.
- dequeue: Remover el elemento del inicio.

![queue](images/queue.png)

Al igual que el stack se puede implementar ya sea usando arreglos o listas ligadas. Con la unica diferencia de que insertamos al final de la lista ligada. Como  pueden imaginarse la implementaci&oacute;n es muy parecida. 

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

Vamos a hacerla como ejercicio en lo que queda de la clase.

## Implementación de Queue usando un arreglo

![QueueArray](images/array-representation-of-queue.png)

Usaremos un arreglo linear para llevar a cabo la implementación de la cola. Para ello definieremos dos variables, `front` y `rear`.
- Inicialmente `front` y `rear` es -1. Esto quiere decir que la cola es vacia.
- Cuando insertamos un valor por primera vez incrementamos tanto el valor de front como el de rear en una unidad y asignamos el valor en esta posición.
- Si `front` y `rear >= 0` entonces cuando insertamos un valor incrementamos `rear` asignamos el valor en esta posición.
- Cuando hacemos un `pop` retornamos el valor en la posicion `front` e incrementamos `front` en una unidad.

Dependiendo de su uso podrian usar memoria estatica o memoria dinamica, por el momento usaremos memoria dinamica, dejaré en una tarea posterior implementar esta estructura usando memoria estatica.
```
template <typename T>
class CQueue{
public:
    CQueue();
    CQueue(int iMax);
    CQueue(int iMax, T *tArray, int nArray);
    ~CQueue();
    bool Push(const T &val);
    T Pop();
    T Print();
private:
    T *m_array;
    int m_iMax;
    int m_iFront;
    int m_iRear;
};

template <typename T>
void CQueue<T>::CQueue(){
    m_iMax = 100;
    m_iFront = -1;
    m_iRear = -1;
    m_array = new T[m_iMax];
}

template <typename T>
void CQueue<T>::~CQueue(){
    delete []m_array;
}
```

### Limitaciones de está implementación

![Waste](images/limitation-array-representation-of-queue.png)

- Desperdicio de memoria
- Tamaño del arreglo

## Implementación de Queue usando un listas ligadas

![Queue](images/linked-list-implementation-of-queue.png)

- Inicialmente `front` y `rear` son apuntadores que apuntan a `NULL`. Esto quiere decir que la cola es vacia.
- Cuando insertamos un valor por primera vez asignamos el valor del apuntador tanto `front` como a `rear`.
- Si `front` y `rear` son no nulos entonces cuando insertamos un valor, lo hacemos haciendo que `rear` apunte a un nuevo nodo con ese valor y actualizamos al dirreción de `rear`.
- Cuando hacemos un `pop` retornamos el valor en la posicion `front` y apuntamos `front` a `front->next`

Desarrollen el resto de la clase dicha implementación.


# Priority Queue

Priority Queue(cola de prioridad) es una extensión de la queue(cola) con las siguientes propiedades:

1. Cada elemento tiene una prioridad asociada.
2. Un elemento con prioridad alta se quita de la cola antes que un elemento con prioridad baja.
3. Si dos elementos tienen la misma prioridad, se sirven según su orden en la cola.

Según la prioridad del elemento, los elementos se organizan en una cola de prioridad. Si los elementos ocurren con la misma prioridad, entonces se sirven de acuerdo con el principio FIFO.

Una cola de prioridad típica admite las siguientes operaciones:

- insert(item, priority): Inserta un elemento con prioridad dada.
- getHighestPriority(): Devuelve el elemento de mayor prioridad.
- deleteHighestPriority(): Elimina el elemento de mayor prioridad.


## Implementación

Usando una estructura auxiliar 
```
struct item {
   int item;
   int priority;
}
```

tenemos dos mmaneras sencillas de implementar colas de prioridad:

- Usando un arreglo
- Usando un heap(monticulo)


### Usando un Arreglo

- `insert()` La operación se puede implementar agregando un elemento al final de la matriz en tiempo `O(1)`.
- `getHighestPriority()` La operación se puede implementar buscando linealmente el elemento de mayor prioridad en la matriz. Esta operación lleva tiempo `O(n)`.
- `deleteHighestPriority()` La operación se puede implementar buscando primero un elemento linealmente, luego quitando el elemento moviendo todos los elementos subsiguientes una posición hacia atrás.

También podemos usar la lista ligada, la complejidad del tiempo de todas las operaciones con la lista vinculada sigue siendo la misma que la matriz. La ventaja de la lista ligada es que la función `deleteHighestPriority()` puede ser implementada de manera más eficiente ya que no tenemos que mover elementos.

### Usando Heaps

Esta opción es la preferida para la implementación de la cola de prioridad porque los heaps proporcionan un mejor rendimiento en comparación con las matrices o la listas ligadas. En un heap binario, `getHighestPriority()` se puede implementar en tiempo `O(1)`, `insert()` se puede implementar en tiempo `O(Logn)` y `deleteHighestPriority()` también se puede implementar en tiempo `O(Logn)`.
Con el heap de Fibonacci, `insert()` y `getHighestPriority()` se pueden implementar en `O(1)` tiempo amortizado y `deleteHighestPriority()` se puede implementar en `O(Logn)` tiempo amortizado.



# Binary Heap

Un binary heap es un arbol binario que cumple las siguientes propiedades:

1. Es un árbol completo (todos los niveles están completamente llenos excepto posiblemente el último nivel y el último nivel tiene todos los noldos a la izquierda). Esta propiedad de Binary Heap los hace adecuados para ser almacenados en una matriz.

2. Un heap binario es Min Heap o Max Heap. En un Heap binario mínimo, la clave/llave/nodo en la raíz debe ser de valor mínimo entre todas las claves/llaves/nodos presentes en el heap binario. La misma propiedad debe ser verdadera de forma recursiva para todos los nodos del árbol binario. Max Binary Heap es similar a MinHeap, pero ahora es el valor maximo.


