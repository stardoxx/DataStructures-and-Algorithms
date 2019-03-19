#include<bits/stdc++.h>
using namespace std;

int single(vector<int> v,int start,int end){
  if(start >end){
    return -1;
  }
  if(start == end){
    return v[start];
  }
  int mid = start+(end-start)/2;
  if(mid%2 == 0){
    if(v[mid] == v[mid+1]){
      return single(v,mid+1,end);
    }
    else{
      return single(v,start,mid);
    }
  }
  else{
    if(v[mid-1] == v[mid]){
      return single(v,mid+1,end);
    }
    else{
      return single(v,start,mid-1);
    }
  }
}

int main(){
 vector<int> v;
 int n,k;
 cout<<"enter n "<<endl;
 cin>>n;
 for(int i = 0;i<n;i++){
   cin>>k;
   v.push_back(k);
 }
 cout<<single(v,0,v.size()-1)<<endl;

  return 0;
}
