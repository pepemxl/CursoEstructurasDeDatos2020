# Usar árboles BSP para generar mapas de juego
Al rellenar un área al azar con objetos, como habitaciones en una mazmorra aleatoria, se corre el riesgo de hacer las cosas demasiado al azar, lo que resulta en una aglomeración que resulta poco utilizable. 

Hay que hacer un objeto Leaf, que usaremos para dividir un área en pequeños segmentos; luego generar una habitación aleatoria en cada Leaf y finalmente  conectar todas las salas con pasillos.

## ¿Qué es BSP? 
El Particionamiento Binario del Espacio (Binary Space Partitioning) es un método de dividir un área en piezas más pequeñas.

Básicamente, tomas un área, llamada Leaf(hoja), y la divides ya sea vertical u horizontalmente, en dos hojas más pequeñas, y luego repite el proceso en las áreas más pequeñas una y otra vez hasta que cada área sea al menos tan pequeña como un conjunto máximo valor.

Nuestra Leaf va a ser un Rectángulo, cada Leaf contendrá un par de Leafs para niños, o un par de Rooms, así como un pasillo o dos.

```
Class CLeaf{
    Leaf *left;
    Leaf *right;
    Rectangle room;
    Vector halls;
    CLeaf(int _x, int _y,int _width, int _height){
        x = _x;
        y = _y;
        width = _width;
        height = _height;
    }
    split();//funcion para dividir hojas
}
```