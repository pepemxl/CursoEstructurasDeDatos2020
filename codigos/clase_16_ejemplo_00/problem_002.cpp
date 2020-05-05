#include <iostream>
#include <string>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2==NULL){
            return new ListNode(0);
        }
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int sumando1= l1->val;
        int sumando2= l2->val;
        int suma    = sumando1+sumando2;
        int digito  = suma%10;
        int accareo = suma/10;
        ListNode *newLinkedList = new ListNode(digito);
        ListNode *temp = newLinkedList;
        while(temp1->next != NULL || temp2->next != NULL){
            if(temp1->next != NULL){
                temp1 = temp1->next;
                sumando1 = temp1->val;
            }else{
                sumando1 = 0;
            }
            if(temp2->next != NULL){
                temp2 = temp2->next;
                sumando2 = temp2->val;
            }else{
                sumando2 = 0;
            }
            suma    = sumando1+sumando2+accareo;
            digito  = suma%10;
            accareo = suma/10;
            ListNode *newNode = new ListNode(digito);
            temp->next = newNode;
            temp = temp->next;
        }
        if(accareo > 0){
            suma    = accareo;
            digito  = suma%10;
            accareo = suma/10;
            ListNode *newNode = new ListNode(digito);
            temp->next = newNode;
            temp = temp->next;
        }
        return newLinkedList;
    }
};


int main(){

    return 0;
}