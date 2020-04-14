#include <iostream>
#include <algorithm>
#include <string.h>
#include "pair.h"
 

int main(int argc, char *argv[]) { 
    Pair<int, int> p1;
    p1.first  = 1;
    p1.second = 2;
    std::cout << "p1=(" << p1.first << ", " << p1.second << ")" << std::endl;
    Pair<int, int> p2(2, 3);
    std::cout << "p2=(" << p2.first << ", " << p2.second << ")" << std::endl;
    Pair<int, int> p3 = make_pair(3, 4);
    std::cout << "p3=(" << p3.first << ", " << p3.second << ")" << std::endl;
    Pair<int, int> p4 = p3;
    std::cout << "p4=(" << p4.first << ", " << p4.second << ")" << std::endl;
    std::cout << "p4="<< p4 << std::endl;
    if(!(p4 == p1)){
        std::cout << "p4 is NOT equal to p1" << std::endl;
    }
    if(p4 == p3){
        std::cout << "p4 is equal to p3" << std::endl;
    }
    if(p4!=p1){
        std::cout << "p4 is NOT equal to p1" << std::endl;
    }
    if(p1>=p1){
        std::cout << "p1 is major or equal to p1" << std::endl;
    }
    if(p1>=p2){
        std::cout << "p1 is greater or equal than p2" << std::endl;
    }else{
        std::cout << "p1 is lower than p2" << std::endl;
    }
    if(p1<=p2){
        std::cout << "p1 is lower than p2" << std::endl;
    }else{
        std::cout << "p1 is greater or equal than p2" << std::endl;    
    }
    if(p1 <= p1){
        std::cout << "p1 is lower or equal than p2" << std::endl;
    }else{
        std::cout << "p1 is greater than p2" << std::endl;
    }
    std::cout << "p1=" << p1 << std::endl;
    std::cout << "p2=" << p2 << std::endl;
    std::cout << "Hacemos swap de p1 con p2" << std::endl;
    p1.swap(p2);
    std::cout << "p1=" << p1 << std::endl;
    std::cout << "p2=" << p2 << std::endl;
    std::cout << "Hacemos swap de p1 con p2" << std::endl;
    p1.swap(p2);
    std::cout << "p1=" << p1 << std::endl;
    std::cout << "p2=" << p2 << std::endl;
	return 0; 
} 