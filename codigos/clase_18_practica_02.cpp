#include <iostream>
#include <limits.h>

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
    // hacemos algo anter de continuar con ambos subarboles
    std::cout << root->data <<  " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

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
    // hacemos algo despues de acabar con el subarbol izquierdo
    std::cout << root->data << " ";
    InOrder(root->right);
}

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
    // hacemos algo despues de haber terminado con ambos subarboles.
    std::cout << root->data << " ";
}


template <typename T>
Node<T> *Search(Node<T> *root, const T &val, Node<T> * &parentNode) {
    Node<T> *currentNode = root;
    Node<T> *tempNode = NULL;
    while(currentNode != NULL && currentNode->data != val){
        tempNode = currentNode;
        if(currentNode->data > val){
            currentNode = currentNode->left;
        }else{
            currentNode = currentNode->right;
        }
    }
    if(currentNode != NULL){
        parentNode = tempNode;
        return currentNode;
    }else{
        return NULL;
    }
}


template <typename T>
T FindMaxVal(Node<T> *root){
    Node<T> *temp = root;
    T val = T(-1);//con siderar no siempre sera posible
    if(temp == NULL){
        return -1;//asumiremos que son puros positivos
    }
    while(temp != NULL){
        val = temp->data;
        temp = temp->right;
    }
    return val;
}

template <typename T>
void Delete(Node<T> *root, const T &val) {
    if(root == NULL){
        return;
    }
    Node<T> *parentNode = NULL;
    Node<T> *currentNode = root;
    currentNode = Search(currentNode, val, parentNode);
    if(currentNode == NULL){
        return;
    }
    //caso 1
    if(currentNode->left == NULL && currentNode->right == NULL){
        if(currentNode == root){
            delete root;
            root = NULL;
        }else{
            if(parentNode->left == currentNode){
                delete currentNode;
                parentNode->left = NULL;
            }else{
                delete currentNode;
                parentNode->right = NULL;
            }
        }
    }
    // caso 2
    if(!(currentNode->left != NULL && currentNode->right != NULL) &&
        (currentNode->left != NULL || currentNode->right != NULL)){
        if(currentNode->left != NULL){
            currentNode->data = currentNode->left->data;
            currentNode->right = currentNode->left->right;
            Node<T> *nodeAux = currentNode->left;//con esto evitamos perder la dirrecion de memoria
            //perdimos la referencia del nodo hijo(que es el que quiero borrar)
            currentNode->left = currentNode->left->left;
            delete nodeAux;
        }else{
            Node<T> *nodeAux = currentNode->right;
            currentNode->data = currentNode->right->data;
            currentNode->left = currentNode->right->left;
            currentNode->right = currentNode->right->right;
            delete nodeAux;
        }

    }
    // caso 3
    if(currentNode->left != NULL && currentNode->right != NULL){
        //intercambiamos por uno anterior en inorden
        T valAux = FindMaxVal(currentNode->left);
        Delete(currentNode->left, valAux);
        currentNode->data = valAux;
    }
}

// version recursiva
template <typename T>
Node<T> *Search2(Node<T> *currentNode, const T &val, Node<T> * &parentNode) {
    if(currentNode == NULL){
        parentNode = NULL;
        return NULL;
    }
    if(currentNode->data == val){
        return currentNode;
    }
    parentNode = currentNode;
    if(currentNode->data > val){
        return Search2(currentNode->left, val, parentNode);
    }else{
        return Search2(currentNode->right, val, parentNode);
    }
}


//version recursiva
template <typename T>
void Delete2(Node<T> *root, const T &val) {
    Node<T> *parentNode = NULL;
    Node<T> *currentNode = root;
    currentNode = Search2(currentNode, val, parentNode);
    if(currentNode == NULL){// caso base
        return;
    }
    //caso 1
    if(currentNode->left == NULL && currentNode->right == NULL){
        if(currentNode != root){
            if(parentNode->left == currentNode){
                parentNode->left = NULL;
            }else{
                parentNode->right = NULL;
            }
        }else{
            root = NULL;
        }
        delete currentNode;
    }
    // caso 3
    else if(currentNode->left != NULL && currentNode->right != NULL){
        T valAux = FindMaxVal(currentNode->left); // tarea crear funcion recursiva para encontrar el valor maximo de un arbol recursivamente
        Delete2(root, valAux);
        currentNode->data = valAux;
    }
    // caso 2
    else{
        Node<T> *childNode = NULL;
        if(currentNode->left != NULL){
            childNode = currentNode->left;
        }else{
            childNode = currentNode->right;
        }
        if (currentNode != root){
            if (parentNode->left == currentNode){
                parentNode->left = childNode;
            }else{
                parentNode->right = childNode;
            }
        } else {
            root = childNode;
        }
        delete currentNode;  
    }
}

// Vamos a construir una funcion recursiva que utilizara el arreglo pre[]. 
// preIndex nos ayudará a mantener la posición actual dentro del arreglo pre[]
// low será el indice menor de creación
// high será el indice mayor de creacion
template <typename T>
Node<T>* CreateTreeFromPreOrder(T pre[], int &preIndex, int key, int low, int high, int &n){
    // Caso Base
    if (preIndex >= n){
        return NULL;  
    } 
    //El primer nodo en preorden siempre es la raiz, creamos el nodo y aumentamos en uno el indice pre
    Node<T>* root = NULL;
    // Si key esta en el rango (low, high) entonces esparte de dicho subarbol
    if(key > low && key < high){
        root = new Node<T>(key);
        preIndex = preIndex + 1;  
        if(preIndex < n){
            root->left  = CreateTreeFromPreOrder(pre, preIndex, pre[preIndex], low, key, n);  
            root->right = CreateTreeFromPreOrder(pre, preIndex, pre[preIndex], key, high, n);  
        }
    }
    return root;  
}

template <typename T>
Node<T>* CreateTreeFromArray(T pre[], int &n){
    if( n == 0 ){
        return NULL;
    }
    int preIndex = 0;
    return CreateTreeFromPreOrder(pre, preIndex, pre[preIndex], INT_MIN, INT_MAX, n);
}

int main(int argc, char *argv[]){
    Node<int> *root = NULL;
    int pre[6] = {10, 5, 1, 7, 40, 50};// supongamos que este es su preorden
    int n = sizeof(pre)/sizeof(pre[0]);// recuerden solo se vale hacer esto si se declaro en el mismo scope
    root = CreateTreeFromArray(pre, n);
    PreOrder(root);
    return 0;
}