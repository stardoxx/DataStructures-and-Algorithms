#include<bits/stdc++.h>
using namespace std;

int kth(vector<int> v,vector<int> u,int startv,int endv,int startu,int endu,int k){
  cout<<"heool"<<endl;
  if(startu == endu){
    return v[k];
  }
  if(startv == endv){
    return u[k];
  }
  int midv = startv + (endv-startv)/2;
  int midu = startu+(endu-startu)/2;
  if(midu+midv <k){
    if(v[midv] >u[midu]){
      cout<<"test1"<<" ";
      return kth(v,u,startv,endv,midu+1,endu,k-midu-1);
    }
    else{
      cout<<"test2"<<" ";
      return kth(v,u,midv+1,endv,startu,endu,k-midv-1);
    }
  }
  else{
    if(v[midv] >u[midu]){
      cout<<"test3"<<" ";
      return kth(v,u,startv,midv,startu,endu,k);
    }
    else{
      cout<<"test4"<<" ";
      return kth(v,u,startv,endv,startu,midu,k);
    }
  }
}

int main(){
  vector<int> v,u;
  int n;
  cout<<"enter n"<<endl;
  cin>>n;
  int k,m;
  cout<<"enter m"<<endl;
  cin>>m;
  cout<<"enter k"<<endl;
  cin>>k;
  int temp;
  for(int i =0;i<n;i++){
    cin>>temp;
    v.push_back(temp);
  }
  for(int i =0;i<m;i++){
    cin>>temp;
    u.push_back(temp);
  }

  cout<<kth(v,u,0,v.size()-1,0,u.size()-1,k-1)<<endl;


  return 0;
  }
