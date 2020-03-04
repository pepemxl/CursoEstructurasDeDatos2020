#include <stdio.h>
#include <stdlib.h>
#include <chrono> 
#include <iostream>


#define MAX 1000
//#define MAX 10000
#define N_ITERATIONS 100
#define REP(i, n) for(int i=0, n_=(n);i<n_;++i)

using namespace std; 
using namespace std::chrono;

int main(int argc, char *argv[]){
    float total_time1 = 0;
    float total_time2 = 0;
    int **A;
    A = (int **)malloc(sizeof(int*)*MAX);
    REP(i,MAX){
        A[i] = (int *)malloc(sizeof(int)*MAX);
        REP(j, MAX){
            A[i][j] = 0;
        }
    }
    REP(k,N_ITERATIONS){
        auto start = high_resolution_clock::now(); 
        REP(i,MAX){
            REP(j, MAX){
                A[i][j] += 1;
            }
        }
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);
        total_time1 += duration.count();
    }
    total_time1 /= N_ITERATIONS;
    std::cout << total_time1 << std::endl;
    REP(k,N_ITERATIONS){
        auto start = high_resolution_clock::now(); 
        REP(j,MAX){
            REP(i, MAX){
                A[i][j] += 1;
            }
        }
        auto stop = high_resolution_clock::now(); 
        auto duration = duration_cast<microseconds>(stop - start);
        total_time2 += duration.count();
    }
    total_time2 /= N_ITERATIONS;
    std::cout << total_time2 << std::endl;
    REP(i,MAX){
        free(A[i]);
    }
    free(A);
    return 0;
}

/*
Usando 1000 elementos tenemos la salida:
2903.66
5818.49
Usando 10000 elementos tenemos la salida:
*/