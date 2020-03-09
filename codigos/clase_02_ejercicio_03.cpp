#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
struct Node{
    T data;
    Node *next;
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
        std::cout << tempNode->data << std::endl;
         tempNode = tempNode->next;
    }
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
        delete currentNode;
    }
    std::cout << "Lista limpia" << std::endl;
    return;
}


int main(int argc, char *argv[]){
    Node<int> *lista;
    lista = new Node<int>;
    lista->data = 0;
    lista->next = NULL;
    for(int i=1; i < 10; ++i){
        PushBack<int>(lista, i);
    }
    print(lista);
    clear(lista);
    return 0;
}