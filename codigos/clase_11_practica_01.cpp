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
bool Insert(Node<T>* &nodeRoot, const T &val){
    if(nodeRoot == NULL){
        Node<T> *newNode = new Node<T>(val);
        nodeRoot = newNode;
        return true;
    }
    // como ejercicio de la clase implementaran el resto de la función insert
    if(nodeRoot->left == NULL){
        std::cout << "Aqui estamos" << std::endl;
        Node<T> *newNode = new Node<T>(val);
        nodeRoot->left = newNode;
        return true;
    }else{
        Node<T> *newNode = new Node<T>(val);
        nodeRoot->right = newNode;
        return true;
    }
    return false;
}


int main(int argc, char *argv[]){
    Node<int> *root;// Creamos raiz del arbol
    root = NULL;
    Insert(root, 1);
  /* El arbol despues de insertar el valor 1 seria el siguiente:
        1 
      /   \ 
     NULL  NULL   
  */
    Insert(root, 2);
    Insert(root, 3);
  /* 2 y 3 se convierten respectivamente en los hijos izquierdo y derecho
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  //root = Insert(root, 4);
  /* 4 se convierte en el hijo izquierdo del nodo con valor 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
   //root = Insert(root, 5);
  /* 5 se convierte en el hijo derecho del nodo con valor 2 
           1 
       /       \ 
      2          3 
    /     \       /  \ 
   4         5  NULL  NULL 
  /  \      /  \ 
NULL NULL  NULL NULL
*/
    std::cout << root->data << std::endl;
    std::cout << root->left->data << std::endl;
    std::cout << root->right->data << std::endl; 
    //std::cout << root->left->left->data << std::endl;
    //delete root->left->left->left;
    //delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;
    return 0;
}


