#include <iostream>

int H(int x){
    return x%10;
}

void Convierte(int A[], int B[], int n){
    int indice = 0;
    for(int i = 0; i < n; ++i){//i = 0 // i = 4
        indice = H(A[i]);// H(A[0]) = H(11) = 1// H(A[4]) = H(15)=5
        B[indice] = A[i];//B[1] = 11//B[5] = 14
    }
}

void PrintArray(int A[], int n){
    for (int i =0;i < n;++i){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    return;
}
// {0,1,2,3,4,5,6,7,8,9}
int main(int argc, char *argv[]){
    //int A[] = {11, 12, 13, 14, 15};
    int A[] = {11, 12, 13, 14, 15, 22, 27, 105, 108};
    int n = sizeof(A)/sizeof(A[0]);
    int *B = new int[10]; // {0,1,2,3,4,5,6,7,8,9}
    for(int i = 0; i < 10;++i){
        B[i] = -1;
    }
    std::cout << "lista de size " << n << std::endl;
    PrintArray(A, n);
    Convierte(A, B, n);
    PrintArray(B, 10);
    // 0 , 1 ,  2,  3,  4,  5,  6,  7,  8,  9
    // -1, 11, 22, 13, 14, 15, -1, 27, 108, -1
    delete[] B;
    return 0;
}

