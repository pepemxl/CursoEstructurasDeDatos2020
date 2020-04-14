#include <stdio.h>
#include <iostream>

void printANumber(int n) 
{ 
    if (n < 1) {//caso base
        std::cout << n << " "; 
        return;
    }else{ 
        printANumber(n-1);
        std::cout << n << " "; 
        //printANumber(n-1);
        return;
    } 
} 
  
int main() 
{ 
    int n = 20; 
    printANumber(n); 
}