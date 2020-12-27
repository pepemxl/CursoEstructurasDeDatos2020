#include <Container/CStack.h>
#include <iostream>

int main(int argc, char *argv[]){
    CStack<int> L1;
    int temp;
    for(int i = 0; i < 1000; ++i){
        std::cout << "Pushing:" << i+1 << std::endl;
        L1.Push(i+1);
    }
    L1.Print();
    for(int i = 0; i < 1000; ++i){
        std::cout << "Poping:" << L1.Pop() << std::endl;
    }
    return 0;
}