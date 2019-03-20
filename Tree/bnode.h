#include<iostream>
using namespace std;
class binary{
public:
 int data;
 binary* right;
 binary* left;
 binary(int data){
   this->data = data;
   right =NULL;
   left = NULL;

 }

};
