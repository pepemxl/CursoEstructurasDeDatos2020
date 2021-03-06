#include <iostream>
#include <limits.h>
#include <vector>

template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;
    int factor=0;
    int height=1;
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
    // std::cout << "preindex " << preIndex << std::endl;
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

template <typename T>
int ComputeHeight(Node<T>* root){
    if(root == NULL){
        return 0;
    }
    int L_height = ComputeHeight(root->left);
    int R_height = ComputeHeight(root->right);
    int height = 0;
    if(L_height > R_height){
        height = L_height + 1;
    }else{
        height = R_height + 1;
    }
    root->height = height;
    root->factor = L_height - R_height;
    return height;
}

template <typename T>
void PreOrderWithFactor(Node<T> *root) {
    if(root == NULL){
        return;
    }
    // hacemos algo anter de continuar con ambos subarboles
    std::cout << root->data <<  ".factor(" << root->factor << ") ";
    PreOrderWithFactor(root->left);
    PreOrderWithFactor(root->right);
}

template <typename T>
void PreOrderWithHeight(Node<T> *root) {
    if(root == NULL){
        return;
    }
    // hacemos algo anter de continuar con ambos subarboles
    std::cout << root->data <<  ".height(" << root->height << ") ";
    PreOrderWithHeight(root->left);
    PreOrderWithHeight(root->right);
}


int Max(int a, int b){  
    return (a > b)? a : b;  
}  

template <typename T>
int GetNodeHeight(Node<T>* node){  
    if(node == NULL){
        return 0;
    }
    return node->height;  
} 

/* Estructura basica de Rotacion Derecha y Rotacion Izquierda
T1, T2 y T3 son subarboles del arbol con raiz "y" en el arbol a la izquieda
"x" en el arbol de la dereacho respectivamente
     y                               x
    / \     Rotacion Derecha        /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Rotacion Izquierda        T2  T3
Los valores data en cada nodo cumplen lo siguiente
 data(T1) < data(x) < data(T2) < data(y) < data(T3)
*/

template <typename T>
Node<T>* RightRotate(Node<T>* y){
    // guardamos referencias temporales a sus hijos
    Node<T> *x  = y->left;
    Node<T> *T2 = x->right;  
    // hacemos rotacion
    x->right = y;
    y->left = T2;
    //actualizamos raiz al salir
    return x;
} 

/*  Caso LL
T1, T2, T3 y T4 son subarboles.
         z                                      y 
        / \                                   /   \
       y   T4      Rotacion derecha (z)      x      z
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
*/

/* Estructura basica de Rotacion Derecha y Rotacion Izquierda
T1, T2 y T3 son subarboles del arbol con raiz "y" en el arbol a la izquieda
"x" en el arbol de la dereacho respectivamente
     y                               x
    / \     Rotacion Derecha        /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Rotacion Izquierda        T2  T3
Los valores data en cada nodo cumplen lo siguiente
 data(T1) < data(x) < data(T2) < data(y) < data(T3)
*/
template <typename T>
Node<T>* LeftRotate(Node<T>* x){
    // creamos temporales de nodos a mover
    Node<T> *y = x->right;
    Node<T> *T2 = y->left;
    // Realizamos el cambio
    y->left = x;
    x->right = T2;
    // Actualizar raiz
    return y; 
}
// uso z = LeftRotate(z)
/* Caso RR donde z es el nodo critico
  z                                  y
 /  \                              /   \ 
T1   y     Rotacion Izquierda(z)  z      x
    /  \   - - - - - - - - ->    / \    / \
   T2   x                       T1  T2 T3  T4
       / \
     T3  T4
*/


/* Caso LR
     z                               z                           x
    / \                            /   \                        /  \ 
   y   T4  Rotacion Izquierda (y) x    T4  Rotacion Derecha(z) y      z
  / \      - - - - - - - - ->    /  \      - - - - - - - ->   / \    / \
T1   x                          y    T3                      T1  T2 T3  T4
    / \                        / \
  T2   T3                    T1   T2
*/
template <typename T>
Node<T>* LeftRightRotate(Node<T> *z){
    Node<T> *y = z->left;// L
    //y = LeftRotate(y);
    z->left = LeftRotate(z->left);
    Node<T> *x = RightRotate(z);
    return x;  
}  



