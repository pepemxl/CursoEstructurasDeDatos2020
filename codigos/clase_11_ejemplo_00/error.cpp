#include <iostream>
#include <algorithm>
#include <string.h>
#include "pair.h"
 

int main(int argc, char *argv[]) { 
    Pair<int, int> map[50];
    for(int i=0;i<50;++i){
        map[i] = make_pair<int, int>(i, 50);
    }
    for(int i=0;i<50;++i){
        std::cout << map[i] << std::endl;
    }
	return 0; 
} 