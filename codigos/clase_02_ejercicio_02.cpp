#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX 100

/* En este ejemplo mostramos las 3 maneras de reservar memoria para un arreglo con 100 elementos
el primero es de manera estatica el segundo y tercero de manera dinamica.
*/
int main(int argc, char *argv[]){
    int A[MAX];
    for(int i=0; i < MAX ; ++i){
        A[i] = i;
    }
    printf("A[4]= %d\n", A[4]);
    printf("&(A[4])= %d\n", &A[4]);
    printf("&(A[4])+1= %d\n", &A[4]+1);
    printf("sizeof(int)= %d\n",sizeof(int));
    printf("A[8]=*(&A[4]+sizeof(int))= %d\n", *(&A[4]+sizeof(int)));// tener cuidado al usar * o &
    printf("A[5]=*(&A[4]+1)= %d\n", *(&A[4]+1));    
    return 0;
}