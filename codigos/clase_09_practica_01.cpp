#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_map>


int Swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


bool BubbleSort(int A[], int B[], int n){
    for(int i = 0; i < n-1;++i){
        for(int j = i+1; j < n;++j){
            if(A[i] > A[j]){
                Swap(A[i], A[j]);
                Swap(B[i], B[j]);
            }
        } 
    }
}


void PrintArr(int arr[], int n){
	for (int i=0; i<n; i++){
		std::cout << arr[i] << " "; 
    }
    std::cout << std::endl;
} 

void Convert(int arr[], int arr_convert[], int n){ 
	// Creamos un arreglo temporal temp y copiamos todos los elementos usando memcpy
	int temp[n]; 
	memcpy(temp, arr, n*sizeof(int)); 
    // Creamos arreglo con indices de 0 a n-1
    for(int i = 0; i < n; i++){
        arr_convert[i] = i;
    }
    std::cout << "arr_convert inicializado: ";
    PrintArr(arr_convert, n);
	// Ordenamos el arreglo usando la funcion bubblesort que definimos arriba
	BubbleSort(temp, arr_convert, n); 
} 




int main(int argc, char *argv[]) { 
    // Inicializamos el arreglo
	int A[] = {10, 20, 15, 12, 11, 50};// -> {0=10,2=20,3=15,1=12,4=11,5=50}
    // Calculamos el tamaño del arreglo
	int n = sizeof(A)/sizeof(A[0]); 
    int *B = (int*)malloc(sizeof(int)*n);
	std::cout << "Consideremos el siguiente arreglo" << std::endl; 
	PrintArr(A, n); 
    std::cout << "Iniciamos conversion" << std::endl; 
    Convert(A, B, n); 
	std::cout << "Arreglo convertido" << std::endl; 
	PrintArr(B, n); 
    std::cout << "Imprimir arreglo original ordenado" << std::endl; 
    for(int i = 0;i < n; ++i){
        std::cout << A[B[i]] << " "; 
    }
    std::cout << std::endl;
    free(B);
	return 0; 
} 
