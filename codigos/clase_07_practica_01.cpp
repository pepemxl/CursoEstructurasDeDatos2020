#include <iostream>
#include <stdlib.h>
#include <time.h>


template <typename T>
class CQueue{
public:
    CQueue();
    CQueue(int iMax);
    CQueue(int iMax, T *array, int nArray);
    ~CQueue();
    bool Push(const T &val);
    T Pop();
    bool Print();
    int GetSize();
private:
    T *m_array;
    int m_iMax;
    int m_iFront;
    int m_iRear;
};

template <typename T>
CQueue<T>::CQueue(){
    m_iMax = 100;
    m_iFront = -1;
    m_iRear = -1;
    m_array = new T[m_iMax];
    std::cout << "Queue creado con memoria "<< m_iMax << std::endl;
}

template <typename T>
CQueue<T>::~CQueue(){
    if(m_array){
        delete []m_array;
        std::cout << "Queue liberado" << std::endl;
    }
}

template <typename T>
CQueue<T>::CQueue(int iMax){
    m_iMax = iMax;
    m_iFront = -1;
    m_iRear = -1;
    m_array = new T[m_iMax];
    std::cout << "Queue creado con memoria "<< m_iMax << std::endl;
}

template <typename T>
CQueue<T>::CQueue(int iMax, T *array, int nArray){
    if(nArray > iMax){
        std::cout << "Hay un error no podemos guardar esa lista en una cola con menos capacidad" << std::endl;
        return;
    }
    m_iMax = iMax;
    m_iFront = -1;
    m_iRear = -1;
    m_array = new T[m_iMax];
    for(int i = 0; i < nArray;++i){
        std::cout << "enQueue:" << array[i] << std::endl;
        this->Push(array[i]);
    }
    std::cout << "Queue creado con memoria "<< m_iMax << std::endl;
}

template <typename T> 
bool CQueue<T>::Push(const T &val){
    if(m_iFront == -1 && m_iRear == -1){//vamos a asumir que tenemos suficiente memoria
        m_iFront = 0;
        m_iRear = 0;
    }else if(m_iRear >= m_iFront){// siempre se cumple para queue simples
        m_iRear++;
    }
    if(m_iRear >= m_iMax){
        std::cout << "Has llegado al limite del queue, ya no se pueden agregar mas" << std::endl;
        return false;
    }
    m_array[m_iRear] = val;
    return true;
}

template <typename T> 
int CQueue<T>::GetSize(){
    int size;
    size = m_iRear-m_iFront+1;
    return size;
}


template <typename T> 
T CQueue<T>::Pop(){
    T temp;
    if(m_iFront == -1 && m_iRear == -1){//vamos a asumir que tenemos suficiente memoria
        std::cout << "El arreglo esta vacio, NO puedes realizar un POP" << std::endl;
        return T(0);
    }
    temp = m_array[m_iFront];
    if(m_iFront == m_iRear){
        m_iFront = -1;
        m_iRear = -1;
    }else{
        m_iFront++;
    }
    return temp;
}

template <typename T> 
bool CQueue<T>::Print(){
    int size = GetSize();
    for(int i = m_iFront; i <= m_iRear; ++i){
        std::cout << m_array[i] << " ";
    } 
    std::cout << std::endl;
    return true;
}

int main(int argc, char *argv[]){
    srand(0);
    //srand(time(0));
    CQueue<int> myQueue;
    CQueue<int> myQueue2(1000);
    int *A;
    A = new int[50];
    for(int i = 0 ;i < 50;++i){
        A[i] = rand()%100;
    }
    for(int i = 0; i < 50; ++i){
        std::cout << A[i] << " ";
    }    
    std::cout << std::endl;

    CQueue<int> myQueue3(100, A, 50);
    std::cout << "Size: " << myQueue3.GetSize() << std::endl;
    myQueue3.Print();
    for(int i = 0; i < 50;++i){
        std::cout << "Pop: " << myQueue3.Pop() << std::endl;
        std::cout << "Size: " << myQueue3.GetSize() << std::endl;
        myQueue3.Print();
    }
    std::cout << "Pop: " << myQueue3.Pop() << std::endl;
    myQueue3.Print();
    if(A){
        delete[]A;
        std::cout << "Liberando A" << std::endl;
    }
    return 0;
}
