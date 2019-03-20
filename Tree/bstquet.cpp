#include<iostream>
using namespace std;
#include"bnode.h"
#include<climits>
class node{
public:
  int data;
  node * next;
  node * pre;
  node(int data){
    this->data = data;
    pre = NULL;
    next = NULL;
  }
};
//insert into binary tree
binary* insert(binary* root,int data){
  if(root == NULL){
    binary* newnode = new binary(data);
    return newnode;
  }
  if(data <= root->data){
    root->left = insert(root->left,data);
  }
  else {
     root->right = insert(root->right,data);
  }
  return root;

}
//inorder printing
void inorder(binary* root){
  if(root == NULL){
    return ;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
//search
bool search(binary* root,int data){
  if(root == NULL){
    return false;
  }
  if(root->data == data){
    return true;
  }
  else if(root->data > data){
   return  search(root->left,data);
  }
  else{
    return search(root->right,data);
  }
}
//non recursive search
bool nonRecurSearch(binary * root,int data){
  if(root == NULL){
    return false;
  }
  binary* temp = root;
  while(temp){
    if(temp->data == data){
      return true;
    }
    else if(temp->data > data){
      temp = temp->left;
    }
    else{
      temp = temp->right;
    }
  }
  return false;
}
//find minimum value
binary * findMin(binary* root){
  if(root == NULL){
    return root;
  }
  while(root->left != NULL){
    root = root->left;
  }
  return root;
}
//find min non recursive
int nonRecurfindmin(binary* root){
  if(root == NULL){
    return -1;
  }
  binary* temp = root;
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp->data;
}
//LCA of a BST
binary * lca(binary * root,int a,int b){
  if(root == NULL){
    return root;
  }
  binary* l, *r;

   if(root->data > a && root->data >b){
    l = lca(root->left,a,b);
    return l;
  }
  else if(root->data < a && root->data < b){
      r = lca(root->right,a,b);
      return r;
    }
    else{
      return root;
    }
  }
//deletion in a BST
binary * deleteBST(binary * root,int data){
  if(root == NULL){
    return root;
  }
  else if(data < root->data){
    root->left = deleteBST(root->left,data);
  }
  else if(data > root->data){
    root->right = deleteBST(root->right,data);
  }
  else{
    //case 1: no child ,leaf
    if(root->left == NULL && root->right == NULL){
      delete root;
      root = NULL;
    }
    //case 2: with one child
    else if(root->left == NULL){
      binary * temp = root;
      root= root->right;
      delete temp;
    }
    else if(root->right == NULL){
      binary * temp = root;
      root = root->left;
      delete temp;
    }
    //case 3: has left and right child
    else{
      binary * temp = findMin(root->right);
      root->data = temp->data;
      root->right = deleteBST(root->right,temp->data);
    }
  }
  return root;
}

//check BST
bool isBst(binary* root){
  if(root == NULL){
    return true;
  }
  if(root->left == NULL && root->right->data < root->data){
    return false;
  }
  if(root->left->data >root->data && root->right == NULL){
    return false;
  }
  if(root->left->data < root->data && root->right->data > root->data){
    return true;
  }
  return isBst(root->left) && isBst(root->right);
}
//distance between two nodes
int distance(binary *root,int a){
  if(root == NULL ){
    return INT_MIN;
  }
  if(root->data == a){
    return 0;
  }
  else if(a < root->data){
    int l = distance(root->left,a);
    if(l != INT_MIN){
      return l+1;
    }
  }
  else{
    int r = distance(root->right,a);
    if(r != INT_MIN){

    return 1+r;
      }
  }
}
//shortestPath between two nodes
int shortestPath(binary * root, int a,int b){
  if(root == NULL){
    return -1;
  }
  binary * temp = lca(root,a,b);
  int disA = distance(root,a);
  int disB = distance(root,b);
  return disA+disB;
}
//merging two ll
/*binary * merge(binary *a,binary *b){
  if(a == NULL){
    return b;
  }
  if(b == NULL){
    return a;
  }
  binary * alast = a->left;
  binary * blast = b->left;
  alast->right = b;
  b->left = alast;
  blast->right = a;
  a->left = blast;
  return a;
}
//convert bst to dll
binary * bstToDll(binary* root){
  if(root == NULL){
    return root;
  }
  binary * alist = bstToDll(root->left);
  binary * blist = bstToDll(root->right);
  root->left = root;
  root->right = root;
  alist = merge(alist,root);
  alist = merge(alist,blist);
  return alist;
}
//convert a sorted dll into bst
node* dllToBst(node * head){
  if(head == NULL){
    return NULL;
  }
  if(head->next == NULL){
    return head;
  }
  node * mid = middle(head);
  mid->next = dllToBst(mid->next);
  mid->pre = dllToBst(mid->pre);
  return mid;
}*/
//kth smallest element
void kSmallest(binary * root,int &count){
  if(root == NULL){
   count--;
    return ;
  }
  kSmallest(root->left,count);
  if(count == 0){
    cout<<root->data<<endl;
  }
  kSmallest(root->right,count);
}
//floor of a given number
binary* floor(binary * root,int k){
  if(root == NULL){
    return root;
  }
  binary* left =floor(root->left,k);
  if(left == NULL){
    return root;
  }
  if(left != NULL){
  if(k < root->data){
    return left;
    }
  }
  return floor(root->right,k);
}


int main(){
   binary * root = new binary(21);
  root = insert(root,12);
  root = insert(root,32);
  root = insert(root,1);
  root = insert(root,15);
  root = insert(root,51);
  root = insert(root,-100);
  /*int k ;
  cout<<"enter k"<<endl;
  cin>>k;
  kSmallest(root,k);*/
  int x = 54;
  binary * temp = floor(root,x);
  cout<<temp->data<<endl;
  //inorder(root);
  //cout<<shortestPath(root,-100,51)<<endl;
  //deleteBST(root,15);
  //inorder(root);
  //cout<<search(root,51)<<endl;
  //cout<<search(root,43)<<endl;
//cout<<nonRecurSearch(root,23)<<endl;
//cout<<nonRecurSearch(root,15)<<endl;
//  cout<<nonRecurfindmin(root)<<endl;
//  binary* temp = lca(root,1,15);
//  cout<<temp->data<<endl;
//cout<<isBst(root)<<endl;
  return 0;
}
