#include<bits/stdc++.h>
using namespace std;

int rotations(vector<int> v,int start,int end){
  if(start >end){
    return -1;
  }
  if(start == end){
    return -1;
  }
  int mid = start+(end-start)/2;
  if(v[mid+1] <v[mid]){
    return mid+1;
  }
  if(v[mid] < v[mid-1]){
    return mid;
  }
  if(v[end] > v[mid]){
    return  rotations(v,start,mid-1);
  }
  return rotations(v,mid+1,end);
}

int main(){
 vector<int> v;
 int n,temp;
 cout<<"enter n"<<endl;
 cin>>n;
 for(int i = 0;i<n;i++){
   cin>>temp;
   v.push_back(temp);
 }
  cout<<rotations(v,0,v.size()-1)<<endl;
  return 0;
}
