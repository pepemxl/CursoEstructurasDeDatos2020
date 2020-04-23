#include <iostream>


template <typename T>
struct Node{
    T data;
    Node<T> *next;
    Node(const T &val){
        data = val;
    }
};

template <typename T>
void Print(Node<T> *currentNode, int &contador){
    if(currentNode == NULL){// condicion de paro en una recursion
        return;
    }
    std::cout << currentNode->data <<  " ";
    Print(currentNode->next, contador);
    std:: cout << currentNode << std::endl;
    contador++;
}
// 1->2->3->4->5->6->7->8->9->10

int main(){
    Node<int> *root = new Node<int>(1);
    Node<int> *temp = root; 
    for(int i = 2;i <= 10;++i){
        Node<int> *temp2 = new Node<int>(i);
        temp->next = temp2;
        temp = temp->next;
    }
    int contador = 0;
    Print(root, contador);
    std::cout <<  std::endl;
    std::cout << "Tenemos " << contador << " elementos en nuestra lista ligada"  << std::endl;
    return 0;
}


