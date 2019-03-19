#include<bits/stdc++.h>
using namespace std;

int peak(vector<int> v,int start,int end){
  if(start > end){
    return -1;
  }
  if(start == end){
    return v[end];
  }
  int mid = start+(end-start)/2;
  if(v[mid-1] < v[mid] && v[mid] <v[mid+1]){
    return peak(v,mid+1,end);
  }
  if(v[mid-1]>v[mid] && v[mid]>v[mid+1]){
    return peak(v,start,mid-1);
  }
  if(v[mid-1] < v[mid] && v[mid] >v[mid+1]){
    return v[mid];
  }
}

int main(){
 vector<int> v = {10, 20, 30, 40, 50};
 cout<<peak(v,0,v.size()-1);
  return 0;
}
