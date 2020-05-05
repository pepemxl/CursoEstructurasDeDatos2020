# Sesión 16

## Codificación de Huffman (continuación)

Codificación de Huffman(o Huffman Encoding) es un algoritmo para hacer compresión de información y es la versión más sencilla de lo que hoy conocemos como compresión de archivos.

[Implementación](codigos/clase_16_practica_01.cpp)


En esta implementación vemos como se escribe de manera binaria un archivo de texto. Esto será utilizado más adelante.

Usar dicha implementación para guardar tanto en binario el código de la clase pasada, asi como su versión comprimida.

## ¿Qué pueden decir de ambas versiones?

Crear las siguientes funciones:

```
// Esta funcion deberá procesar una cadena de caracteres y
// separar en bloques de 8 bits, para entonces convertirlos en
// caracteres 
char* segmenta_cadena(char *buffer, int length){

}
```

```
// Esta funcion recibe un bloque de 8 bits y lo convierte 
// a un caracter
char convierte_cadena_8bits_to_char(char *buffer){

}
```


Con lo visto en clase crearemos un pequeño código de encriptación, que será parte de la tarea de la siguiente semana.
