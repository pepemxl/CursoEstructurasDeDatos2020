# Tarea \#2 (Entregar antes de 19/03/2020)
## Curso de Estructura de Datos

- Problema 1.- Crear una clase gen&eacute;rica para crear un stack con listas simplemente ligadas, que tendr&aacute; los siguientes m&eacute;todos:
    - Contructor (Inicializa la lista con un elemento head)
    - PushBack (Inserta elemento al final)
    - PushFront (Inserta elemento al inicio)
    - Clear (Limpia/borra todos los elementos)
    - Insert (Recibe un par&aacute;metro que le indica en que posici&oacute;n debe insertarse)
    - Remove (Recibe un par&aacute;metro que le indica en que posici&oacute;n debe borrarse)
    - PopBack (Regresa el elemento al final y lo elimina)
    - PopFront (Regresa el elemento al inicio y lo elimina)
    - Destructor ( Borra todos los elementos y libbera memoria de head, en caso de ser elemento especial).
    - Lenght (Regresa un entero que nos dice el n&uacute;mero actual de elementos en el stack).

considerando la siguiente clase base:
```
template <typename T>
class stack{
    int currentNumberOfElements;
    Node<T> *head;
};
```
- Problema 2.- Crear una clase gen&eacute;rica para crear stacks con listas doblemente ligadas, que tendr&aacute; los siguientes m&eacute;todos:
    - Contructor (Inicializa el stack con elemento head)
    - PushBack (Inserta elemento al final)
    - PushFront (Inserta elemento al inicio)
    - Clear (Limpia/borra todos los elementos)
    - Insert (Recibe un par&aacute;metro que le indica en que posici&oacute;n debe insertarse)
    - Remove (Recibe un par&aacute;metro que le indica en que posici&oacute;n debe borrarse)
    - PopBack (Regresa el elemento al final y lo elimina)
    - PopFront (Regresa el elemento al inicio y lo elimina)
    - Destructor ( Borra todos los elementos y libbera memoria de head, en caso de ser elemento especial).
    - Lenght (Regresa un entero que nos dice el n&uacute;mero actual de elementos en el stack).

considerando la siguiente clase base:
```
template <typename T>
class stack{
    int currentNumberOfElements;
    Node<T> *head;
    Node<T> *tail;
};
```