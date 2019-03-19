#include<bits/stdc++.h>
using namespace std;
//majority elements in a array
int maxIndex(int * arr,int start,int end,int x){
  if(start>end){
    return INT_MIN;
  }
  int mid = (start+end)/2;
  if(arr[mid] == x){
    if(arr[mid+1] == x){
      return maxIndex(arr,mid+1,end,x);
    }
    else{
      return mid;
    }
  }
  if(arr[mid]<x){
    return maxIndex(arr,start,mid,x);
  }
  else{
    return maxIndex(arr,mid+1,end,x);
  }
}

int minIndex(int * arr,int start,int end,int x){

  int mid = (start+end)/2;
  if(arr[mid] == x){
    if(arr[mid-1] == x){
      return minIndex(arr,start,mid-1,x);
    }
    return mid;
  }
 else if(arr[mid]>x){
    return minIndex(arr,start,mid,x);
  }
  else{
    return minIndex(arr,mid+1,end,x);
  }
}


bool maj(int * arr,int start,int end,int x){
  if(start > end){
    return false;
  }
  if(start == end){
    if(arr[start] == x){
      return true;
    }
  }
  int high = maxIndex(arr,start,end,x);
  int low = minIndex(arr,start,end,x);
  if(high - low >= (end-start+1)/2){
    return true;
  }
  else{
    return false;
  }

}


int main(){
  int arr[] = {1, 1, 2, 4, 4, 4, 6, 6};
  int  n = sizeof(arr)/sizeof(arr[0]);
  int x;
  cin>>x;
cout<<maj(arr,0,n-1,x)<<endl;


  return 0;
}
