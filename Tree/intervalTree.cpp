#include<bits/stdc++.h>
using namespace std;



class itNode{
public:
  int max;
  int left,right;
  itNode * leftNode;
  itNode *rightNode;

  itNode(int left,int right){
    this->left = left;
    this->right = right;
    leftNode = NULL;
    rightNode =NULL;
    max = right;
  }
};
itNode *  insert(itNode * root,int left,int right){
  if(root == NULL){
    itNode * newnode = new itNode(left,right);
    return newnode ;
  }
  if(left < root->left){
    root->leftNode =  insert(root->leftNode,left,right);

  }
  else{
    root->rightNode = insert(root->rightNode,left,right);
  }
  if(root->max < right){
    root->max = right;
  }
  return root;
}

int search(itNode * root,int qlow,int qhigh){
  if(root == NULL){
    return -1;
  }

  while(root != NULL){
    if((root->left < qlow && root->right > qlow)||(root->left < qhigh && root->right > qhigh )){
      return root->max;
    }
    else if(root->leftNode != NULL && root->left > qlow ){
      root = root->leftNode;
    }
    else{
      root = root->rightNode;
    }
  }
}

void inorderIT(itNode * root){
  if(root == NULL){
    return ;
  }
  inorderIT(root->leftNode);
  cout<<root->left<<" "<<root->right<<" "<<root->max<<endl;
  inorderIT(root->rightNode);
  return ;
}



int main(){
  itNode * root = new itNode(17,19);
  root =  insert(root,5,8);
  root = insert(root,21,24);
  root = insert(root,4,8);
  root = insert(root,15,18);
  root = insert(root,7,10);
  root = insert(root,16,22);
  //inorderIT(root);
  int find = search(root,21,23);
  if(find == -1){
    cout<<"not found"<<endl;
  }
  else{
  cout<<find;
}
  return 0;
}
