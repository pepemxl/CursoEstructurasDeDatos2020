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

/*template <typename T>
Node<T> *Search(Node<T> *root, const T &val) {
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(val < root->data){
        return Search(root->left, val);
    }else{
        return Search(root->right, val);
    }
}*/


template <typename T>
Node<T> *Search(Node<T> *root, const T &val) {
    Node<T> *currentNode;
    currentNode = root;
    while(currentNode != NULL && currentNode->data != val){
        if(currentNode->data > val){
            currentNode = currentNode->left;
        }else{
            currentNode = currentNode->right;
        }
    }
    if(currentNode != NULL){
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

template <typename T>
void Delete(Node<T> *root, const T &val) {

    
}

int main(int argc, char *argv[]){
    Node<int> *root = NULL;
    int A[9] = {43, 10, 79, 90, 12, 54, 11, 9, 50};
    for(int i = 0; i < 9; ++i){
        root = Insert(root, A[i]);
    }
    std::cout << "InOrden: "  ;
    InOrder(root);
    std::cout << std::endl;
    Node<int> *temp = Search(root, 45);
    if( temp != NULL ){
        std::cout << temp->data << std::endl;
    }else{
        std::cout << "Este valor no existe" << std::endl;
    }
    temp = Search(root, 50);
    if( temp != NULL ){
        std::cout << "Valor encontrado: " << temp->data << " en direccion: " << temp << std::endl;
    }else{
        std::cout << "Este valor no existe" << std::endl;
    }
    return 0;
}