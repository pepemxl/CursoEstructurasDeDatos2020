#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL && q != NULL){
            return false;
        }
        if(p != NULL && q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool bleft = true;
        bool bright = true;
        bleft = isSameTree(p->left, q->left);
        bright= isSameTree(p->right, q->right);
        if(!bleft || !bright){
            return false;
        }
        return true;
    }
};


int main(){
    
    return 0;
}