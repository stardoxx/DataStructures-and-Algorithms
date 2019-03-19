#include<bits/stdc++.h>
using namespace std;

int repetition(vector<int> v,int start,int end){
  if(start >end){
    return -1;
  }
  if(start == end){
    return -1;
  }
  int mid = start+(end-start)/2;
  if(v[mid] == v[mid+1] || v[mid-1] == v[mid]){
    return v[mid];
  }
  int diffIndex = end-mid;
  int diffValues = v[end]-v[mid];
  if(diffIndex >diffValues){
    return repetition(v,mid+1,end);
  }
  else{
    return repetition(v,start,mid-1);
  }

}

int main(){
  int n,temp;
  vector<int> v;
 cout<<"enter n"<<endl;
 cin>>n;
   for(int i =0;i<n;i++){
     cin>>temp;
     v.push_back(temp);
   }
  cout<<repetition(v,0,v.size()-1)<<" ";
}
