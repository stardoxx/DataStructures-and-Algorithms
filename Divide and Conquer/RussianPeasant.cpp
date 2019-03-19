#include<bits/stdc++.h>
using namespace std;

int bitmul(int a,int b){
  int result =0;
  while(b > 0){
    if(b%2 != 0){
      result =  a+result;
    }
    a = a<<1;
    b = b>>1;
  }
  return result;
}

int main(){
  int a,b;
  cout<<"enter a & b"<<endl;
  cin>>a>>b;
  cout<<bitmul(a,b);


  return 0;
}
