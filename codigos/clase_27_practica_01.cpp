#include <iostream> 
#include "limits.h" 

// Función para hacer sqp de dos datos
template <typename T>
void swap(T *x, T *y){
	T temp = *x; 
	*x = *y; 
	*y = temp; 
} 

//Class para Min Heap
class MinHeap {
private:
	int *m_ptriArr; // Apuntador a arreglon donde se guardara heap
	int m_iCapacity; // tamaño maximo
	int m_iHeapSize; // tamaño actual
public: 
    // Constructor por default
    MinHeap(); 
    // Constructor: Crea un Heap apartir del arreglo A[] de tamaño capacity
	MinHeap(int capacity); 
	// heapify un subarbol con un nodo raiz dado el index
	void MinHeapify(int index);
    // Encontrar al padre del nodo i
	int Parent(int i);
	// Encuentra el hijo izquierdo del nodo i
	int Left(int i);
	// Encuentra el hijo derecho del nodo i
	int Right(int i);
	// Extrae la raiz
	int ExtractMin(); 
	// Decrementa el valor de la llave en el indice i al valor val
	void DecreaseKey(int i, int val); 
	// Regresa la menor llave del min heap
	int GetMin();
	// Borra la llave guardada en el indice i
	void DeleteKey(int i); 
	// Inserta una nueva llave k
	void InsertKey(int k); 
    // Imprime todos los valores del heap
    void Print();
}; 

MinHeap::MinHeap(){
	m_iHeapSize = 0; 
	m_iCapacity = 100; 
    m_ptriArr = new int[100];// se pone una potencia de 2
    // tambien podrian usar un vector<int>
} 

MinHeap::MinHeap(int capacity){
	m_iHeapSize = 0; 
	m_iCapacity = capacity; 
	m_ptriArr = new int[capacity]; 
} 

int MinHeap::Parent(int i){
    if(i > 0){
        return (i-1)/2; 
    }else{
        return -1;// para indicar que hubo un error
    }
}

int MinHeap::Left(int i){
    if(i < m_iCapacity){
        return (2*i + 1); 
    }else{
        return -1;// para indicar que hubo un error
    }
    
}

int MinHeap::Right(int i){
    if(i < m_iCapacity){
        return (2*i + 2);
    }else{
        return -1;// para indicar que hubo un error
    }
}

int MinHeap::GetMin(){
    if(m_iCapacity >0 ){
        return m_ptriArr[0]; 
    }
}
 
void MinHeap::InsertKey(int key){ 
    std::cout << "Insertando valor en ultima posicion: " << key << std::endl;
	if(m_iHeapSize == m_iCapacity){
		std::cout << "Overflow: Has alcanzado el limite de el arreglo" << std::endl; 
		return; 
	}
    m_ptriArr[m_iHeapSize] = key; 
    int current_index = m_iHeapSize;
	m_iHeapSize++; 
	// Arreglamos el arreglo hasta que se cumple la propiedad de Min-Heap
	while(current_index != 0 && m_ptriArr[Parent(current_index)] > m_ptriArr[current_index]) { 
	    swap(&m_ptriArr[current_index], &m_ptriArr[Parent(current_index)]); 
	    current_index = Parent(current_index); 
	} 
} 

void MinHeap::DecreaseKey(int current_index, int val) {
    if(val >= m_ptriArr[current_index]){
        std::cout << "Operacion DecreaseKey Invalida" << std::endl;
        return;
    }
	m_ptriArr[current_index] = val; 
	while(current_index != 0 && m_ptriArr[Parent(current_index)] > m_ptriArr[current_index]) {
	    swap(&m_ptriArr[current_index], &m_ptriArr[Parent(current_index)]); 
	    current_index = Parent(current_index); 
	} 
} 

int MinHeap::ExtractMin() {
    std::cout << "Extrayendo raiz: "<< std::endl;
	if(m_iHeapSize <= 0){//heapSize hasta donde he borrado o hasta donde hay elemento en mi arreglo
		return INT_MIN;// INT_MIN(comodin para decir que es un elemento sin valor o le ponemos INT_MAX)
    }
	if(m_iHeapSize == 1) {
		m_iHeapSize--; 
		return m_ptriArr[0]; 
	} 
	int root = m_ptriArr[0]; 
	m_ptriArr[0] = m_ptriArr[m_iHeapSize-1]; 
	m_iHeapSize--; 
	MinHeapify(0); 
	return root; 
} 

void MinHeap::DeleteKey(int current_index){ 
    std::cout << "Borrando elemento en posicion: " << current_index << std::endl;
	DecreaseKey(current_index, INT_MIN); 
	std::cout << "Extract Min: " << ExtractMin() << std::endl; 
} 

// Metodo recursivo para crear un heap apartir de un
// subarbol con su raiz en el indice dado, se asume que sus subarboles ya son heaps
void MinHeap::MinHeapify(int current_index) {
    // obtenemos los nodos de los hijos izquierdo y derecho
	int l = Left(current_index); // posicion en el arreglo
	int r = Right(current_index); // posicion en el arreglo
    // en principio el mas chico se encuentra en la posicion current_index
	int smallest = current_index; // posicion mas pequeña a arreglar
	if( l< m_iHeapSize && m_ptriArr[l] < m_ptriArr[current_index]){
        smallest = l; 
    }
	if(r < m_iHeapSize && m_ptriArr[r] < m_ptriArr[smallest]){
        smallest = r;
    }
	if (smallest != current_index){
		swap(&m_ptriArr[current_index], &m_ptriArr[smallest]);
		MinHeapify(smallest);
	} 
} 

void MinHeap::Print(){
    std::cout << "Heap Values: " << std::endl;
    for(int i = 0; i < m_iHeapSize;++i){
        std::cout << m_ptriArr[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) { 
	MinHeap heap(6); 
	heap.InsertKey(1); 
	heap.InsertKey(3); 
	heap.InsertKey(6); 
	heap.InsertKey(5); 
	heap.InsertKey(9); 
    heap.InsertKey(7); 
    heap.Print();
    heap.DeleteKey(5); // Borrar en posicion
    heap.Print();
    std::cout << "Current Min:" << heap.GetMin() << std::endl;
	heap.InsertKey(8); 
    heap.Print();
	std::cout << "Raiz: " << heap.ExtractMin() << std::endl; 
    heap.Print();
	return 0; 
} 
