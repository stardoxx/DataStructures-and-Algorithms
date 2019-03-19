#include<bits/stdc++.h>
using namespace std;
//divide and conquer medians
//O(n) solution
int median(vector<int> u,vector<int> v){
  int i =0,j=0,k;
  int p =INT_MIN,q = INT_MIN;
 for( k =0;k<=v.size();k++){
   if(i == v.size()){
     p = q;
     q = u[0];
     break;
   }
  else if(j == v.size()){
     p = q;
     q= v[0];
     break;
   }
   else if(u[i]<v[j]){
     p = q;
     q= u[i];
     i++;
   }
   else{
     p = q;
     q = v[j];
     j++;
   }

 }
 return (p+q)/2;
}
//O(logn)
 int med(vector<int >u){
   if(u.size()%2 == 0){
     return (u[u.size()/2]+ u[(u.size()/2)-1])/2;
   }
 }
int medianNew(vector<int> u,vector<int> v){
  if(v.size() == 0){
    return -1;
  }
  if(v.size() == 1){
    return (v[0]+u[0])/2;
  }
  if(v.size() == 2){
    return max(v[0],u[0])+min(u[0],v[0])/2;
  }
  int m1 = med(u);
  int m2= med(v);
  if(m1 == m2){
    return m1;
  }
  if(m1>m2){
    vector<int> p,q;
    for(int i =u.size()/2;i<u.size();i++){
      p.push_back(u[i]);
    }
    for(int j =0;j<v.size()/2;j++){
      q.push_back(v[j]);
    }
    return  medianNew(p,q);
  }
  else{
      vector<int> p,q;
    for(int i =0;i<u.size()/2;i++){
      p.push_back(u[i]);
    }
    for(int j = v.size()/2;j<v.size();j++){
      q.push_back(v[j]);
    }
    return medianNew(p,q);
  }

}

int main(){
 vector<int> v ={0,1,3,6,45};
 vector<int> u ={2,4,5,8,9};
 int m =medianNew(v,u);

cout<<m<<endl;

  return 0;
}
