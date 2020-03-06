# Plantillas
Las plantillas(templates en ingles) en C++ nos permiten trabajar funciones y clases con tipos de datos gen&eacute;ricos.
Esto nos permite que una funci&oacute;n/clase trabaje con muchos tipos de datos distintos sin tener que reescribir la funci&oacute;n/clase de nuevo. 

## Como se crean funciones/clases gen&eacute;ricas
La forma de lograr esto es pasar el tipo de datos a usar como par&aacute;metros dentro de nuestras funciones/clases. C++ agrego un par de keywords para lograr esto `template` y `typename`.

## Como trabajan las plantillas(templates)
Las plantillas son expandidas/creadas en tiempo de compilación, al igual que las macros. Solo que en lugar de sustituir/crear partes de código como ocurre con las macros, aqui  se generán nuevas versiones de código objeto que corresponden con las instancias de nuestra plantilla para disntintos tipos de datos.

## Tres tipos de plantillas
- plantillas de funci&oacute;n
- plantillas de clase
- plantillas de variables(apartir de c++14)

### Plantillas de funci&oacute;n
Las plantillas de función nos permiten escribir funciones genéricas que pueden ser usadas con distintos tipos de datos. Uno de los ejemplos más relevantes es vector de la librería estandar STL, siendo una librería de contenedores creados con plantillas que con la misma sintaxis nos permite usar cualquier tipo de dato en este contenedor

```
std::vector<int> myVector;
std::vector<float> myVector;
std::vector<std::string> myVector;
...
```
#### Declaración de plantillas

```
template <class identifier> function_declaration;
template <typename identifier> function_declaration;
```

Nota: Ambas funcionan exactamente igual.

```
#include <iostream>

template <typename T>
inline T max(T a, T b) {
    return a > b ? a : b;
}

int main(){
    std::cout << max(3, 7) << std::endl;
    std::cout << max(3.0, 7.0) << std::endl;
    std::cout << max<double>(3,7.0);
    std::cout << max(3, 7.0) << std::endl;
    std::cout << max<double>(3, 7.0) << std::endl;
    std::cout << max<char>('g', 'e') << std::endl;
    return 0;
}
```

### Plantillas de clase

Una plantilla de clase nos permite generar clases basadas en parametros. Estas clases han sido bastamente utilizadas en la libreria STL para generar contenedores genericos. 
```
std::vector<double> myvector;
```

### Plantillas de variable
```
template<typename T> constexpr T pi = T(3.141592653589793238462643383L);
```

Nota: El especificador ```constexpr```  aparecio apartir de c++11 y le dice al compilador que la variable será  determinada en
tiempo de compilaci&oacute;n. Su uso es para decirle al compilador que se trata de una declaraci&oacute;n al estilo ```inline```, lo cual aumenta el performance, sin embargo vuelve m&aacute;s lenta la compilaci&oacute;n. (Revisar referencias para conocer mejor su uso, tiene ciertas condiciones especiales que dependen de la versi&oacute;n de C++.)

## NOTAS Adicionales
- Cuando una función debe trabajar esencialemnte distinto para distintos tipos de datos, es cuando usamos sobrecarga de funciones, de lo contrario
utilizamos plantillas.
- Al utilizar plantillas recordar que si tenemos un variable estatica dentro de una clase, cada instancia de la plantilla contendra su propia variable estatica.
- Si necesitamos un comportmiento específico para cierto tipo de dato, podemos crear una especialización de la plantilla.
- A l igual que las funciones podemos no pasar un parámetro a la plantilla, esto por lo regular es para poder especificar valores o constantes dentro de alguna instancia de la plantilla, solo recuerda que debe ser un valor constante al momento de instanciar o te marcara un error por que no podrá determinar cual es su código objeto al momento de compilación, podemos decir que en algún sentido es una manera de usar macros dentro de nuestro template, por ejemplo:
```
#include <stdio.h>
template <typename T, int parameter_01> 
int fun(T a) { 
   int m = parameter_01; 
   return a*m;
}
int main(int argc, charg *argv[]){
    printf("%d\n", fun<int, 5>(5));
    // lo siguienteno comilará
    int i = 5;
    printf("%d\n", fun<int, i>(5));
    return 0;
}
```


## Ejercicios de clase

- Crear una funci&oacute;n llamada swap para intercambiar el valor de dos variables.
- Crear un buble sort para ordernar cualesquiera dos
n&uacute;mero usando templates.
- Crear una clase Array usando templates
    - Debera contener un constructor al cual se le pasar&aacute;n dos par&aacute;metros:
        - el primero un arreglo de n&uacute;meros.
        - el segundo el tamaño del arreglo


