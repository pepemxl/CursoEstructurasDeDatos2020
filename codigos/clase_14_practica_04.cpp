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

//implementar 
/*Algorithm:
Search (ROOT, ITEM)

Step 1: IF ROOT -> DATA = ITEM OR ROOT = NULL
    Return ROOT
   ELSE
   IF ROOT < ROOT -> DATA
   Return search(ROOT -> LEFT, ITEM)
  ELSE
   Return search(ROOT -> RIGHT,ITEM)
  [END OF IF]
  [END OF IF]
Step 2: END
*/
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


//implementar
/*
Algorithm
Delete (TREE, ITEM)

Step 1: IF TREE = NULL
   Write "item not found in the tree" ELSE IF ITEM < TREE -> DATA
  Delete(TREE->LEFT, ITEM)
  ELSE IF ITEM > TREE -> DATA
   Delete(TREE -> RIGHT, ITEM)
  ELSE IF TREE -> LEFT AND TREE -> RIGHT
  SET TEMP = findLargestNode(TREE -> LEFT)
  SET TREE -> DATA = TEMP -> DATA
   Delete(TREE -> LEFT, TEMP -> DATA)
  ELSE
   SET TEMP = TREE
   IF TREE -> LEFT = NULL AND TREE -> RIGHT = NULL
   SET TREE = NULL
  ELSE IF TREE -> LEFT != NULL
  SET TREE = TREE -> LEFT
  ELSE
    SET TREE = TREE -> RIGHT
  [END OF IF]
  FREE TEMP
[END OF IF]
Step 2: END
*/

// implementar

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
        return Search2(currentNode->righ, val, parentNode);
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
        if(currentNode->left == NULL){
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


int main(int argc, char *argv[]){
    Node<int> *root = NULL;
    int A[10] = {43, 10, 79, 90, 12, 54, 11, 9, 50, 44};
    for(int i = 0; i < 9; ++i){
        std::cout << "Insertando: " << A[i] << std::endl;
        root = Insert(root, A[i]);
    }
    std::cout << "InOrden: "  ;
    InOrder(root);
    std::cout << std::endl;
    std::cout << "Borrando 79" << std::endl;
    Delete(root, 79);
    std::cout << "InOrden: "  ;
    InOrder(root);
    std::cout << std::endl; 
    // Ahora borramos 43
    std::cout << "Borrando 43" << std::endl;
    Delete(root, 43);
    std::cout << "InOrden: "  ;
    InOrder(root);
    std::cout << std::endl; 
    return 0;
}