#include <iostream>
#include <stdio.h>
#include <stdlib.h>

template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
        std::cout << "Creando Nodo con valor 0" << std::endl;
    }
    ~Node(){
        std::cout << "Destruyendo Nodo con valor: " << data << std::endl;
    }
    Node(const T &val) {
        data = val;
        left = NULL;
        right = NULL;
        std::cout << "Creando Nodo con valor: " << data << std::endl;
    }
};



int main(int argc, char *argv[]){
    Node<int> *root = new Node<int>(1);// Creamos raiz del arbol
/* El arbol despues de insertar el valor 1 seria el siguiente:
        1 
      /   \ 
    NULL  NULL   
*/
    root->left  = new Node<int>(2); 
    root->right = new Node<int>(3); 
/* 2 y 3 se convierten respectivamente en los hijos izquierdo y derecho
           1 
         /   \ 
        2      3 
      /   \   /  \ 
    NULL NULL NULL NULL 
*/
    root->left->left = new Node<int>(4); 
/* 4 se convierte en el hijo izquierdo del nodo con valor 2 
           1 
        /      \ 
      2         3 
    /   \      /  \ 
   4   NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
    //root->left->left->left = new Node<int>(5); 
    std::cout << root->data << std::endl;
    std::cout << root->left->data << std::endl;
    std::cout << root->right->data << std::endl; 
    std::cout << root->left->left->data << std::endl; 
    //std::cout << root->left->left->left->data << std::endl; 
    //delete root->left->left->left; 
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}


