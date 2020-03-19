#include <stdio.h>
#include <stdlib.h>
#include <iostream>

template <typename T>
struct Node{
    T data;
//    static int contador = 0;
    char* nombre="JUAN";
    Node<T> *next;
    Node(){
        this->data = 0;
        this->next = NULL;
        std::cout << "Nodo creado con valor por defecto 0" << std::endl;
    }
    Node(const T &val){
        this->data = val;
        this->next = NULL;
        std::cout << "Nodo creado con valor " << val << std::endl;
    }
    ~Node(){
        std::cout << "Nodo Borrado" << std::endl;
    }
};

template <typename T>
struct ListaLigada{
    T data;
    Node<T> *next;
    ListaLigada(){
        this->data = 0;
        this->next = NULL;
    }
    ListaLigada(const T &input){
        this->data = input;
        this->next = NULL;
    }
};

template <typename T>
void PushBack(Node<T> *ptrNode, const T &val){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;// Inicializamos
    while(tempNode->next != NULL){
        tempNode = tempNode->next;
    }
    // Factorizamos codigo agregando constructor con valor inicial
    // Node<T> *newNode = new Node<T>;
    // newNode->data = val;
    // newNode->next = NULL;
    Node<T> *newNode = new Node<T>(val);
    tempNode->next = newNode;
    return;
}

template <typename T>
void Print(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << " Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode;
    tempNode = ptrNode;
    std::cout << "Imprimiendo lista ligada: ";
    while(tempNode != NULL){
        std::cout << tempNode->data << " ";
         tempNode = tempNode->next;
    }
    std::cout << std::endl;
    return;
}

template <typename T>
void Clear(Node<T> *ptrNode){
    if(ptrNode == NULL){
        std::cout << "Ptr NULL" << std::endl;
        return;
    }
    Node<T> *tempNode, *currentNode;
    tempNode = ptrNode;// Inicializamos
    while(tempNode != NULL){
        currentNode = tempNode;
        tempNode = tempNode->next;
       // std::cout << "Borrado " << currentNode->data << std::endl;
        delete currentNode;
    }
  //  std::cout << "Lista limpia" << std::endl;
    return;
}

template <typename T>
Node<T> *PushFront(Node<T> *ptrHead,const T &val){
    Node<T> *newNode = new Node<T>(val);
    newNode->next = ptrHead;
    std::cout << "Nodo insertado al inicio con valor: "   << newNode->data << std::endl;
    return newNode;
}

template <typename T>
Node<T> *Insert(Node<T> *ptrHead,const T &val, int pos){
    if(pos == 0){
        ptrHead = PushFront(ptrHead,val);
        return ptrHead;
    }
    // Ahora buscamos nodo en ubicaci�n(pos>0) a remplazar(logica 0)
    int contador = 0;
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    Node<T> *prevNode = tempNode;
    while(tempNode != NULL && contador < pos){
        prevNode = tempNode;
        tempNode = tempNode->next;
        contador++;
    }
    if(contador == pos){
        std::cout << "El valor lista[" << pos <<"] es: "   << tempNode->data << std::endl;
        std::cout << "El valor lista[prevNode] es: "       << prevNode->data << std::endl;
        Node<T> *newNode = new Node<T>(val);
        newNode->next = tempNode;
        prevNode->next = newNode;
    }else{
        std::cout << "Posici�n no encontrada" << std::endl;
    }
    return ptrHead;
}

template <typename T>
Node<T>* PopFront(Node<T> *ptrHead, Node<T>* &ptrPopNode){
    if (ptrHead == NULL){
        std::cout << "Lista vacia operacion no valida" << std::endl;
        return NULL;
    }
    Node<T>* newHead = ptrHead->next;
    std::cout << "Primer Elemento: " << ptrHead->data << std::endl;
    ptrPopNode = ptrHead;
    return newHead;
}

template <typename T>
Node<T> *Pop(Node<T> *ptrHead, Node<T>* &ptrPopNode, int pos){
    if(pos == 0){
        ptrHead = PopFront(ptrHead, ptrPopNode);
        return ptrHead;
    }
    // Ahora buscamos nodo en ubicaci�n(pos>0) a remplazar(logica 0)
    int contador = 0;
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    Node<T> *prevNode = tempNode;
    while(tempNode != NULL && contador < pos){
        prevNode = tempNode;
        tempNode = tempNode->next;
        contador++;
    }
    if(contador == pos){
        std::cout << "El valor lista[" << pos <<"] es: "   << tempNode->data << std::endl;
        std::cout << "El valor lista[prevNode] es: "       << prevNode->data << std::endl;
        ptrPopNode = tempNode;
        prevNode->next = tempNode->next;
    }else{
        std::cout << "Posici�n no encontrada" << std::endl;
        ptrPopNode = NULL;
    }
    return ptrHead;
}


template <typename T>
Node<T> *PopBack(Node<T> *ptrHead, Node<T>* &ptrPopNode){
    if(ptrHead == NULL){
        ptrPopNode = NULL;
        std::cout << "Error lista vacia" << std::endl;
        return NULL;
    }
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    Node<T> *prevNode = tempNode;
    while(tempNode->next != NULL){
        prevNode = tempNode;
        tempNode = tempNode->next;
    }
    std::cout << "El valor lista[ultimo] es: "         << tempNode->data << std::endl;
    std::cout << "El valor lista[prevNode] es: "       << prevNode->data << std::endl;
    ptrPopNode = tempNode;
    prevNode->next = NULL;
    return ptrHead;
}


