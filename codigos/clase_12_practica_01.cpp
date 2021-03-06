#include <iostream>


template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
        //std::cout << "Creando Nodo" << std::endl;
    }
    ~Node(){
        //std::cout << "Destruyendo Nodo con valor: " << data << std::endl;
    }
    Node(const T &val) {
        data = val;
        left = NULL;
        right = NULL;
        //std::cout << "Creando Nodo con valor: " << data << std::endl;
    }
};

template <typename T>
Node<T>* Insert(Node<T>* root, T data) {
    if(root == NULL) {
        return new Node<T>(data);
    } else {
        Node<T> *newNode;
        if(data <= root->data) {
            newNode = Insert(root->left, data);
            root->left = newNode;
        } else {
            newNode = Insert(root->right, data);
            root->right = newNode;
        }
        return root;
    }
}

// implementar
/*
- Pre-orden:
    - Visitar la raíz.
    - Recorrer el subárbol izquierdo en pre-orden.
    - Recorrer el subárbol derecho en pre-orden.
*/
template <typename T>
void PreOrder(Node<T> *root) {
    if(root == NULL){
        return;
    }
    // hacemos algo
    std::cout << root->data <<  " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

// implementar
/*
- In-orden
    - Recorrer el subárbol izquierdo en entre-orden.
    - Visitar la raíz.
    - Recorrer el subárbol derecho en entre-orden.
*/
template <typename T>
void InOrder(Node<T> *root) {
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    std::cout << root->data << " ";
    InOrder(root->right);
}

// implementar
/*
Post-orden
    - Recorrer el subárbol izquierdo en post-orden.
    - Recorrer el subárbol derecho en post-orden.
    - Visitar la raíz.
*/
template <typename T>
void PostOrder(Node<T> *root) {
    if(root == NULL){
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->data << " ";
}

int main(int argc, char *argv[]){
    Node<int> *root = NULL;
    int A[10] = {5, 3, 8, 4, 2, 1, 7 , 6, 9, 10};
    for(int i = 0; i < 10; ++i){
        root = Insert(root, A[i]);
    }
    std::cout << "PreOrden: " ;
    PreOrder(root);
    std::cout << std::endl;
    std::cout << "InOrden: "  ;
    InOrder(root);
    std::cout << std::endl;
    std::cout << "PostOrden: "  ;
    PostOrder(root);
    return 0;
}