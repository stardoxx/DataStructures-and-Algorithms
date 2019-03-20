#include<iostream>
using namespace std;
#include<algorithm>
#include<climits>
#include<vector>
class node{
public:
  int data;
  node* next;
  node(int data){
    this->data = data;
    next = NULL;
  }
};


class bst{
public:
  int data;
  bst* left;
  bst* right;
  bst(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
};
//inserting into binary tree
bst* insert(bst* root,int data){
  if(root == NULL){
    bst* newnode = new bst(data);
    return newnode;
  }
  if(root->data >= data){
    root->left = insert(root->left,data);
  }
  else if(root->data < data ){
    root->right = insert(root->right,data);
  }
  return root;
}
//printing values of tree between two values
void between(bst* root,int a,int b){
  if(root == NULL){
    return ;
  }

  if(root->data > a && root->data >b){
    between(root->left,a,b);
  }
  else if(root->data < a &&root->data <b){
    between(root->right,a,b);
  }
  else{
    int maximum = max(a,b);
    int minimum = min(a,b);
    cout<<root->data<<" ";
    between(root->left,minimum,root->data);
    between(root->right,root->data,maximum);
  }
}



// bst sort or inorder traversal(printing)
void inorder(bst* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<endl;
  inorder(root->right);

}
//maximum in bst
/*int maximum(bst* root){
  if(root == NULL){
    return INT_MIN;
  }
  if(root->right == NULL){
    return root->data;
  }
  return maximum(root->right);
}/*
//minimum in bst
int minimum(bst* root){
  if(root == NULL){
    return INT_MAX;
  }
  if(root->left == NULL){
    return root->data;
  }
  return  minimum(root->left);
}
//check for bst
bool check(bst* root){
  if(root == NULL){
    return false;
  }
  if(root->left == NULL && root->right == NULL){
    return true;
  }
  int leftmax = maximum(root);
  int rightmin = minimum(root);
  bool result = (root->data > leftmax)&&(root->data < rightmin)&&check(root->left)&&check(root->right);
  return result;
}*/
bool checkForBst(bst* root,int min = INT_MIN,int max = INT_MAX){
  if(root == NULL){
    return false;
  }
  if(root->data < min || root->data > max){
    return false;
  }
  else if(root->data > min && root->data < max){
  bool leftcheck =  checkForBst(root->left);
  bool rightcheck = checkForBst(root->right);
  return (leftcheck && rightcheck);
  }
}
//constructing binary tree using sorted array
bst* tree(vector<int> v,int start,int end){
  if(start > end){
    return NULL;
  }
  int mid  = start + (end-start)/2;
  bst* node = new bst(v[mid]);
  node->left = tree(v,start,mid-1);
  node->right = tree(v,mid+1,end);
  return node;
}


bst* formBST(vector<int> v){

  bst* root = tree(v,0,v.size()-1);
  return root;

}

void preorder(bst* root){
  if(root== NULL){
    return ;
  }
  preorder(root->left);
  preorder(root->right);
  cout<<root->data<<" ";

}
//constructing sorted linked list from bst
node* bstToll(bst* root){
   if(root == NULL){
     node* temp = NULL;
     return temp;
   }
   node* roothead = new node(root->data);
   node* lefthead ;
   node* righthead;
  if(root->left != NULL){
   lefthead =  bstToll(root->left);
  }
  if(root->right != NULL){
   righthead = bstToll(root->right);
  }
  node* temp = lefthead;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = roothead;
  roothead->next = righthead;
  return lefthead;

}
//print head
void printll(node* head){
 if(head == NULL){
   return;  
 }
  while(head != NULL){
    cout<<head->data<<" ";
    head = head->next;
  }
}




int main(){
  int data;
//  cout<<"insert data into bst"<<endl;
//  cin>>data;
//  bst* root = new bst(data);
/*  for(int i = 0;i <6;i++){
    cout<<"insert into bst"<<endl;
    cin>>data;
    root = insert(root,data);
  }*/

  vector<int> v;
  for(int i =0;i< 10;i++){
    v.push_back(i+1);
  }
  bst* root = formBST(v);
  node* head = bstToll(root);
  printll(head);
//  preorder(root);
  //between(root,16,40);
//  cout<<maximum(root)<<endl;
//cout<<checkForBst(root)<<endl;
  return 0;
}
