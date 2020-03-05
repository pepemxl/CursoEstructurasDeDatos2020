# Plantillas
Las plantillas(templates en ingles) en C++ nos permiten trabajar funciones y clases con tipos de datos gen&eacute;ricos.
Esto nos permite que una funci&oacute;n/clase trabaje con muchos tipos de datos distintos sin tener que reescribir la funci&oacute;n/clase de nuevo.

## Tres tipos de plantillas
- plantillas de funci&oacute;n
- plantillas de clase
- plantillas de variables(apartir de c++14)

### Plantillas de funci&oacute;n
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


# Ejercicios de clase

- Crear una funci&oacute;n llamada swap para intercambiar el valor de dos variables.
- Crear un buble sort para ordernar cualesquiera dos
n&uacute;mero usando templates.
- Crear una clase Array usando templates
    - Debera contener un constructor al cual se le pasar&aacute;n dos par&aacute;metros:
        - el primero un arreglo de n&uacute;meros.
        - el segundo el tamaño del arreglo


