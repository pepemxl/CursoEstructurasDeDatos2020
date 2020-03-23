#include <stdio.h>
#include <iostream>

int fact(int n){
    if (n <= 1){ // caso base
        return 1;
    }else{
        return n*fact(n-1);    
    }
}
  
int main() 
{ 
    int n = 10; 
    for(int i = 0; i < n;++i){
        std::cout << "Factorial de " << i << " es " << fact(i) << std::endl;
    }
    
}