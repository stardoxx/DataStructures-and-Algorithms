#include<bits/stdc++.h>
using namespace std;
//naive approach
void naive(vector<int> v,vector<int> u){
  vector<int> w;
//  cout<<"check2"<<endl;
  for(int i = 0;i<(v.size()+u.size()-1);i++){
    w.push_back(0);
  }
//  cout<<"check3"<<endl;
  for(int i = 0;i<v.size();i++){
    for(int j =0;j<u.size();j++){
      w[i+j] = w[i+j]+ v[i]*u[j];
    }
  }

  for(int i =0;i<w.size();i++){
    cout<<w[i]<<" ";
  }
}
//divide and conquer
 

int main(){
  int m,n;
  vector<int> v,u;
  cin>>m;
  int temp;
  for(int i = 0;i<m;i++){
    cin>>temp;
    v.push_back(temp);
  }
  cout<<"\nenter n"<<endl;
  cin>>n;
  for(int i =0;i<n;i++){
    cin>>temp;
    u.push_back(temp);
  }
//  cout<<"check1"<<endl;
  naive(v,u);


  return 0;
}
