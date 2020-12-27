#include <iostream>
#include <vector>


template <typename T>
struct Node{
    T data;
    Node<T> *next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(T &val){
        this->data = val;
        this->next = NULL;
    }
    ~Node(){

    }
};

template <typename T>
void PushBack(Node<T> *ptrNode, T &val){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    Node<T> *newNode = new Node<T>(val);
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
        std::cout << tempNode->data << "->";
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
        std::cout << (char)(tempNode->data +'A') << "->";
        tempNode = tempNode->next;
    }
    std::cout << "NULL"<< std::endl;
    return;
}

// funcion para agregar aristas o relaciones usando una
// lista de vectores
template <typename T>
void AddEdge(Node<T> **adj, int u, int v) {
    PushBack(adj[u], v);
    PushBack(adj[v], u);
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
    //iniciaNodo(adj, 0);
	AddEdge(adj, 0, 1); 
	AddEdge(adj, 0, 3); 
    //AddEdge(adj, 1, 0);  //ya fue considerado
	AddEdge(adj, 1, 2); 
	AddEdge(adj, 1, 3); 
	//AddEdge(adj, 2, 1); //ya fue considerado
	AddEdge(adj, 2, 4); 
	AddEdge(adj, 3, 4); 
	PrintGraph(adj, n);
    for(int i = 0; i < n;++i){
        delete adj[i];
    }
    delete [] adj;
	return 0; 
} 
