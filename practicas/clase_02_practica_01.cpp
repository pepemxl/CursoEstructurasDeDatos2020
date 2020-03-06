#include <stdio.h>

template<int n>
struct fun {
    enum { val = fun<n-1>::val + fun<n-2>::val};
};

template<> 
struct fun<0> { 
    enum { val = 1 }; 
};

template<> 
struct fun<1> { 
    enum { val = 1 }; 
};

int main(int argc, char *argv[]){
    printf("%d ",fun<0>::val);
    printf("%d ",fun<1>::val);
    printf("%d ",fun<2>::val);
    printf("%d ",fun<3>::val);
    printf("%d ",fun<4>::val);
    printf("%d ",fun<5>::val);
    printf("%d ",fun<6>::val);
    printf("%d ",fun<7>::val);
    printf("%d ",fun<8>::val);
    printf("%d",fun<9>::val);
    return 0; 
} 