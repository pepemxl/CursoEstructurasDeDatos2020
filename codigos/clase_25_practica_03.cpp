#include <iostream>
#include <list> 
#include <vector>

class Graph {
private:
    int m_iV;// Numero de vertices
    std::list<int> *m_ptrAdj;// Apuntador a un arreglo que contiene las listas de adyacencias
    bool *m_ptrbVisited;
    void DFS_recursive(int s, bool *status);
public: 
    Graph();
    ~Graph();
    Graph(int V);
    void addEdge(int u, int v);
    void DFS(int s);// Recorrido BFS desde nodo s
}; 

Graph::Graph(){
    m_iV = 0; 
    m_ptrAdj = NULL; 
    m_ptrbVisited = NULL;
} 

Graph::Graph(int V){ 
    m_iV = V; 
    m_ptrAdj = new std::list<int>[V]; 
    m_ptrbVisited = new bool[V]; 
} 
Graph::~Graph(){ 
    delete [] m_ptrAdj;
    delete [] m_ptrbVisited;
}

void Graph::addEdge(int u, int v){
    m_ptrAdj[u].push_back(v);
}

void Graph::DFS_recursive(int s, bool *status) { 
    // Marcamos el nodo como procesado
    status[s] = true; 
    std::cout << (char)(s+'A') << " "; 
    // Recorrecmos toos los nodos adyacentes a este nodo
    std::list<int>::iterator it; 
    for(it = m_ptrAdj[s].begin(); it != m_ptrAdj[s].end(); ++it) {
        if(!status[*it]){
            //std::cout << "Nodo " << (char)(*it+'A') << " fue agregado por ser vecino de Nodo " << (char)(s+'A') << std::endl;
            DFS_recursive(*it, status); 
        }
    }
        
} 

void Graph::DFS(int s){
    // Inicializamos la lista de estados
    for(int i = 0; i < m_iV; ++i) {
        m_ptrbVisited[i] = false;
    }
    DFS_recursive(s, m_ptrbVisited);
} 
  

int main(int argc, char *argv[]){
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(4, 3); 
    g.addEdge(3, 0); 
    //g.addEdge(0, 3); 
    for(int i = 0; i< 5; ++i){
        std::cout << "DFS(" << i << ")" << std::endl;
        g.DFS(i); 
        std::cout << std::endl;
    }
    return 0; 
}