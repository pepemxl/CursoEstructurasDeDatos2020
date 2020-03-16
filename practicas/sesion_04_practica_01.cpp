#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
struct Node{
    T data;
    Node *next;
    Node(){
        this->data = 0;
        this->next = NULL;
        std::cout << "Nodo creado con valor por defecto 0" << std::endl;
    }
    Node(const T &val){
        this->data = val;
        this->next = NULL;
        std::cout << "Nodo creado con valor " << val << std::endl;
    }
};

template <typename T>
struct ListaLigada{
    T data;
    Node<T> *next;
    ListaLigada(){
        this->data = 0;
        this->next = NULL;
    }
    ListaLigada(const T &input){
        this->data = input;
        this->next = NULL;
    }
};

template <typename T>
void PushBack(Node<T> *ptrNode, const T &val){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;// Inicializamos
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    // Factorizamos codigo agregando constructor con valor inicial
    // Node<T> *newNode = new Node<T>;
    // newNode->data = val;
    // newNode->next = NULL;
    Node<T> *newNode = new Node<T>(val);
    tempNode->next = newNode;
    return;
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
Node<T> *PushFront(Node<T> *ptrHead,const T &val){
    Node<T> *newNode = new Node<T>(val);
    newNode->next = ptrHead;
    std::cout << "Nodo insertado al inicio con valor: "   << newNode->data << std::endl;
    return newNode;
}

template <typename T>
Node<T> *Insert(Node<T> *ptrHead,const T &val, int pos){
    if(pos == 0){
        ptrHead = PushFront(ptrHead,val);
        return ptrHead;
    }
    // Ahora buscamos nodo en ubicación(pos>0) a remplazar(logica 0)
    int contador = 0;
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    Node<T> *prevNode = tempNode;
    while(tempNode != NULL && contador < pos){
        prevNode = tempNode;
        tempNode = tempNode->next;
        contador++;
    }
    if(contador == pos){
        std::cout << "El valor lista[" << pos <<"] es: "   << tempNode->data << std::endl;
        std::cout << "El valor lista[prevNode] es: "       << prevNode->data << std::endl;
        Node<T> *newNode = new Node<T>(val);
        newNode->next = tempNode;
        prevNode->next = newNode;
    }else{
        std::cout << "Posición no encontrada" << std::endl;
    }
    return ptrHead;
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
Node<T> *Pop(Node<T> *ptrHead, Node<T>* &ptrPopNode, int pos){
    if(pos == 0){
        ptrHead = PopFront(ptrHead, ptrPopNode);
        return ptrHead;
    }
    // Ahora buscamos nodo en ubicación(pos>0) a remplazar(logica 0)
    int contador = 0;
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    Node<T> *prevNode = tempNode;
    while(tempNode != NULL && contador < pos){
        prevNode = tempNode;
        tempNode = tempNode->next;
        contador++;
    }
    if(contador == pos){
        std::cout << "El valor lista[" << pos <<"] es: "   << tempNode->data << std::endl;
        std::cout << "El valor lista[prevNode] es: "       << prevNode->data << std::endl;
        ptrPopNode = tempNode;
        prevNode->next = tempNode->next;
    }else{
        std::cout << "Posición no encontrada" << std::endl;
    }
    return ptrHead;
}

int main(int argc, char *argv[]){
    Node<int> *ptrHead;// Apuntador a la cabeza de la lista
    Node<int> *ptrTemp;// Apuntador auxiliar
    ptrHead = new Node<int>(0);
    for(int i=1; i <= 9; ++i){
        PushBack<int>(ptrHead, i);
    }
    ptrHead = Insert(ptrHead, 100, 0);
    ptrHead = Insert(ptrHead, 101, 1);
    ptrHead = Insert(ptrHead, 102, 5);
    Print(ptrHead);
    std::cout << "Eliminando primer elemento ... "<< std::endl;
    ptrHead = PopFront(ptrHead, ptrTemp);
    std::cout << "Elemento recuperado:  "<< ptrTemp->data << std::endl;
    free(ptrTemp);
    Print(ptrHead);
    std::cout << "Eliminando nodo 5 ... "<< std::endl;
    ptrHead = Pop(ptrHead, ptrTemp, 5);
    std::cout << "Elemento recuperado:  "<< ptrTemp->data << std::endl;
    free(ptrTemp);
    Print(ptrHead);
    Clear(ptrHead);
    return 0;
}
