#include <iostream>
#include <vector>


template <typename T>
struct Node{
    T data;
    T weight;
    Node<T> *next;
    Node(){
        this->data = 0;
        this->weight = 0;
        this->next = NULL;
    }
    Node(T &val){
        this->data = val;
        this->weight = 0;
        this->next = NULL;
    }
    Node(T &val, T &val2){
        //this->id = val;
        this->data = val;
        this->weight = val2;
        this->next = NULL;
    }
    ~Node(){

    }
};

template <typename T>
void PushBack(Node<T> *ptrNode, T &val, T &val2){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    Node<T> *newNode = new Node<T>(val, val2);
    tempNode = ptrNode;
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    return;
}

template <typename T>
void Print(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;
    while(tempNode != NULL){
        std::cout << "(" << tempNode->data << "," << tempNode->weight << ")->";
        tempNode = tempNode->next;
    }
    std::cout << "NULL"<< std::endl;
    return;
}

template <typename T>
void PrintLetter(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;
    while(tempNode != NULL){
        std::cout << "(" << (char)(tempNode->data +'A') << "," << tempNode->weight << ")->";
        tempNode = tempNode->next;
    }
    std::cout << "NULL"<< std::endl;
    return;
}

// funcion para agregar aristas o relaciones usando una
// lista de vectores
template <typename T>
void AddEdge(Node<T> **adj, int u, int v, int peso) {
    PushBack(adj[u], v, peso);
}

// Funcion para imprimir lista de adyacencias
template <typename T>
void PrintGraph(Node<T> **adj, int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << "Lista de vertices adyacentes del nodo " << i << std::endl; 
        Print(adj[i]);
        PrintLetter(adj[i]);
	} 
} 

int main(int argc, char *argv[]) {
	int n = 5; // numero de vertices
	Node<int> **adj; // adj es un arreglo de 5 vectores que guardaran la lista de adyacencias
    adj = new Node<int>*[n];
    for(int i = 0; i < n;++i){
        adj[i] = new Node<int>(i);
    }
	AddEdge(adj, 0, 1, 5); 
	AddEdge(adj, 1, 2, 2); 
	AddEdge(adj, 1, 3, 8); 
	AddEdge(adj, 2, 4, 4); 
	AddEdge(adj, 4, 3, 10); 
    AddEdge(adj, 3, 0, 7); 
	PrintGraph(adj, n);
	return 0; 
} 
