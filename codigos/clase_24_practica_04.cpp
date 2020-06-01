#include <iostream>
#include <vector>

// funcion para agregar aristas o relaciones usando una
// lista de vectores
void AddEdge(std::vector<int> adj[], int u, int v) {
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

// Funcion para imprimir lista de adyacencias
void PrintGraph(std::vector<int> adj[], int n) {
	for(int i = 0; i < n; ++i) {
		std::cout << "Lista de vertices adyacentes del nodo " << i << std::endl; 
        std::cout << i ;
        for(int j = 0;j < adj[i].size();++j){
            std::cout << "-> " << adj[i][j]; 
        }
		std::cout << std::endl;
        std::cout << (char)(i + 'A');
        for(int j = 0;j < adj[i].size();++j){
            std::cout << "-> " << (char)(adj[i][j] + 'A'); 
        }
		std::cout << std::endl;
	} 
} 

int main(int argc, char *argv[]) {
	int n = 5; // numero de vertices
	std::vector<int> adj[n]; // adj es un arreglo de 5 vectores que guardaran la lista de adyacencias
	AddEdge(adj, 0, 1); 
	AddEdge(adj, 0, 3); 
    //AddEdge(adj, 1, 0);  //ya fue considerado
	AddEdge(adj, 1, 2); 
	AddEdge(adj, 1, 3); 
	//AddEdge(adj, 2, 1); //ya fue considerado
	AddEdge(adj, 2, 4); 
	AddEdge(adj, 3, 4); 
	PrintGraph(adj, n); 
	return 0; 
} 
