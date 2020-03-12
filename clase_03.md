# Estructuras de Datos

## Preliminares (Parte de su curso de algoritmos, por lo cual solo será un breve recordatorio/introducción)
### Análisis asintótico de  un algoritmo
En el análisis matemático, el análisis asintótico de un algoritmo es un método/manera de definir el límite matemático del rendimiento en tiempo de ejecución de un algoritmo. Con esto podemos considerar los siguientes tres casos/escenarios:
- caso promedio de un algoritmo,
- el mejor caso de un algoritmo y por último
- el peor caso de un algoritmo.

Se utiliza para calcular matemáticamente el tiempo de ejecución de cualquier operación dentro de un algoritmo.

### Notaciones asintóticas
Las anotaciones asintóticas comúnmente utilizadas para calcular la complejidad del tiempo de ejecución de un algoritmo son:

- Big oh (Ο)
- Omega (Ω)
- Theta (θ)

### Big oh  (O)
Es la forma formal de expresar el límite superior del tiempo de ejecución de un algoritmo. Mide el peor caso de complejidad de tiempo o la mayor cantidad de tiempo que el algoritmo tarda en completar su operación.

### Omega (&Omega;)
Es la forma formal de representar el límite inferior del tiempo de ejecución de un algoritmo. Mide la menor cantidad de tiempo que un algoritmo puede tardar en completarse o la mejor complejidad de tiempo del caso.

### Theta (&Theta;)
Es la forma formal de expresar tanto el límite superior como el límite inferior del tiempo de ejecución de un algoritmo.

## Estructras de datos lineales (Continuaci&oacute;n...)

## Listas Ligadas (Sesión de práctica)

Abrir un nuevo proyecto de codebocks y copiar contenido del ejercicio [ejercicio 03](./codigos/clase_02_ejercicio_03.cpp)

Como pueden ver es el último ejercicio de la clase pasada, la única diferencia es que está implementado con plantillas.

El día de hoy agregaremos la siguiente funcionalidad:
- inserción al inicio: `PushFront(head, val)`
- inserción de nodo en posición arbitraria: `Insert(head, val)`
- borrar nodo al inicio y retornar valor dentro de nodo: `PopFront(head)`
- borrar nodo al final y retornar valor dentro de nodo: `PopBack(head)`
- borrar nodo en posicion arbitraria: `Delete(head, pos)`
- crear función que regrese nodo en posición( si la posición excede el número de elemntos en la lista ligada deberá regresar `NULL`): `Position(head, pos)`
- crear función para buscar la primer ocurrencia de un valor `val` dentro de la lista ligada: `Search(head, val)`
- crear constructor en estructura nodo que imprima "Nodo Creado"
- crear destructor en estructura nodo que imprima "Nodo Borrado"
- sobrecargar operador `[]` para acceder directamente a un nodo por posición
- sobrecargar operador `<<` para poder imprimir el contenido dentro de la estructura nodo.




