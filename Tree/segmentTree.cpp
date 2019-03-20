#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(int sgArray[],int input[],int start,int end,int pos){
  if(start > end){
    return;
  }
  if(start == end){
    sgArray[pos] = input[start];
    return;
  }
  int mid = (start+end)/2;
  buildSegmentTree(sgArray,input,start,mid,2*pos+1);
  buildSegmentTree(sgArray,input,mid+1,end,2*pos+2);
  sgArray[pos] = min(sgArray[2*pos+1],sgArray[2*pos+2]);

}

int minQuery(int *sgArray,int qstart,int qend,int start,int end,int pos){
 if(qstart >end || qend < start){
   return INT_MAX;
 }
 if(qstart <= start && qend >= end){
   return sgArray[pos];
 }
 int mid = (start+end)/2;
 return min(minQuery(sgArray,qstart,qend,start,mid,2*pos+1),minQuery(sgArray,qstart,qend,mid+1,end,2*pos+2));


}

void update(int * sgArray,int start,int end,int i,int value,int pos){
  if(start > i || end < i){
    return;
  }

  if(start == end){
    sgArray[i] = value;
    return;
  }

  int mid = (start+end)/2;
  update(sgArray,start,mid,i,value,2*pos+1);
  update(sgArray,mid+1,end,i,value,2*pos+2);
  sgArray[i] = min(sgArray[2*i+1],sgArray[2*i+2]);
  return;
}

//merge two arrays
void merge(int * input,int * sgArray,int inStart,int inEnd,int sgStart,int sgEnd){
  if(inStart == inEnd && sgStart == sgEnd){
    sgArray[sgStart] = input[inStart];
    return;
  }
  int midi = (inStart+inEnd)/2;
  int midsg = (sgStart+sgEnd)/2;
  merge(input,sgArray,inStart,midi,sgStart,midsg);
  merge(input,sgArray,midi+1,inEnd,midsg+1,sgEnd);
  return;
}

int distinct(int * sgArray,int n){
  unordered_set<int> s;
  for(int i = 0;i<n;i++){
    if(s.find(sgArray[i]) == s.end()){
      s.insert(sgArray[i]);

    }

  }
  return s.size();
}

void buildSumArray(int * sgArray,int * sum,int start,int end,int pos){
  if(start == end){
    sum[pos] = sgArray[start];
    return;
  }
  int mid = (start+end);
  buildSumArray(sgArray,sum,start,mid,2*pos+1);
  buildSumArray(sgArray,sum,mid+1,end,2*pos+2);
  sum[pos] = sum[2*pos+1]+sum[2*pos+2];
  return;
}


int main(){
  //int input[100];
  int input1[] = {1 ,2 ,3 ,4 ,5,6};
  int input2[] = {2 ,1 ,3 ,1 ,4,2};
  int sgArray[5];
  //buildSegmentTree(sgArray,input,0,5,0);
  /*for(int i= 0;i< 11;i++){
    cout<<sgArray[i]<<" ";
  }*/

//update(sgArray,0,5,2,-2,0);
//cout<<minQuery(sgArray,0,5,0,5,0);
  merge(input1,sgArray,0,2,0,2);
  merge(input2,sgArray,3,5,3,5);
  int sum[20];
 /*for(int i = 0;i<5;i++){
   cout<<sgArray[i]<<" ";
 }*/
 buildSumArray(sgArray,sum,0,5,0);
 cout<<sum[0];

//cout<<distinct(sgArray,5);

  return 0;
}
