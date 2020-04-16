#include <iostream>
#include <algorithm>
#include <string.h>
#include "pair.h"

 void PrintArr(int arr[], int n){
	for (int i=0; i<n; i++){
		std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
} 

void Convert(int arr[],int arr_convert[], int n){ 
	// Creamos un arreglo temporal temp como parejas ordenadas
    Pair<int, int> *_vector = new Pair<int, int>[n];
    for(int i=0;i<n;++i){
        _vector[i] = make_Pair(arr[i], i); 
    }
	// Ordenamos el arreglo usando la funcion sort de la biblioteca algorithm
    // Con esto garantizamos O(n log(n))
	std::sort(_vector, _vector + n); 
    std::cout << "Imprimiendo _vector" << std::endl;
    for(int i=0;i<n;++i){
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;
    // Ponemos el segundo indice de vector en arr_convert
	for (int i = 0; i < n; i++) {
        arr_convert[_vector[i].second] = i; 
    }
    delete [] _vector;// en realidad este vector es la tabla hash
} 

int main(int argc, char *argv[]) { 
    // Inicializamos el arreglo como en ejemplos anteriores
	int A[] = {10, 20, 15, 12, 11, 50}; 
    // Calculamos el tamaño del arreglo
	int n = sizeof(A)/sizeof(A[0]); 
    int *B = (int*)malloc(sizeof(int)*n);
	std::cout << "Consideremos el siguiente arreglo" << std::endl; 
	PrintArr(A, n); 
	Convert(A, B, n); 
	std::cout << "Arreglo convertido" << std::endl; 
	PrintArr(B, n); 
    free(B);
	return 0; 
} 