#include <iostream>
#include <algorithm>
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
        //Print(adj[i]);
        PrintLetter(adj[i]);
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
        m_ptrAdj[i] = new Node<T>(i);
    }
}

template <typename T>
void BorraListaLigada(Node<T> *root){
    Node<T> *temp = root;
    Node<T> *aux;
    while(temp != NULL){
        aux = temp->next;
        delete temp;
        temp = aux;
    }
}


//practica para la clase creen la función que libera de manera correcta la memoria instanciada
template <typename T>
Graph<T>::~Graph(){ 
    int V = m_iV; 
    for(int i = 0;i < V;++i){
        BorraListaLigada(m_ptrAdj[i]);// como limpiamos cada lista ligada, limpiarlo asi provoca un leak de memoria
        //m_ptrAdj[0]->node1->node2->node3->node4->NULL// como borramos listas ligadas
        //m_ptrAdj[1]->node1->node2->node3->node4->NULL// como borramos listas ligadas
    }
    delete [] m_ptrAdj;
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
    for(int i = 0; i < V; ++i){// como mejoramos esta parte??
        if(mst_flags[i] == false){
            if(key[i] < min_weight){
                min_weight = key[i];
                min_index = i;
            }
        }
    }
    return min_index;  
} 


template<typename T>
void UpdateKeyParent(Graph<T> &g, int u, T *key, bool *mst_flags, int *parent){
    int V = g.getV();
    Node<T> *u_list = g.getNodeAdyacencias(u);
    Node<T> *temp = u_list->next;
    while( temp != NULL ){
        int v = temp->data;
        int peso = temp->weight;
        if(mst_flags[v] == false){
            if(peso < key[v]){
                parent[v] = u;
                key[v] = peso;
            }
        }
        temp = temp->next;
    }
}

template<typename T>
void PrintMST(Graph<T> &g, int *parent){ 
    int V = g.getV();
    std::cout << "Aristas de MST" << std::endl;
    for(int i = 1; i < V; ++i){
        std::cout << i << " - " << parent[i] << std::endl;
    }
} 

template <typename T>
void PrimMST(Graph<T> &g, int * &parent, T * &key, bool * &mst_flags){
    int V = g.getV();
    parent = new int[V];
    key = new T[V];
    mst_flags = new bool[V];
    for(int i = 0; i < V; ++i){
        key[i] = (T)INT_MAX;
        mst_flags[i] = false;
        parent[i] = -1;
    }
    key[0] = (T)0;
    parent[0] = -1;
    for(int i = 0; i < V; ++i){
        int u = MinKey(key, mst_flags, V);
        mst_flags[u] = true;
        UpdateKeyParent<T>(g, u, key, mst_flags, parent);
    }
    PrintMST<T>(g, parent);
}

// practica
// crear funcion que calcule la suma de todos los pesos de las aristas
template <typename T>
T suma(Graph<T> &g,T* &key){
    int V = g.getV();
    T suma = T(0);
    for(int i = 0; i < V;++i){
        std::cout << "Peso nodo " << i <<" : "<< key[i] << std::endl;
        suma += key[i];
    }
    std::cout << "Peso total: " << suma << std::endl;
    return suma;
}

//truco para guardar relaciones
int Root(int x, int* &label){  
    int indice = x;
    int padre = label[x];
    while(padre != indice){
        indice = padre;
        padre = label[indice];
    }  
    return padre;  
} 

void Union(int x, int y, int* &label){
    int u = Root(x, label);
    int v = Root(y, label);
    //u = label[v];
    if(label[u] < label[v]){
        label[v] = label[u];
    }else{
        label[u] = label[v];
    }
}

 


template <typename T>
T Kruskal(std::vector<std::pair<T, std::pair<int, int > > > &vector_aristas,int* &label,int V){
    int x, root_x;
    int y, root_y;
    T costo;
    T costo_minimo = T(0);
    int edges = vector_aristas.size();  
    for(int i = 0;i < edges;++i){
        x = vector_aristas[i].second.first;  
        y = vector_aristas[i].second.second;  
        costo = vector_aristas[i].first;  
        root_x = Root(x, label);
        root_y = Root(y, label);
        std::cout << "Uniendo arista ("<<(char)(x+'A')<<","<<(char)(y+'A')<<")"<< std::endl;
        std::cout << "Root(x=" << (char)(x+'A') <<"):" << (char)(root_x+'A') << std::endl; 
        std::cout << "Root(y=" << (char)(y+'A') <<"):" << (char)(root_y+'A') << std::endl;
        if( root_x != root_y ){
            costo_minimo += costo;  
            Union(x, y, label); 
            std::cout << "Costo: " << costo;
            std::cout << " Costo Minimo: " << costo_minimo << std::endl;
        }else{
            std::cout << " No Agregado " << std::endl;
        }    
    }  
    return costo_minimo;
}

template <typename T>
void KruskalMST(Graph<T> &g){
    int res = 0;
    int V = g.getV();
    g.printAdyacencias();
    std::vector<std::pair<T, std::pair<int, int > > > vector_aristas;
    for(int u=0; u < V;++u){
        Node<T> *u_list = g.getNodeAdyacencias(u);
        Node<T> *temp = u_list->next;
        while( temp != NULL ){
            int v = temp->data;
            T peso = temp->weight;
            if(u < v){
                vector_aristas.push_back(std::make_pair(peso,std::make_pair(u,v)));
            }
            temp = temp->next;
        }
    }
    // imprimimos lista completa de aristas
    std::cout << "(peso,node1,node2)"<<std::endl;
    for(int i = 0; i < vector_aristas.size();++i){
        std::cout <<"("<< vector_aristas[i].first << ",";
        std::cout << vector_aristas[i].second.first << ",";
        std::cout << vector_aristas[i].second.second << ")";
        std::cout << std::endl;
    }
    std::sort(vector_aristas.begin(),vector_aristas.end());
    // imprimimos lista completa de aristas ordenada por peso
    std::cout << "(peso,arista1, arista2)"<<std::endl;
    for(int i = 0; i < vector_aristas.size();++i){
        std::cout <<"("<< vector_aristas[i].first << ",";
        std::cout << vector_aristas[i].second.first << ",";
        std::cout << vector_aristas[i].second.second << ")";
        std::cout << std::endl;
    }
    //creamos labels t(i) = i
    int *label = new int[V];
    for(int u=0; u < V;++u){
        label[u] = u;//padre del nodo
    }

    res = Kruskal(vector_aristas, label, V);
    std::cout << "Costo total:" << res << std::endl;
    delete [] label;
}



/*
    Grafo de ejemplo para kruskal
    V={0->A,1->B,2->C,3->D,4->E,5->F,6->G}
    G={(A,B,7),
       (A,D,5),
       (B,C,8),
       (B,E,7),
       (B,D,9),
       (C,E,5),
       (D,E,15),
       (D,F,6),
       (E,F,8),
       (E,G,9),
       (F,G,11)
    }
*/
int main(int argc, char *argv[]){
    Graph<int> g(7); 
    g.addEdge(0,1,7);//g.addEdgeL('A','B',7)
    g.addEdge(0,3,5);
    g.addEdge(1,2,8);
    g.addEdge(1,4,7);
    g.addEdge(1,3,9);
    g.addEdge(2,4,5);
    g.addEdge(3,4,15);
    g.addEdge(3,5,6);
    g.addEdge(4,5,8);
    g.addEdge(4,6,9);
    g.addEdge(5,6,11);
    KruskalMST<int>(g);
    return 0; 
}