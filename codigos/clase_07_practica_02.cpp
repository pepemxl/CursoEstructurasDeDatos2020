#include <iostream>
#include <stdlib.h>
#include <time.h>


template <typename T, int S>
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
    static const int iMax = S;
private:
    T m_array[iMax];
    int m_iFront;
    int m_iRear;
};

template <typename T, int S>
CQueue<T,S>::CQueue(){
    m_iFront = -1;
    m_iRear = -1;
    std::cout << "Queue creado con memoria "<< iMax << std::endl;
}

template <typename T, int S>
CQueue<T, S>::~CQueue(){
    std::cout << "Queue liberado" << std::endl;
}

int main(int argc, char *argv[]){
    CQueue<int, 5> myQueue;
    CQueue<int, 50> myQueue2;
    return 0;
}