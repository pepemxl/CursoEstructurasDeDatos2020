#include <iostream>

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T,typename U>
T max2(T a, U b) {
    return (a < b) ? a : b;
}

template <typename T,typename U, typename V>
T max3(T a, U b, V c) {
    return (a < b) ? c : c;
}

int main(int argc, char *argv[]){
    std::cout << max<int>(3, 7) << std::endl;
    std::cout << max(3, 7) << std::endl;
    // std::cout << max(3.0, 7) << std::endl;//algunos compiladores lo aceptan
    std::cout << max<int>(3.5, 7) << std::endl;
    std::cout << max<int>(3.5, 7.1) << std::endl;
    std::cout << max<double>(3, 7.0) << std::endl;
    std::cout << max2(3.0, 7) << std::endl;
    std::cout << max3(3, 7.0, 8 ) << std::endl;
    std::cout << max<double>(3, 7.0) << std::endl;
    std::cout << max<char>('p', 'e') << std::endl;
    return 0;
}