#include <stdio.h>
#include <stdlib.h>
#include <iostream> 

// 1 1 2 3 5 8 13
int fibo(int n){
    int res = 0;
    if (n == 0){
        return 1;
    }
    if (n == 1){
        return 1;
    }
    res = fibo(n-1)+ fibo(n-2);//se para calcular amvbos fibonaccis
    return res;
}



int main(int argc, char *argv[]){
    int n=5;
    if(argc == 2){
        n = atoi(argv[1]);// convierte cadena de caracteres a entero
        // ansi string to int
        // tambien existe atof
    }
    std::cout << "Fibonacci " << argv[0] << std::endl;
    std::cout << "Fibonacci(" <<n << "): "<< fibo(n) << std::endl;

    return 0;
}