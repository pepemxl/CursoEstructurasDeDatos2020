#include <stdio.h>


struct Foo{
    int a;
    int b;
};



class CArray{
    int *_A;
    CArray();
    CArray(int A[], int n){
        _A = A;
        _A = new int[n];
        for(int i =0;i < n; ++i){
            _A[i] = A[i];
        }
    }

    ~CArray(){
        delete [] _A;
    }

};


/* Pequeño recordatorio de manejo de memoria */
int main(int argc, char *argv[]){
    Foo p1;// pertenece al stack de memoria del programa (NO LIBERAR!!!)
    int A;
    int arreglo[100];
    CArray lista(arreglo);
    CArray lista2(lista._A);

    delete p1;
    delete A;
    return 0;
}