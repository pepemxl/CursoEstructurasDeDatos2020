#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int signo = 1;
        int temp;
        if(x == INT_MIN){
            return 0;
        }
        if(x < 0){
            signo = -1;
            temp = x*signo;
        }else{
            temp = x;
        }
        int nuevo = 0;
        int residuo = 0;
        while(temp > 0){
            residuo = temp%10;
            temp = temp/10;
            if (nuevo > INT_MAX / 10){
                return 0;
            }
            nuevo = nuevo*10+residuo;
        }
        return nuevo*signo;
    }
};


int main(){
    Solution sol;
    //printf("%d",' ');
    // std::cout << sol.reverse(0) << std::endl;
    // std::cout << sol.reverse(-1) << std::endl;
    // std::cout << sol.reverse(609) << std::endl;
    // std::cout << sol.reverse(-609) << std::endl;
    // std::cout << sol.reverse(1534236469) << std::endl;
    // std::cout << sol.reverse(-2147483648) << std::endl;
    std::cout << -2147483648 << std::endl;
    std::cout << INT_MIN << std::endl;
    std::cout << INT_MIN-1 << std::endl;
    if(-2147483648 == INT_MIN){
        std::cout << "Valiendo" << std::endl; 
    }
    
    return 0;
}