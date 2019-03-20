#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
class bnode{
public:
  int data;
  bnode* left;
  bnode* right;
  bnode(int data){
    this->data = data;
    left =NULL;
    right =NULL;
  }
  ~bnode(){
    delete left;
    delete right;
  }
};
bnode* input(){
  cout<<"enter data"<<endl;
  int data;
  cin>>data;
  bnode* newroot = new bnode(data);
  queue<bnode*> q;
  q.push(newroot);
  while(q.size() != 0){
    bnode* temp = q.front();
    q.pop();
    cout<<"do you want to enter leftchild? [y/n]"<<endl;
    string check;
    cin>>check;
    if(check == "y"){
    int leftchild;
    cin>>leftchild;
    bnode* leftnode = new bnode(leftchild);
    temp->left = leftnode;
    q.push(temp->left);
  }
    cout<<"do you want to enter rightchild? [y/n]"<<endl;
    //string check;
    cin>>check;
    if(check == "y" ){
      int rightchild;
      cin>>rightchild;
      bnode* rightnode = new bnode(rightchild);
      temp->right = rightnode;
      q.push(temp->right);
    }
  }
  return newroot;
}
//print
void preorder(bnode* root){
  if(root == NULL){
    return ;
  }
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);

}


int main(){
  bnode* root = input();
  preorder(root);
  return 0;
}
