#include <iostream>
#include <list> 
#include <vector>

class Graph {
private:
    int m_iV;// Numero de vertices
    std::list<int> *m_ptrAdj;// Apuntador a un arreglo que contiene las listas de adyacencias
    bool *m_ptrbVisited;
public: 
    Graph();
    ~Graph();
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s);// Recorrido BFS desde nodo s
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
    m_ptrAdj[v].push_back(u);
}

void Graph::BFS(int s){
    // Inicializamos la lista de visitados
    for(int i = 0; i < m_iV; ++i) {
        m_ptrbVisited[i] = false;
    }
    // Creamos un queue para este BFS usando una lista de la libreria estandar
    std::list<int> queue; 
    // Ponemos el nodo s como visitado y lo agregamos al queue
    m_ptrbVisited[s] = true; 
    queue.push_back(s); 
    // Creamos un iterador de listas
    std::list<int>::iterator it; 
    while(!queue.empty()){
        // Desencolamos e imprimimos valor
        s = queue.front(); 
        std::cout << (char)(s+'A') << " "; 
        queue.pop_front();//esta funcion borra el primer elemento de la lista
        // Revisamos todos los vecinos del nodo s en la lista de adyacencias
        for(it = m_ptrAdj[s].begin(); it != m_ptrAdj[s].end(); ++it) { 
            // si no ha sido visitado se pone como visitado y se agrega al queue
            if (!m_ptrbVisited[*it]){ 
                m_ptrbVisited[*it] = true; 
                queue.push_back(*it); 
            }
        }
   } 
} 
  

int main(int argc, char *argv[]){
    Graph g(5); 
    g.addEdge(0, 1); 
    g.addEdge(1, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(4, 3); 
    g.addEdge(3, 0); 
    g.addEdge(0, 3); // que pasa si invertimos esta relacion
    for(int i = 0; i< 5; ++i){
        std::cout << "BFS(" << i << ")" << std::endl;
        g.BFS(i); 
        std::cout << std::endl;
    }
    return 0; 
}