#include <iostream>


int hanoi(int n){
    if(n < 1){
        return 0;
    }
    if(n == 1){
        return 1;
    }else{
        return 2*hanoi(n-1)+1;
    }
}

int main(int argc, char *argv[]){
    for(int i = 0; i < 10; ++i){
        std::cout << "Hanoi(" << i << ") : " << hanoi(i) << std::endl;
    }
}