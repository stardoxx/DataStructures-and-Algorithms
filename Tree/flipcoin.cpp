#include<bits/stdc++.h>
using namespace std;



void buildSegmentTree(int * sgArray,int* input,int start,int end,int pos){
  if(start > end){
    return ;
  }
  if(start == end){
    sgArray[pos] = input[end];
  }
  int mid = (start+end)/2;
  buildSegmentTree(sgArray,input,start,mid,2*pos+1);
  buildSegmentTree(sgArray,input,mid+1,end,2*pos+2);
  sgArray[pos] = sgArray[2*pos+1]+sgArray[2*pos+2];
  return;
}

void countHead(int * sgArray,int start,int end,int s,int e, int pos){
  if(s>e){
    return;
  }
  if(s <= start && e >= end){

  }
}

int main(){

  int n;
  cin>>n;
 int * input = new int(n);
 for(int i = 0;i<n;i++){
   input[i] = 0;
 }
 int qlines;
 cin>>qlines;
 int * sgArray = new int(4*n+1);
 buildSegmentTree(input,sgArray,0,n,0);
 for(int i = 0;i<qlines;i++){
   int operation,qlow,qhigh;
   cin>>operation>>qlow>>qhigh;
   if(operation == 1){
    int headcoin = countHead(sgArray,start,end,pos);
    cout<<headcoin<<endl;
   }
   else{
     flipcoins(qlow,qhigh);
   }
 }


  return 0;
}
