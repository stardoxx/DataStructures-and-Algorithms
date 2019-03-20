#include<iostream>
using namespace std;
class tbst{
public:
  int data;
  tbst* right;
  tbst* left;
  int l;
  int r;
  tbst(int data){
    this->data = data;
    left = NULL;
    right = NULL;
    l = -1;
    r = -1;
  }
}
