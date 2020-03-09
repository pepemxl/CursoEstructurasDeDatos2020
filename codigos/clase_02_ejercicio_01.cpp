#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100

using namespace std; 

/* En este ejemplo mostramos las 3 maneras de reservar memoria para un arreglo con 100 elementos
el primero es de manera estatica el segundo y tercero de manera dinamica.
*/
int main(int argc, char *argv[]){
    int A[MAX];
    int *B;
    int *C;
    B = (int *)malloc(sizeof(int)*MAX);
    C = new int[100];
    for(int i=0; i < MAX ; ++i){
        A[i] = i;
        B[i] = i;
        C[i] = i;
    }
    for(int i=0; i < MAX ; ++i){
        printf("%d %d %d %d\n",i,A[i],B[i],C[i]);
    }
    delete[] C;
    free(B);
    return 0;
}