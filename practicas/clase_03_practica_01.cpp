#include <iostream>
#include <bits/stdc++.h>// para incluir varias librerias, sin embargo no es estandar


class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        int iNumberOfNodes;
        SinglyLinkedListNode *ptrnodeHead;
        SinglyLinkedListNode *ptrnodeTail;

        SinglyLinkedList() {
            this->ptrnodeHead = nullptr;
            this->ptrnodeTail = nullptr;
        }

        void InsertNode(int iNodeData) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(iNodeData);
            if (!this->ptrnodeHead) {
                this->ptrnodeHead = node;
            } else {
                this->ptrnodeTail->next = node;
            }
            this->ptrnodeTail = node;
        }
};

void PrintSinglyLinkedList(SinglyLinkedListNode* ptrNode) {
    while (ptrNode) {
        std::cout << ptrNode->data << "->";
        ptrNode = ptrNode->next;
    }
    std::cout << std::endl;
}

void FreeSinglyLinkedList(SinglyLinkedListNode* ptrNode) {
    while (ptrNode) {
        SinglyLinkedListNode* temp = ptrNode;
        ptrNode = ptrNode->next;
        free(temp);
    }
}

// Completar la funcion DeleteNode que borra el nodo en la posicion iPosition y
// devuelve el puntero a la cabeza resultante Head

SinglyLinkedListNode* DeleteNode(SinglyLinkedListNode* ptrnodeHead, int iPosition) {


}

// Completar la funcion reversePrint.
// Esta funcion debera imprimir en order inverso la lista ligada

void ReversePrint(SinglyLinkedListNode* ptrnodeHead) {


}


int main(int argc, char *argv[]){
    int iPosition = 7;
    SinglyLinkedList* linkedList = new SinglyLinkedList();

    linkedList->InsertNode(10);
    linkedList->InsertNode(9);
    linkedList->InsertNode(8);
    linkedList->InsertNode(7);
    linkedList->InsertNode(6);
    linkedList->InsertNode(5);
    linkedList->InsertNode(4);
    linkedList->InsertNode(3);
    linkedList->InsertNode(2);
    linkedList->InsertNode(1);

    SinglyLinkedListNode* linkedList = deleteNode(llist->ptrnodeHead, iPosition);

    PrintSinglyLinkedList(linkedList);

    FreeSinglyLinkedList(linkedList);

    return 0;
}
