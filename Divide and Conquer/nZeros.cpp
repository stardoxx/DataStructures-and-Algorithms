#include<bits/stdc++.h>
using namespace std;

int zeros(int n){
  int c = 0;
  while(n >0){
    n /= 5;
    c += n;
  }
  return c;
}

void search(int n){
  int low = 0;
  int high = 1e6;

  while(low < high){
    int mid = (low+high)/2;
    int count = zeros(mid);
    if(count < n){
      low = mid+1;
  }
  else{
    high = mid;
  }
  vector<int> result;
  while(zeros(low) == n){
    result.push_back(low);
    low++;
  }
  for(int i =0;i<result.size();i++){
    cout<<result[i]<<" ";
  }
}
}

int main(){
  int n ;
  cout<<"enter n"<<endl;
  cin>>n;
  search(n);

  return 0;
}
