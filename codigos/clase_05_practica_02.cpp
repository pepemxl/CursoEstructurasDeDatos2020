#include <stdio.h>
#include <iostream>

/*
    implementar un stack utilizando listas ligadas
*/

template <typename T>
struct Node{
    T data;
    Node<T> *next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(const T &val){
        this->data = val;
        this->next = NULL;
    }
    ~Node(){
    }
};

template <typename T>
Node<T> *PushVersion01(Node<T> *ptrHead,Node<T> * &ptrTop,int &top, const T &val){
    if(top == -1){
        Node<T> *newNode = new Node<T>(val);
        ptrTop = newNode;
        top++;
        return newNode;
    }
    Node<T> *newNode = new Node<T>(val);
    ptrTop->next = newNode;
    ptrTop = newNode;
    top++;
    return ptrHead;
}

template <typename T>
void Print(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;
    std::cout << "Imprimiendo lista ligada: ";
    while(tempNode != NULL){
        std::cout << tempNode->data << " ";
         tempNode = tempNode->next;
    }
    std::cout << std::endl;
    return;
}

template <typename T>
void Clear(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << "Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode, *currentNode;
    tempNode = ptrNode;// Inicializamos
    while(tempNode != NULL){
        currentNode = tempNode;
        tempNode = tempNode->next;
       // std::cout << "Borrado " << currentNode->data << std::endl;
        delete currentNode;
    }
  //  std::cout << "Lista limpia" << std::endl;
    return;
}

template <typename T>
Node<T> *PushFront(Node<T> *ptrHead,const T &val){//ptrHead = NULL
    Node<T> *newNode = new Node<T>(val);
    newNode->next = ptrHead;//NULL
    std::cout << "Nodo insertado al inicio con valor: "   << newNode->data << std::endl;
    return newNode;
}

//push, pop, peek
template <typename T>
bool Push(Node<T> * &ptrHead,int &top, const T &val){
    ptrHead = PushFront(ptrHead, val);
    top++;
    return true;
}

template <typename T>
Node<T>* PopFront(Node<T> *ptrHead, Node<T>* &ptrPopNode){
    if (ptrHead == NULL){
        std::cout << "Lista vacia operacion no valida" << std::endl;
        return NULL;
    }
    Node<T>* newHead = ptrHead->next;
    std::cout << "Primer Elemento: " << ptrHead->data << std::endl;
    ptrPopNode = ptrHead;
    return newHead;
}

template <typename T>
bool Pop(Node<T> * &ptrHead,int &top, T &val){
    if(top == -1){
        std::cout << "Lo sentimos stack vacio" << std::endl;
        return false;
    }
    Node<T> *ptrPopNode;
    ptrHead = PopFront(ptrHead, ptrPopNode);
    std::cout << "Pop: " << ptrPopNode->data << std::endl;
    val = ptrPopNode->data;
    top--;
    delete ptrPopNode;
    return true;
}

template <typename T>
bool Peek(Node<T> *ptrHead,int &top, T &val){
    if(top == -1){
        std::cout << "Lo sentimos stack vacio" << std::endl;
        return false;
    }
    if(ptrHead != NULL){
        std::cout << "Peek: " << ptrHead->data << std::endl;
        val = ptrHead->data;
    }
    return true;
}


int main(){
    int top = -1;
    int valor;
    Node<int> *ptrHead = NULL;
    /*Node<int> *ptrTop = NULL;
    ptrHead = PushVersion01(ptrHead, ptrTop, top, 3);
    ptrHead = PushVersion01(ptrHead, ptrTop, top, 4);
    ptrHead = PushVersion01(ptrHead, ptrTop, top, 5);*/
    Push(ptrHead, top, 3) ;
    Push(ptrHead, top, 4) ;
    Push(ptrHead, top, 5) ;
    Print(ptrHead);
    Pop(ptrHead, top, valor);
    std::cout << "Valor recuperado: " << valor << std::endl;
    Print(ptrHead);
    Peek(ptrHead, top, valor);
    std::cout << "Valor recuperado: " << valor << std::endl;
    Print(ptrHead);
    Clear(ptrHead);
    // prueben insertando 1000 elementos;
    // prueben haciendo pop de los 1000 elementos;
    // hagan 3 peek
    return 0;
}