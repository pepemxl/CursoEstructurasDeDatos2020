#include <stdio.h>
#include <string>

template <class T>
T suma(T a, T b){
    return a+b;
}

int main(int argc, char *argv[]){
    printf("1+3=%d\n", suma(1,3));
    printf("1+3=%f\n", suma(1,3));// Que fue lo que paso?
    float x = suma(1,3);
    printf("1+3=%f\n", x);
    //printf("1+3=%f\n", suma(1,3.0));// Error por que?
    //printf("1+3=%f\n", suma(1.0,3));// Error por que?
    printf("1+3=%f\n", suma(1.0,3.0));
    //printf("1+3=%f\n", suma("1","2"));/ Error por que?
    printf("1+3=%s\n", suma(std::string("1"), std::string("2")));// Cual es el problema?
    return 0;
}