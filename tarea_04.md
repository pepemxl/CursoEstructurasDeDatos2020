# Tarea \#4 (Entregar antes de 02/04/2020)
## Curso de Estructura de Datos

- Problema 1. Utilizar la clase de la tarea \#2 Problema 1, para crear una clase gen&eacute;rica que crea un `queue` con un par stacks que implementamos con listas simplemente ligadas deberán crear la funcionalidad:
    - void enQueue(T x): Que agrega un elemento de tipo `T` a la cola, para ello seguirán los siguientes pasos:
        1. Mientras `stack1` no está vacío, `push` todo elemento de `stack1` a `stack2`.
        2. `push` x en `stack1`.
        3. `push` de todo elemento de `stack2` a `stack1`.
    - T deQueue(): Devuelve el primer elemento de la cola y lo elimina de la misma, para ello seguiran los siguientes pasos:
        - Si `stack1` es vacio entonces impriman error y regrensen `NULL`.
        - `pop` de `stack1` y regresar el valor en la funci&oacute;n.

En resumen el elemento más antiguo estará siempre en la parte superior de la `stack1`, de modo que la operación `deQueue` simplemente sera un pop en el `stack1`. Para colocar el elemento en la parte superior de `stack1`, se utiliza `stack2`.


- Problema 2. Utilizar la clase de la tarea \#2 Problema 1, para crear una clase gen&eacute;rica que crea un `queue` con un par de listas simplemente ligadas deberán crear la funcionalidad:
    - void enQueue(T x): Que agrega un elemento de tipo `T` a la cola, para ello seguirán los siguientes pasos:
        - `push` a stack1.
    - T deQueue(): Devuelve el primer elemento de la cola y lo elimina de la misma, para ello seguiran los siguientes pasos:
        - Si ambos stacks son vacios entonces impriman error y regrensen `NULL`.
        - Si `stack2` es vacio, mientras `stack1` no lo sea mandar cada elemento de `stack1` a `stack2`.
        - `pop` de `stack2` y regresar el valor.

En resumen `enQueue`es una operacion en que cada  nuevo elemento se ingresa en la parte superior de `stack1`. En la operación de `deQueue`, si `stack2` está vacío entonces todos los elementos deberan ser movidos a `stack2` y finalmente se devuelve la parte superior(`top`) de `stack2`.

- Problema 3. Implementar la clase generica `Queue` considerando la estructura
```
template <typename T>
struct Node { 
    T data; 
    Node* next; 
    Node(T &val) { 
        data = val; 
        next = NULL; 
    } 
}; 
```
consideraremos que tiene dos apuntadores
```
template <typename T>
class CQueue{ 
    Node<T> *front;
    Node<T> *rear; 
    CQueue() 
    { 
        front = rear = NULL; 
    }
    void enQueue(T x);
} 
```
implementar `enQueue` y `deQueue`.
- Problema 4. Implementar una clase `Array` usando una lista ligada simple.
    - Implementar constructor que reciba el número de elementos.
    - Deberá contener una variable `int size` que contendrá el número máximo de elementos que puede contener.
    - Un metodo de asignación de valores:
        - `Set(int posicion, int valor)` 
        - Si la posición es mayor que size o negativa deberá enviar error.
    - Un metodo de obtención de valores:
        - `Get(int posicion)` 
        - Si la posición es mayor que size o negativa deberá enviar error.