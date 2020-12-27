# Repaso de las últimas clases Arboles AVL

|SN|	Rotación|	Descripción|
|---|---|---|
|1|	LL| El nuevo nodo es insertado en el subarbol izquierdo del subarbol izquierdo de un nodo critico.|
|2|	RR| El nuevo nodo es insertado en el subarbol derecho del subarbol derecho de un nodo critico.|
|3|	LR| El nuevo nodo es insertado en el subarbol derecho del subarbol izquierdo de un nodo critico.|
|4|	RL| El nuevo nodo es insertado en el subarbol izquiedo del subarbol derecho de un nodo critico.|

La clase pasada ya vimos como hacer un balanceo cuando tenemos la condición `LL` , `RR` , `LR` y `RL`.

<img width="20%" height="150" src="images/avl_LL.png"/>

<img width="20%" height="150" src="images/avl_RR.png"/>


<img width="20%" height="150" src="images/right_subtree_of_left_subtree.jpg"/>

<img width="20%" height="150" src="images/left_subtree_of_right_subtree.jpg"/>

### Rotación Derecha (`LL`)

![LR](images/avl_right_rotation.jpg)

### Rotación Izquierda (`RR`)

![LR](images/avl_left_rotation.jpg)

### Rotación Izquierda Derecha (`LR`)

<img width="20%" height="200" src="images/right_subtree_of_left_subtree.jpg"/> 
<img width="20%" height="200" src="images/subtree_left_rotation.jpg"/> 
<img width="20%" height="200" src="images/left_unbalanced_tree.jpg"/> 
<img width="20%" height="200" src="images/right_rotation.jpg"/> 

## Rotación Derecha Izquierda (`RL`)

<img width="20%" height="200" src="images/left_subtree_of_right_subtree.jpg"/> 
<img width="20%" height="200" src="images/subtree_right_rotation.jpg"/> 
<img width="20%" height="200" src="images/right_unbalanced_tree.jpg"/> 
<img width="20%" height="200" src="images/left_rotation.jpg"/> 


# Analizar Borrado de nodos

## Rotación `R0` Despues de borrar un nodo, B(nodo a la izquierda del nuevo nodo critico A) tiene factor 0.

Si el nodo B tiene un factor de balance 0, y el factor de balance del nodo A se altera al eliminar el nodo X, entonces el árbol se reequilibrará girando el árbol usando la rotación `R0`.



![R0](images/deletion-in-avl-tree.png)



El nodo crítico A se mueve a su derecha y el nodo B se convierte en la raíz del árbol con T1 como su subárbol izquierdo. Los subárboles T2 y T3 se convierten en el subárbol izquierdo y derecho del nodo A. El proceso involucrado en la rotación `R0` se muestra en la  imagen.


### Ejemplo

Borrar el nodo->30 del árbol AVL que se muestra en la siguiente imagen.


![R0 Ejemplo](images/deletion-in-avl-tree-example.png)

[codigo](codigos/clase_22_practica_01.cpp)

En este caso, el nodo B tiene un factor 0, por lo tanto, el árbol se rotará utilizando la rotación `R0` como se muestra en la siguiente imagen. El nodo B->10 se convierte en la raíz, mientras que el nodo A se mueve a su derecha. El hijo derecho del nodo B ahora se convertirá en el hijo izquierdo del nodo A.

![R0 Ejemplo Solucion](images/deletion-in-avl-tree-solution.png)


## Rotación `R1`  (Después de borrar el nodo, B queda con factor 1 )

La rotación `R1` se debe realizar si el factor del nodo `B` es 1. En la rotación `R1`, el nodo crítico A se mueve hacia la derecha con los subárboles `T2` y `T3` como su hijo izquierdo y derecho respectivamente. `T1` se colocará como el subárbol izquierdo del nodo `B`.

![R1](images/deletion-in-avl-tree-r1-rotation.png)

### Ejemplo
Borrar el `Nodo->55` del árbol AVL que se muestra en la siguiente imagen.

![R1 Ejemplo](images/deletion-in-avl-tree-r1-rotation-example.png)

Eliminar 55 del árbol AVL perturba el factor de balance del nodo 50, es decir, el nodo A que se convierte en el nodo crítico. Esta es la condición de la rotación R1 en la cual, el nodo A se moverá a su derecha (como se muestra en la imagen a continuación). La derecha de B ahora se convierte en la izquierda de A , es decir, 45.

![R1 Ejemplo Solucion](images/deletion-in-avl-tree-r1-rotation-solution.png)

[codigo](codigos/clase_22_practica_02.cpp)


## Rotación `R-1`  (Despues de borrar el nodo, B queda con factor -1 )

La rotación R-1 se realizará si el nodo B tiene un factor de balance -1. Este caso se trata de la misma manera que la rotación LR. En este caso, el nodo C, que es el hijo derecho del nodo B, se convierte en el nodo raíz del árbol con B y A como sus hijos izquierdo y derecho, respectivamente.

Los subárboles T1, T2 se convierten en los subárboles izquierdo y derecho de B, mientras que T3, T4 se convierten en los subárboles izquierdo y derecho de A.


![R-1](images/deletion-in-avl-tree-r-1-rotation.png)


### Ejemplo
Borrar el nodo->60 del árbol AVL que se muestra en la siguiente imagen.



![R-1 Ejemplo](images/deletion-in-avl-tree-example2.png)


en este caso, el nodo B tiene un factor de equilibrio -1. Al eliminar el nodo 60, se altera el factor de equilibrio del nodo 50, por lo tanto, debe rotarse R-1. El nodo C, es decir, 45 se convierte en la raíz del árbol con el nodo B (40) y A (50) como su hijo izquierdo y derecho.


![R-1 Ejemplo Solucion](images/deletion-in-avl-tree-solution2.png)


[codigo](codigos/clase_22_practica_03.cpp)


## Arboles L
### Ejemplo de arbol L-1
```
   50(-1)
   /   \
40(0)   55(-1)
         \
         60(0)
```
Si borramos el nodo->40
```
   50(-2)
       \
       55(-1)
         \
         60(0)
```
Para balancear el arbol hacemos una rotación RR, es decir, una rotación a la izquierda de 50 usando como pivote a 55.

```
       55(0)
      /   \
    50(0)  60(0)
```

## Recordatorio

Mandar descripción básica de su proyecto