#include <stdio.h>

template <typename T, int parameter_01> 
int fun(T a) { 
   int m = parameter_01; 
   return a*m;
}

int main(int argc, char *argv[]){
    printf("%d\n", fun<int, 5>(5));
    int i = 5;
    // Si descomentamos la siguiente linea no se comilará
    //printf("%d\n", fun<int, i>(5));
    // Para arreglarlo podemos hacer lo siguiente
    const int i2 = 5;
    printf("%d\n", fun<int, i2>(5));
    return 0;
}