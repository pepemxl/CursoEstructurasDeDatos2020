# Sesión 17

## Codificación de Huffman (continuación)

Esta clase completaremos la implementación funcional de codificación/compresión de Huffman adaptable.

La clase pasada implementamos una simple segmentación de una cadena de carfacteres en cadenas que representan 8 bits.

```
vector<string> segmenta_cadena(char *buffer, int length){
    vector <string> myvector;
    string buffer2="";
    for(int i = 0; i < length-1 ;++i){
        if(i > 0 && i%8 == 0){
            myvector.push_back(buffer2);
            buffer2="";
        }
        buffer2 += buffer[i];
    }
    if(buffer2.size()>0){
        for(int i = buffer2.size(); i < 8;i++){
            buffer2 += '0';
        }
        myvector.push_back(buffer2);
    }
    return myvector;
}
```
Después implementamos  Big Endian apartir de estas cadenas de 8 bits para encontrar el caracters/entero asociado a cada subcadena. Esta no es una implementación optima pero servira.
```
char convierte_cadena_8bits_to_char(char *buffer){
    int n = 0;
    int potencia = 1;
    for(int i = 0; i < 8;++i){
        if(buffer[i] == '1'){
            n += potencia;
        }
        potencia *= 2;
    }
    return char(n);
}
```
Un par de cambios nos deja realizar la conversión de las mismas cadenas cosiderando little endian.
```
char convierte_cadena_8bits_to_char_le(char *buffer){
    int n = 0;
    int potencia = 1;
    for(int i = 7; i >= 0;--i){
        if(buffer[i] == '1'){
            n += potencia;
        }
        potencia *= 2;
    }
    return char(n);
}
```

Ahora continuemos con la implementación:

[Implementación](codigos/clase_17_practica_00.cpp)

Con esto ya tenemos casi todos los ingredientes para terminar nuestro programa que comprimira archivos de texto.

[Implementación](codigos/clase_17_practica_01.cpp)

Ahora para terminar con este ejercicio y poder crear una herramienta de codificación y decodificación de texto, el resto de la clase harán lo siguiente:

- Como pueden notar al decodificar hay un error justo en el último caracter, corregir el código para que este error no ocurra.
- Crear una función que reciba un `unordered_map<char, int> um_freq` y nos regrese la raiz del arbol de decodificación Huffman.
- Crear una función que reciba un `unordered_map<char, int> um_freq` y nos regrese un mapa de codificación `unordered_map<char, string> huffmanCode`.
- Crear función que reciba como parametro `unordered_map<char, int> um_freq` y que guarde un archivo con el siguiente formato:
```
<numero de entradas>
<caracter> <entero>
```
- Crear función que lea un archivo con el siguiente formato y guarde dichas entradas en `unordered_map<char, int> um_freq`:
```
<numero de entradas>
<caracter> <entero>
```


## No olviden enviar su propuesta de proyecto para mañana!!!

## La siguiente semana tenemos el 2do Parcial

Esta semana no habrá tarea para que tengan tiempo de estudiar para su exámen.

Temas:
- Tablas Hash
- Recursión
- Arboles
- Arboles Binarios
- Arboles de Busqueda Binaria
- Codificación de Huffman