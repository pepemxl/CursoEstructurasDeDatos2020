# Exámen (Duración 3 horas)

1. Utilizar/crear una clase stack, para crear una clase gen&eacute;rica que crea un `queue` con un par stacks que deberán crear la siguiente funcionalidad:
    - void enQueue(T x): Que agrega un elemento de tipo `T` a la cola, para ello seguirán los siguientes pasos:
        1. Mientras `stack1` no está vacío, `push` todo elemento de `stack1` a `stack2`.
        2. `push` x en `stack1`.
        3. `push` de todo elemento de `stack2` a `stack1`.
    - T deQueue(): Devuelve el primer elemento de la cola y lo elimina de la misma, para ello seguiran los siguientes pasos:
        - Si `stack1` es vacio entonces impriman error y regrensen `NULL`.
        - `pop` de `stack1` y regresar el valor en la funci&oacute;n.

Menciona que complejidad tiene `enQueue` y `deQueue` y como podrias reducir su complejidad. 

2. Dada una lista simplemente ligada que contiene números enteros con todos sus elementos ordenados en orden creciente, crea un BST Balanceado generico que contenga la misma información que contiene la lista ligada. Para comprobar imprime
    - Los elementos dentro de la lista ligada.
    - El preorden del BST balanceado.
    - El inorden del BST balanceado.
    - El posorden del BST balanceado.

3. Implementa un `priority Queue` utiizando un `heap`.

4. (Problema) https://www.hackerrank.com/challenges/is-binary-search-tree/problem

5. (Problema Bonus) https://www.hackerrank.com/challenges/largest-rectangle/problem 

Evita buscar las soluciones, solo tienes permitido usar el código que tienes en tu repositorio.