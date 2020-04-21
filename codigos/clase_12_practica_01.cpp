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
template <typename T>
void PreOrder(Node<T> *root) {

}

// implementar
template <typename T>
void InOrder(Node<T> *root) {

}

// implementar
template <typename T>
void PostOrder(Node<T> *root) {

}

int main(int argc, char *argv[]){
    Node<int> *root = NULL;
    int A[10] = {5, 3, 8, 4, 2, 1, 7 , 6, 9, 10};
    /*for(int i = 1; i < 10; ++i){
        root = Insert(root, A[i]);
    }*/
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j){
            std::cout << i << " " << j << std::endl;
            if(j == 5){
                break;
            }
        }
    }
    //PreOrder(root);
    return 0;
}