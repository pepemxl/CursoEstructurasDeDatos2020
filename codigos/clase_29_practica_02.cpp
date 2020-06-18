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
    int getV();
    Node<T> *getNodeAdyacencias(int u);
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

template <typename T>
int Graph<T>::getV(){
    return m_iV;
}

template <typename T>
Node<T> *Graph<T>::getNodeAdyacencias(int u){
    return m_ptrAdj[u];
}

// Esta funcion nos ayudara a encontrar la arista,
// con menos peso, del conjunto de aristas que aun no estan en el MST
template<typename T>
int MinKey(T *key, bool *mst_flags, int V){  
    int min_weight = INT_MAX;// + infinito para inicializar busqueda
    int min_index = -1;// indice no encontrado
    std::cout << "Buscando nodo libre: ";
    for(int i = 0; i < V; ++i){// como mejoramos esta parte??
        if(mst_flags[i] == false){
            std::cout << i << "(libre";
            if(key[i] < min_weight){
                std::cout << " y menor";
                min_weight = key[i];
                min_index = i;
            }
            std::cout << ")," ;
        }
    }
    std::cout << std::endl;
    return min_index;  
} 

// Para todos los vertices del grafo
// - revisamos cuales estan conectados al vertice u
// y aun no han sido agregados al MST, i.e., mst_flags[v] == false
// - tomamos el que tenga menor peso y actualizamos tanto
// su peso como el padre
template<typename T>
void UpdateKeyParent(Graph<T> &g, int u, T *key, bool *mst_flags, int *parent){
    int V = g.getV();
    std::cout << "Vecinos de " << u << ":";
    for(int v = 0; v < V;++v){
        Node<T> *temp = g.getNodeAdyacencias(v);
        temp = temp->next;// el primer nodo es el mismo vertice
        while(temp != NULL){
            // el nodo no ha sido agregado a MST
            int u_ = temp->data;// nodo vecino de v
            int peso = temp->weight;// peso de v->u_
            if(u_ == u){
                std::cout << v;
                if(mst_flags[v] == false){
                    std::cout << "(No en MST)";
                    if(peso < key[v]){
                        parent[v] = u;
                        key[v] = peso;
                        std::cout << "(up peso: "<<peso<<")";
                    }
                }
                std::cout << ",";
            }
            
            temp = temp->next;
        }
    }
    std::cout << std::endl;
} 

// pratica optimizar la funcion UpdateKeyParent
template<typename T>
void UpdateKeyParent2(Graph<T> &g, int u, T *key, bool *mst_flags, int *parent){
}

template<typename T>
void PrintMST(Graph<T> &g, int *parent){ 
    int V = g.getV();
    std::cout << "Aristas" << std::endl;
    for(int i = 1; i < V; ++i){
        std::cout << i << " - " << parent[i] << std::endl;
    }
    //std::cout << std::endl;
} 

// practica
// crear funcion que calcule la suma de todos los pesos de las aristas



template <typename T>
void PrimMST(Graph<T> &g){
    int V = g.getV();
    // Arreglo para guardar MST
    int *parent = new int[V];
    // Valores llave/peso que podria ser entero o flotante
    T *key = new T[V];
    // Arreglo que indica que vertices estan en MST
    bool *mst_flags = new bool[V];
    // Inicializamos todas las llaves a INT_MAX
    for(int i = 0; i < V; ++i){
        key[i] = (T)INT_MAX;
        mst_flags[i] = false;
        parent[i] = -1;
    }
    // Por el momento pondremos como primer elemento de nuestro
    // MST al vertice en la posición 0
    key[0] = (T)0;
    parent[0] = -1; // Indica que no tiene padre
    for(int i = 0; i < V; ++i){
        // Buscamos la llave/peso de menor valor
        // de los vectices que no estan en el MST
        int u = MinKey(key, mst_flags, V);// la primera vez sabemos que sera nodo 0
        std::cout << "Agregamos a:" << u << std::endl;
        // Agregamos nodo encontrado al MST
        mst_flags[u] = true;
        // Actualizamos nuestros arreglos temporales de vertices 
        // y pesos que estan conectados al nodo seleccionado
        // pero no han sido aun incluidos al MST
        UpdateKeyParent<T>(g, u, key, mst_flags, parent);
    }
    // Imprimir MST
    PrintMST<T>(g, parent);
    delete [] mst_flags;
    delete [] key;
    delete [] parent;
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
    //g.printAdyacencias();
    PrimMST<int>(g);
    return 0; 
}