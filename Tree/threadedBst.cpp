#include<iostream>
using namespace std;
#include"tbst.h"
#include<queue>
//inorder inorder Successor
tbst * inorderSuccessor(tbst* node){
  tbst * temp =  node;
  if(temp->r == 0){
    return node->right;
  }
  else{
    temp = node->right;
    while(temp->l == 1){
        temp = temp->l;

    }
    return temp;
  }
}
//inorder predecessor
tbst* inorderPred(tbst* root,tbst* node){
  tbst * temp = inorderSuccessor(root);
  while(temp != root && node != inorderSuccessor(temp)){
    temp  = inorderSuccessor(temp);
  }
  return temp;
}
//inorder traversal
void inorderTraversal(tbst* root,queue<tbst *>* q){
  tbst * temp  = inorderSuccessor(root);
  while(temp != root){
    temp = inorderSuccessor(temp);
    cout<<temp->data<<endl;
  }
}
//
//insert into tbst



int main()
