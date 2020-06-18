#include <iostream>

template <typename T>
struct Node{
    T data;
    T weight;
    Node<T> *next;
    Node(){
        this->data = 0;
        this->weight = 0;
        this->next = NULL;
        //std::cout << "Contructor_default" << std::endl;
    }
    Node(T &val){
        this->data = val;
        this->weight = 0;
        this->next = NULL;
        //std::cout << "Contructor_val" << std::endl;
    }
    Node(T &val, T &val2){
        this->data = val;
        this->weight = val2;
        this->next = NULL;
        //std::cout << "Contructor_val_weight" << std::endl;
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
    //PushBack(adj[v], u, peso);
}

// Funcion para imprimir lista de adyacencias
template <typename T>
void PrintGraph(Node<T> **adj, int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << "Lista de vertices adyacentes del nodo " << i << std::endl; 
        Print(adj[i]);
        //PrintLetter(adj[i]);
	} 
} 


template <typename T>
class Graph {
private:
    int m_iV;// Numero de vertices
    Node<T> **m_ptrAdj;// Apuntador a un arreglo que contiene el primer nodo de las listas de adyacencias
public: 
    Graph();
    ~Graph();
    Graph(int V);
    void addEdge(int u, int v, T weight);
    void printAdyacencias();
}; 

template <typename T>
Graph<T>::Graph(){
    m_iV = 0; 
    m_ptrAdj = NULL; 
} 

template <typename T>
Graph<T>::Graph(int V){ 
    m_iV = V; 
    m_ptrAdj = new Node<T>*[V];
    for(int i = 0;i < V;++i){
        m_ptrAdj[i] = new Node<T>;
    }
} 

//practica para la clase creen la función que libera de manera correcta la memoria instanciada
template <typename T>
Graph<T>::~Graph(){ 
    
}

template <typename T>
void Graph<T>::addEdge(int u, int v, T weight){
    AddEdge<T>(m_ptrAdj, u, v, weight);
    AddEdge<T>(m_ptrAdj, v, u, weight);
}

template <typename T>
void Graph<T>::printAdyacencias(){
    PrintGraph<T>(m_ptrAdj, m_iV);
}

int main(int argc, char *argv[]){
    Graph<int> g(6); 
    g.addEdge(0, 1, 1); 
    g.addEdge(0, 2, 5); 
    g.addEdge(1, 2, 2); 
    g.addEdge(1, 3, 5); 
    g.addEdge(1, 4, 2); 
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 2);
    g.addEdge(4, 5, 4);
    g.printAdyacencias();
    return 0; 
}