#include<bits/stdc++.h>
using namespace std;

int check(int * arr,int start,int end){
  int count =0;
  for(int i  = start;i<= end;i++){
    if(arr[i]>arr[i+1]){
      count++;
    }
  }
  return count;
}

int merge(int * arr,int start1,int end1,int start2,int end2){
  int i = start1,j = start2;
  int count =0;
  while(i<=end1 && j<= end2){
    if(arr[i]>arr[j]){
      i++;
      j++;
      count++;
    }
    else{
      i++;
      count++;
    }
  }
  return count;
}

int inv(int *arr,int start,int end){
  if(start == end){
    return 0;
  }
  if(end - start == 2){
    int in =  check(arr,start,end);
    return in;
  }
  int mid = (start+end)/2;
  int result1 =inv(arr,start,mid);
  int result2 = inv(arr,mid+1,end);
  int out =  merge(arr,start,mid,mid+1,end);
  return out+result1+result2;
}

int main(){
  int arr[] = {0,1,3,2,4,8,5,9,7,6};
  int num= inv(arr,0,9);
 cout<<num<<endl;

  return 0;
}
