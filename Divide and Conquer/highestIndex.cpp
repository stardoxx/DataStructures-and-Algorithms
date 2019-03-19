#include<bits/stdc++.h>
using namespace std;

 int searchIndex(int * arr,int start,int end,int i){
   if(start>end)
      return -1;
   int mid = (start+end)/2;
   if(arr[mid] == i){
     if(arr[mid+1] == i){
        return searchIndex(arr,mid+1,end,i);
     }
     else{
       return mid;
     }
   }
   else if(arr[mid] < i){
     return searchIndex(arr,mid+1,end,i);
   }
   else{
     return searchIndex(arr,start,mid,i);
   }

 }

int main(){
  int arr[10] = {1,1,1,2,3,3,3,4,5,6};
  int index = searchIndex(arr,0,10,3 );
  cout<<index<<endl;

  return 0;
}
