#include<bits/stdc++.h>
using namespace std;

int maxContiguous(int n,int * arr){
  int * max = new int(n);
  int maxSum = 0;
  if(arr[0]>0){
    max[0] = arr[0];
  }
  else{
    max[0] = 0;
  }
  for(int i = 1;i<n;i++){
    if(max[i-1]+arr[i] >0){
      max[i] = max[i-1]+arr[i];
    }
    else{
      max[i] = 0;
    }
  }
  for(int i = 0;i<n;i++){
    if(max[i] > maxSum){
      maxSum = max[i];
    }
  }
  return max[n];
}

int main(){
  int n;
  cin>>n;
  int * arr = new int(n);
  for(int i = 0;i<n;i++){
    cin>>arr[i];
  }
  int result = maxContiguous(n,arr);
cout<<result<<endl;
  return 0;
}
