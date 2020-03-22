#ifndef _CStack_h_
#define _CStack_h_
#include <iostream>


template <typename T>
struct Node{
    T data;
    Node<T> *next;
    Node();
    Node(const T &val);
    ~Node();
};

template<typename T>
class CStack{
private:
    Node<T> *ptrHead;
    int top;
public:
    CStack();
    ~CStack();
    bool Push(const T &val);
    T Pop();
    bool Pop(T &val);
    bool Peek(T &val);
    bool Print();
    bool Clear();
};

template <typename T>
Node<T>::Node(){
    this->data = 0;
    this->next = NULL;
}

template <typename T>
Node<T>::Node(const T &val){
    this->data = val;
    this->next = NULL;
}

template <typename T>
Node<T>::~Node(){
}

template <typename T>
Node<T> *PushFront(Node<T> *ptrHead,const T &val){
    Node<T> *newNode = new Node<T>(val);
    newNode->next = ptrHead;
    return newNode;
}

template <typename T>
Node<T>* PopFront(Node<T> *ptrHead, Node<T>* &ptrPopNode){
    if (ptrHead == NULL){
        std::cout << "Lista vacia operacion no valida" << std::endl;
        return NULL;
    }
    Node<T>* newHead = ptrHead->next;
    ptrPopNode = ptrHead;
    return newHead;
}


template <typename T>
CStack<T>::CStack(){
    top = -1;
    ptrHead = NULL;
}

template <typename T>
CStack<T>::~CStack(){
    this->Clear();

}

template <typename T>
bool CStack<T>::Push(const T &val){
    ptrHead = PushFront(ptrHead, val);
    top++;
    return true;
}

template <typename T>
bool CStack<T>::Pop(T &val){
    if(top == -1){
        std::cout << "Lo sentimos stack vacio" << std::endl;
        return false;
    }
    Node<T> *ptrPopNode;
    ptrHead = PopFront(ptrHead, ptrPopNode);
    val = ptrPopNode->data;
    top--;
    delete ptrPopNode;
    return true;
}

template <typename T>
T CStack<T>::Pop(){
    T result;
    if(top == -1){
        std::cout << "Lo sentimos stack vacio" << std::endl;
        return false;
    }
    Node<T> *ptrPopNode;
    ptrHead = PopFront(ptrHead, ptrPopNode);
    result = ptrPopNode->data;
    top--;
    delete ptrPopNode;
    return result;
}

template <typename T>
bool CStack<T>::Peek(T &val){
    if(top == -1){
        std::cout << "Lo sentimos stack vacio" << std::endl;
        return false;
    }
    if(ptrHead != NULL){
        val = ptrHead->data;
    }
    return true;
}

template <typename T>
bool CStack<T>::Print(){
    Node<T> *ptrNode = this->ptrHead;
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return true;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;
    std::cout << "Imprimiendo lista ligada: ";
    while(tempNode != NULL){
        std::cout << tempNode->data << " ";
         tempNode = tempNode->next;
    }
    std::cout << std::endl;
    return true;
}

template <typename T>
bool CStack<T>::Clear(){
    Node<T> *ptrNode = this->ptrHead;
    if(ptrNode == NULL){
        std::cout << "Liberando stack en destructor: Actualmente NULL " << std::endl;
        return true;
    }
    Node<T> *tempNode, *currentNode;
    tempNode = ptrNode;
    std::cout << "Borrando informacion en stack" << std::endl;
    while(tempNode != NULL){
        currentNode = tempNode;
        tempNode = tempNode->next;
        delete currentNode;
    }
    return true;
}


#endif