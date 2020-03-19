#include <stdio.h>
#include <stdlib.h>
#include <iostream>

bool PushStack(int *A,int &top, int val){
    top++;
    A[top] = val;
    return true;
}

int PopStack(int *A,int &top){
    int res = A[top];
    top--;
    return res;
}

int PeekStack(int *A,int &top){
    int res = A[top];
    return res;
}

bool PrintStack(int *A, const int &top){
    printf("Imprimiendo lista\n");
    for(int i=0;i <= top;++i){
        printf("A[%d]= %d\n",i,A[i]);
    }
}

int main(int argc, char *argv[]){
    //int A[1000];
    int *A;
    A = new int[1000];
    int top=-1;
    for(int i=0;i < 1000;++i){
        A[i]=-1;
    }
    PushStack(A,top,5);
    PushStack(A,top,6);
    PushStack(A,top,7);
    PushStack(A,top,8);
    PrintStack(A,top);
    std::cout <<"Pop: " << PopStack(A, top) << std::endl;
    PrintStack(A,top);
    std::cout <<"Peek: " << PeekStack(A, top) << std::endl;
    PrintStack(A,top);
    delete[] A;
    return 0;
}
