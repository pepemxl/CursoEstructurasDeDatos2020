#include <iostream>
#include <algorithm>
#include <string.h>

 void PrintArr(int arr[], int n){
	for (int i=0; i<n; i++){
		std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
} 

void Convert(int arr[],int arr_convert[], int n){ 
	// Creamos un arreglo temporal temp y copiamos todos los elementos usando memcpy
	int temp[n]; 
	memcpy(temp, arr, n*sizeof(int)); 
	// Ordenamos el arreglo usando la funcion sort de la biblioteca algorithm
    // Con esto garantizamos O(n log(n))
	std::sort(temp, temp + n); 

	// Creamos una tabla hash usando un mapa desordenado( lo ironico es que estamos creando una tabla hash con otra y nadie a replicado!!!)
    // pueden pensarlo como una lista de pares de datos, en este caso enteros
	int umap[100] = {0}; // estamos usando este arreglo para optimizar acceso desperdiciando memoria
	// Insertamos los valores ordenados del arreglo en esta tabla hash
    // {10, 11, 12, 15, 20, 50}; 
	for (int i = 0; i < n; i++) {//i = 0
        umap[temp[i]] = i; //umap[temp[0]] = 0; umap[10] = 0; umap[0] = (10, 0)
        //umap[10] = 0;
        //umap[11] = 1;
        //umap[12] = 2;
        //umap[15] = 3;
        //umap[20] = 4;
        //umap[50] = 5;
    }
    //i = 4
    //umap[temp[i]] = i; -> umap[temp[4]] = 4; -> umap[20] = 4
	//umap(10) = 0
    //umap(20) = 4
	for (int i = 0; i < n; i++) {
        arr_convert[i] = umap[arr[i]]; 
    }
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