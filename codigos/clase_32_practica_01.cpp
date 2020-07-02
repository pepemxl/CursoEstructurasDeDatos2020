#include <iostream>
#include <algorithm>
#include <vector>

class TGato{
public:
    int T[3][3];//0's significan O, y los 1's significan X

    TGato(){
        for(int i = 0; i < 3;++i){
            for(int j = 0; j < 3;++j){
                T[i][j] = -1;
            }
        }
    }
    ~TGato(){}
    print(){
        std::cout << "Imprimiendo Tablero" << std::endl;
        for(int i = 0; i < 3;++i){
            for(int j = 0; j < 3;++j){
                if(T[i][j] == -1){
                    std::cout << " " << " ";
                }
                if(T[i][j] == 0){
                    std::cout << "O" << " ";
                }
                if(T[i][j] == 1){
                    std::cout << "X" << " ";
                }
            }
            std::cout << std::endl;//esta es la forma lenta
            //std::cout << "\n";// esta es más rapida
        }
    }
    void set(int i, int j, int value){
        T[i][j] = value;
    }
    int get(int i, int j){
        return T[i][j];
    }
};


int CrearNodosHijos(){
    int NumeroHijos = 0;

    return NumeroHijos;
}

int MinMax(){

}

void GeneraHijos(TGato &T, std::vector<TGato> &nivel, int val){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(T.get(i,j) == -1){
                TGato copia = T;//falta crear memoria
                copia.set(i,j,val);
                nivel.push_back(copia);
            }
        }
    }
}

int main(int argc, char *argv[]){
    TGato T1;
    T1.print();
    T1.set(0,0,0);
    T1.set(0,1,0);
    T1.set(0,2,1);
    T1.set(1,0,1);
    T1.set(1,2,0);
    T1.set(2,2,1);
    T1.print();
    std::vector<TGato> nivel1;
    std::vector<TGato> nivel2;
    GeneraHijos(T1, nivel1, 1);
    std::cout << nivel1.size() << std::endl;
    for(int i = 0; i < nivel1.size();++i){
        nivel1[i].print();
    }
    for(int i = 0; i < nivel1.size();++i){
        GeneraHijos(nivel1[i], nivel2, 0);
    }
    std::cout << nivel2.size() << std::endl;
    for(int i = 0; i < nivel2.size();++i){
        nivel2[i].print();
    }
    return 0;
}