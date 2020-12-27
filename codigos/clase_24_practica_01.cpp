#include <iostream>
#include <limits.h>
#include <vector>


void Print(int **matriz_adyacencias, int n){
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            std::cout << matriz_adyacencias[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Inicializa(int **matriz_adyacencias, int n){
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < n; ++j){
            matriz_adyacencias[i][j] = 0;
        }
    }
}

void CreaAdyacencias(int **matriz_adyacencias){
    matriz_adyacencias[0][1] = 1;
    matriz_adyacencias[0][3] = 1;
    matriz_adyacencias[1][0] = 1;
    matriz_adyacencias[1][2] = 1;
    matriz_adyacencias[1][3] = 1;
    matriz_adyacencias[2][1] = 1;
    matriz_adyacencias[2][4] = 1;
    matriz_adyacencias[3][0] = 1;
    matriz_adyacencias[3][1] = 1;
    matriz_adyacencias[3][4] = 1;
    matriz_adyacencias[4][2] = 1;
    matriz_adyacencias[4][3] = 1;
}

/*G es un grafo No dirigido*/
void AgregaAdyacencia(int **matriz_adyacencias, int i, int j){
    matriz_adyacencias[i][j] = 1;
    matriz_adyacencias[j][i] = 1;
}
/*G es un grafo No dirigido*/
void CreaAdyacencias2(int **matriz_adyacencias){
    AgregaAdyacencia(matriz_adyacencias, 0, 1);
    AgregaAdyacencia(matriz_adyacencias, 0, 3);
    AgregaAdyacencia(matriz_adyacencias, 1, 2);
    AgregaAdyacencia(matriz_adyacencias, 1, 3);
    AgregaAdyacencia(matriz_adyacencias, 2, 4);
    AgregaAdyacencia(matriz_adyacencias, 3, 4);
}


int main(int argc, char *argv[]){
    /*
    Hacemos correspondencia
    A<-0
    B<-1
    C<-2
    D<-3
    E<-4
    */
    int n = 5;
    int **matriz_adyacencias = new int*[n];
    for(int i = 0;i < n;++i){
        matriz_adyacencias[i] = new int[n];
    }
    std::cout << "Version 1" << std::endl;
    Inicializa(matriz_adyacencias, n);
    CreaAdyacencias(matriz_adyacencias);
    Print(matriz_adyacencias, n);
    std::cout << "Version 2" << std::endl;
    Inicializa(matriz_adyacencias, n);
    CreaAdyacencias2(matriz_adyacencias);
    Print(matriz_adyacencias, n);
    for(int i = 0;i < n;++i){
        delete [] matriz_adyacencias[i];
    }
    delete [] matriz_adyacencias;
    return 0;
}