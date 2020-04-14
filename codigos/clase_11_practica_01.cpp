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
}

template <typename T>
Node<T>* Insert(Node<T>* nodeRoot, const T &val){
    if(nodeRoot == NULL){
        Node<T> *newNode = new Node<T>(val);
        return neNode;
    }
    if(nodeRoot->data <= val)

}


int main(int argc, char *argv[]){
    Node<int> *root;// Creamos raiz del arbol
    root = Insert(root, 1);
  /* El arbol despues de insertar el valor 1 seria el siguiente:
        1 
      /   \ 
     NULL  NULL   
  */
    root->left  = new Node(2); 
    root->right = new Node(3); 
  /* 2 y 3 se convierten respectivamente en los hijos izquierdo y derecho
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root->left->left  = newNode(4); 
  /* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/
  
  getchar(); 
  return 0; 
}
    return 0;
}

