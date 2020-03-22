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

- Problema 3. Utilizar la clase de la tarea \#2 Problema 1, para crear una clase gen&eacute;rica que crea un `queue` con un par stacks que implementamos con listas simplemente ligadas deberán crear la funcionalidad:
    - void enQueue(T x): Que agrega un elemento de tipo `T` a la cola, para ello seguirán los siguientes pasos:
        1. Mientras `stack1` no está vacío, `push` todo elemento de `stack1` a `stack2`.
        2. `push` x en `stack1`.
        3. `push` de todo elemento de `stack2` a `stack1`.
    - T deQueue(): Devuelve el primer elemento de la cola y lo elimina de la misma, para ello seguiran los siguientes pasos:
        - Si `stack1` es vacio entonces impriman error y regrensen `NULL`.
        - `pop` de `stack1` y regresar el valor en la funci&oacute;n.

En resumen el elemento más antiguo estará siempre en la parte superior de la `stack1`, de modo que la operación `deQueue` simplemente sera un pop en el `stack1`. Para colocar el elemento en la parte superior de `stack1`, se utiliza `stack2`.


- Problema 4. Utilizar la clase de la tarea \#2 Problema 1, para crear una clase gen&eacute;rica que crea un `queue` con un par de listas simplemente ligadas deberán crear la funcionalidad:
    - void enQueue(T x): Que agrega un elemento de tipo `T` a la cola, para ello seguirán los siguientes pasos:
        - `push` a stack1.
    - T deQueue(): Devuelve el primer elemento de la cola y lo elimina de la misma, para ello seguiran los siguientes pasos:
        - Si ambos stacks son vacios entonces impriman error y regrensen `NULL`.
        - Si `stack2` es vacio, mientras `stack1` no lo sea mandar cada elemento de `stack1` a `stack2`.
        - `pop` de `stack2` y regresar el valor.

En resumen `enQueue`es una operacion en que cada  nuevo elemento se ingresa en la parte superior de `stack1`. En la operación de `deQueue`, si `stack2` está vacío entonces todos los elementos deberan ser movidos a `stack2` y finalmente se devuelve la parte superior(`top`) de `stack2`.

- Problema Extra(No Obligatorio): Hacer la sobrecarga del operador `[]` como se discutio en clase para poder accesar a un nodo apartir del nodo cabeza `head`.