/* Caso RL
   z                            z                              x
  / \                          / \                            /  \ 
T1   y   Rotacion Derecha(y)  T1   x   Rotación Izquierda(z) z      y
    / \  - - - - - - - - ->     /  \   - - - - - - - - - >  / \    / \
   x   T4                      T2   y                      T1  T2  T3  T4
  / \                              /  \
T2   T3                           T3   T4
*/

template <typename T>
Node<T>* RightLeftRotate(Node<T> *z){
    //Node<T> *y = z->right;
    z->right = RightRotate(z->right);
    Node<T> *x = LeftRotate(z);
    return x;  
}  

template <typename T>
int GetMaxHeight(Node<T> *root){
    int height = 0;
    if(root == NULL){
        return height;
    }
    int L_height = GetMaxHeight(root->left);
    int R_height = GetMaxHeight(root->right);
    if(L_height > R_height){
        height = L_height + 1;
    }else{
        height = R_height + 1;
    }
    return height;
}

template <typename T>
void PrintLevel(Node<T> *root,int level,int current_level){
    if(root == NULL){
        return;
    }
    if(current_level == level){
        std::cout << root->data << " ";
    }
    if(current_level < level){
        current_level += 1;
        PrintLevel(root->left, level, current_level);
        PrintLevel(root->right, level, current_level);
    }
    return;
}

template <typename T>
void LevelOrder(Node<T> *root) {
    if(root == NULL){
        return;
    }
    int max_height = GetMaxHeight(root);
    int contador = 0;
    while(contador < max_height){
        PrintLevel(root, contador, 0);
        contador++;
    }
}

// only for BST trees
template <typename T>
void FindAncestorList(Node<T> *root, int val, std::vector<T> &myvector) {
    if(root == NULL){
        return;
    }
    Node<T> *temp = root;
    while(temp !=NULL){
        myvector.push_back(temp->data);
        if(temp->data == val){
            break;
        }
        if(temp->data > val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
}

template <typename T>
Node<T> *FindNodeVal(Node<T> *root, int val) {
    if(root == NULL){
        return NULL;
    }
    Node<T> *temp = root;
    while(temp !=NULL){
        if(temp->data == val){
            return temp;
        }
        if(temp->data > val){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return NULL;
}

template <typename T>
Node<T> *LowestCommonAncestor(Node<T> *root, int v1,int v2) {
     std::vector<T> myvector_val1;
     std::vector<T> myvector_val2;
     FindAncestorList(root,v1, myvector_val1);
     FindAncestorList(root,v2, myvector_val2);
     int n = myvector_val1.size();
     int m = myvector_val2.size();
     /*for(int i = 0; i < n;i++){
         std::cout << 
     }*/
     for(int i = n-1; i >= 0; --i){
         for(int j = m-1; j >= 0; --j){
             if(myvector_val1[i] == myvector_val2[j]){
                return FindNodeVal(root, myvector_val1[i]);
             }
         }
     }
     return NULL;
}

int main(int argc, char *argv[]){
    Node<int> *root = NULL;
    //int pre[] = {4, 2, 1, 3, 7, 6};// supongamos que este es su preorden
    //int pre[] = {9,7,5,4,3,1,6,8};// caso 2
    int pre[] = {1,2};// caso 3
    int n = sizeof(pre)/sizeof(pre[0]);// recuerden solo se vale hacer esto si se declaro en el mismo scope
    std::cout << n << " nodos"<< std::endl;
    root = CreateTreeFromArray(pre, n);
    std::cout << "PreOrder  : ";
    PreOrder(root);
    std::cout << std::endl;
    int val1 = 1;
    //int val2 = 7;
    //int val2 = 6;//caso 2
    int val2 = 2;//caso 3
    Node<int> *sol = LowestCommonAncestor(root, val1, val2);
    std::cout << sol->data << std::endl;
    return 0;
}