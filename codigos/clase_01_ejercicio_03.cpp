#include <stdio.h>
#include <iostream>
#include <string>


template <typename T>
void swap2(T &a, T &b){//le llamaremos swap2 por que swap ya existe en C++ cuando inlcluimos iostream
    T temp;
    temp = a;
    a = b;
    b = temp;
    return;
}

/*version alternativa de swap usando operadores de deferenciacion */
template <typename T>
int swap3(T *a, T *b){//le llamaremos swap2 por que swap ya existe en C++ cuando inlcluimos iostream
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

template <typename T>
int bubbleSort(T A[], int n) {
    for ( int i = 0; i < n ; ++i ) {
        for (int j = i + 1; j < n; ++j ) {
            if( A[i] > A[j] ) {
                swap2(A[i], A[j]);
            }
        }
    }
    return 0;
}

template <typename T>
int print(T *A,int n){
    for(int i = 0;i < n; ++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

int main(int argc, char *argv[]){
    double A[]={9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(A)/sizeof(A[0]);
    print(A, n);
    bubbleSort(A,n);
    print(A, n);
    return 0;
}