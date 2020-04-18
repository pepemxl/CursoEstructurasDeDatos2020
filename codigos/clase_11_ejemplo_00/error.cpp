#include <iostream>
#include <algorithm>
#include <string.h>
#include "pair.h"
 

int main(int argc, char *argv[]) { 
    Pair<int, int> map[50];
    /*Pair<int, int> p1(10,10);
    std::cout << p1 << std::endl;
    Pair<int, int> p2=p1;
    std::cout << p2 << std::endl;
    Pair<int, int> p3;
    p3=p1;
    std::cout << p3 << std::endl;*/
    for(int i=0;i<50;++i){
        map[i] = make_Pair<int, int>(i, 50);
    }
    for(int i=0;i<50;++i){
        std::cout << map[i] << std::endl;
    }
	return 0; 
} 