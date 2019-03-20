#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<string>
class tbt{
public:
  int data;
  tbt* left;
  tbt* right;
  int threaded;
  tbt(int data){
    this->data = data;
    left =NULL;
    right =NULL;
    threaded =0;
  }
  ~tbt(){
    delete left;
    delete right;
  }
};
tbt* input(){
  cout<<"enter data"<<endl;
  int data;
  cin>>data;
  tbt* newroot = new tbt(data);
  queue<tbt*> q;
  q.push(newroot);
  while(q.size() != 0){
    tbt* temp = q.front();
    q.pop();
    cout<<"do you want to enter leftchild? [y/n]"<<endl;
    string check;
    cin>>check;
    if(check == "y"){
    int leftchild;
    cin>>leftchild;
    tbt* leftnode = new tbt(leftchild);
    temp->left = leftnode;
    q.push(temp->left);
  }
    cout<<"do you want to enter rightchild? [y/n]"<<endl;
    //string check;
    cin>>check;
    if(check == "y" ){
      int rightchild;
      cin>>rightchild;
      tbt* rightnode = new tbt(rightchild);
      temp->right = rightnode;
      q.push(temp->right);
    }
  }
  return newroot;
}
//convert binary to threaded tree
tbt* convertTbt(tbt* root){
  if(root == NULL){
    return root;
  }

  tbt* a = root->left;
  if()


}

int main(){
  int data;
  tbt* root = input();
  root = convertTbt(root);
  return 0;
}
