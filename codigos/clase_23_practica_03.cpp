#include <iostream>
#include <limits.h>
#include <vector>


void adj(std::vector<std:vector<int> >, int i, int j){
    matriz_adyacencias[i][j] = 1;
}


void adj(std::vector<int[]>, int i, int j){
    matriz_adyacencias[i][j] = 1;
}


void adj(int matriz_adyacencias[5][5], int i, int j){
    matriz_adyacencias[i][j] = 1;
}


int main(int argc, char *argv[]){
    int v = 5;
    int matriz_adyacencias[5][5];
    for(int i = 0;i < 5; ++i){
        for(int j = 0;j < 5; ++j){
            matriz_adyacencias[i][j] = 0;
        }
    }
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
    std::pair<int,int> E_ab(0,1);
    adj(matriz_adyacencias,0,1);
    adj(matriz_adyacencias,0,3);
    adj(matriz_adyacencias,1,0);
    adj(matriz_adyacencias,1,2);
    adj(matriz_adyacencias,1,3);
    adj(matriz_adyacencias,2,1);
    adj(matriz_adyacencias,2,4);
    adj(matriz_adyacencias,3,0);
    adj(matriz_adyacencias,3,1);
    adj(matriz_adyacencias,3,4);
    adj(matriz_adyacencias,4,2);
    adj(matriz_adyacencias,4,3);
    return 0;
}