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
        std::cout << "Nodo Creado" << std::endl;
    }
    Node(T &val){
        this->data = val;
        this->next = NULL;
        std::cout << "Nodo Creado" << std::endl;
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
    Node<T> *newNode = new Node<T>;
    newNode->data = val;
    newNode->next = NULL;
    tempNode = ptrNode;// Inicializamos
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
    return;
}


template <typename T>
void print(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;
    while(tempNode != NULL){
        std::cout << tempNode->data << " ";
         tempNode = tempNode->next;
    }
    std::cout << std::endl;
    return;
}

template <typename T>
void clear(Node<T> *ptrNode){
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
    Node<T> *newNode = new Node<T>;
    newNode->data = val;
    newNode->next = ptrHead;
    return newNode;
}

template <typename T>
Node<T> *Insert(Node<T> *ptrHead,const T &val, int pos){
    if(pos == 0){
        ptrHead = PushFront(ptrHead,val);
        return ptrHead;
    }
    int contador = 0;
    Node<T> *tempNode = ptrHead;
    Node<T> *prevNode = tempNode;
    while(tempNode != NULL && contador < pos){
        prevNode = tempNode;
        tempNode = tempNode->next;
        contador++;
    }
    if(contador == pos){
        Node<T> *newNode = new Node<T>;
        newNode->data = val;
        newNode->next = tempNode;
        prevNode->next = newNode;
        std::cout << "El valor lista[" << pos <<"] es: "   << tempNode->data << std::endl;
        std::cout << "El valor lista[prevNode] es: "   << prevNode->data << std::endl;
    }else{
        std::cout << "Posicion no encontrada" << std::endl;
    }
    return tempNode;
}


int main(int argc, char *argv[]){
    Node<int> *lista;
    lista = new Node<int>;
    lista->data = 0;
    lista->next = NULL;
    for(int i=1; i <= 9; ++i){
        PushBack<int>(lista, i);
    }
    std::cout << lista->data << std::endl;
    Node<int> *tempNode = lista->next;
    std::cout << tempNode->data << std::endl;
    tempNode = tempNode->next;
    std::cout << tempNode->data << std::endl;
    /*lista = Insert(lista, 100, 0);
    print(lista);*/
    clear(lista);
    return 0;
}