template <typename T>
Node<T> *Position(Node<T> *ptrHead, int pos){
    if(ptrHead == NULL){
        std::cout << "Error lista vacia" << std::endl;
        return ptrHead;
    }
    if(pos < 0){
        std::cout << "Posicion invalida" << std::endl;
    }
    if(pos == 0){
        return ptrHead;
    }
    // Ahora buscamos nodo en ubicaci�n(pos>0) a remplazar(logica 0)
    int contador = 0;
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    Node<T> *prevNode = tempNode;
    while(tempNode != NULL && contador < pos){
        prevNode = tempNode;
        tempNode = tempNode->next;
        contador++;
    }
    if(contador == pos){
        std::cout << "El valor lista[" << pos <<"] es: "   << tempNode->data << std::endl;
        std::cout << "El valor lista[prevNode] es: "       << prevNode->data << std::endl;
        return tempNode;
    }else{
        std::cout << "Posici�n no encontrada" << std::endl;
        return NULL;
    }
}

//  0  1 2 3  4  5 6 7 8 9
// 101 0 1 2 102 4 5 6 7 8
template <typename T>
int Search(Node<T> *ptrHead,const T &val){
    int posicion = 0;
    if(ptrHead == NULL){
        posicion = -1;
        std::cout << "Error lista vacia" << std::endl;
        return posicion;
    }
    Node<T> *tempNode = ptrHead;//creamos nodo temporal para hacer el recorrido
    while(tempNode != NULL && tempNode->data != val){
        tempNode = tempNode->next;
        posicion++;
    }
    if (tempNode == NULL || tempNode->data != val){
        std::cout << "Valor no encontrado en lista!" << std::endl;
        posicion = -1;
    }
    return posicion;
}

/*template<typename T>
Node<T>& Node<T>::operator[](int index){
    std::cout << "aqui vamos"<< std::endl;
    return *this;
    //return Position(*this, index);
}*/

// Propuesta de Push dada por uno de los estudiantes
// Buena idea solo tener encuenta performance de la funcion
bool PushStack(int *A,int MAX, int val){
    int contador = 0;
    while(A[contador]!=-1 && contador < MAX){
        contador++;
    }
    A[contador] = val;
    return true;
}

bool PushStack2(int *A,int &top, int val){
    top++;
    A[top] = val;
    return true;
}

int PopStack(int *A,int &top){
    int res = A[top];
    top--;
    return res;
}

bool PrintStack(int *A, const int &top){
    printf("Imprimiendo lista\n");
    for(int i=0;i <= top;++i){
        printf("A[%d]= %d\n",i,A[i]);
    }
}

int main(int argc, char *argv[]){
    int A[1000];
    int top=-1;
    for(int i=0;i < 1000;++i){
        A[i]=-1;
    }
    PushStack(A,1000,5);
    top++;
    PushStack(A,1000,6);
    top++;
    PushStack(A,1000,7);
    top++;
    PushStack2(A,top,8);
    PrintStack(A,top);
    std::cout <<"Pop: " << PopStack(A, top) << std::endl;
    PrintStack(A,top);

    /*Node<int> *ptrHead;// Apuntador a la cabeza de la lista
    Node<int> *ptrTemp;// Apuntador auxiliar
    int pos;
    ptrHead = new Node<int>(0);
    for(int i=1; i <= 9; ++i){
        PushBack<int>(ptrHead, i);
    }
    ptrHead = Insert(ptrHead, 100, 0);
    ptrHead = Insert(ptrHead, 101, 1);
    ptrHead = Insert(ptrHead, 102, 5);
    Print(ptrHead);
    std::cout << "Eliminando primer elemento ... "<< std::endl;
    ptrHead = PopFront(ptrHead, ptrTemp);
    std::cout << "Elemento recuperado:  "<< ptrTemp->data << std::endl;
    free(ptrTemp);
    Print(ptrHead);
    std::cout << "Eliminando nodo 5 ... "<< std::endl;
    ptrHead = Pop(ptrHead, ptrTemp, 5);
    std::cout << "Elemento recuperado:  "<< ptrTemp->data << std::endl;
    if(ptrTemp != NULL){
        free(ptrTemp);
    }
    Print(ptrHead);
    std::cout << "Eliminando ultimo elemento ... "<< std::endl;
    ptrHead = PopBack(ptrHead, ptrTemp);
    std::cout << "Elemento recuperado:  "<< ptrTemp->data << std::endl;
    free(ptrTemp);
    Print(ptrHead);
    std::cout << "Elemento en posicion 5 ... "<< std::endl;
    ptrTemp = Position(ptrHead, 5);
    std::cout << "Elemento recuperado:  "<< ptrTemp->data << std::endl;
    Print(ptrHead);
    std::cout << "Buscar val=5 ... "<< std::endl;
    pos = Search(ptrHead, 5);
    std::cout << "Esta en pos: "<< pos << std::endl;
    std::cout << "Buscar val=50 ... "<< std::endl;
    pos = Search(ptrHead, 50);
    std::cout << "Esta en pos: "<< pos << std::endl;*/
    //std::cout << ptrHead[5] << std::endl;
//    Clear(ptrHead);
    return 0;
}
