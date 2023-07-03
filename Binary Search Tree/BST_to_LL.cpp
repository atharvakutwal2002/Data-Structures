#include<bits/stdc++.h>
using namespace std;

Node * BST_TO_LL(Node* root ){
    if(root==NULL){
        return NULL;
    }
    Node* temp = root ;
    Node* right = BST_TO_LL(root->right);
    Node * left = BST_TO_LL(root->left);
    
}