#include <iostream>
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
        std::cout << "Creando Nodo" << std::endl;
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

template <typename T>
Node<T>* Insert(Node<T>* nodeRoot, const T &val){
    if(nodeRoot == NULL){
        Node<T> *newNode = new Node<T>(val);
        return newNode;
    }
    // como ejercicio de la clase implementaran el resto de la función insert
}


int main(int argc, char *argv[]){
    Node<int> *root;// Creamos raiz del arbol
    root = Insert(root, 1);
  /* El arbol despues de insertar el valor 1 seria el siguiente:
        1 
      /   \ 
     NULL  NULL   
  */
    root = Insert(root, 2);
    root = Insert(root, 3);
  /* 2 y 3 se convierten respectivamente en los hijos izquierdo y derecho
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root = Insert(root, 4);
  /* 4 se convierte en el hijo izquierdo del nodo con valor 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}


