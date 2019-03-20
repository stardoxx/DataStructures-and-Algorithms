#include<bits/stdc++.h>
using namespace std;

class points{
public:
  int x,y;
  pair(int x,int y){
    this->x=x;
    this->y =y;
  }


};

float closetUtil(points *px,points*py,int n){
  if(n<= 3){
    return dist(px,n);
  }
  int mid = n/2;
  points pmid = px[mid];
  points
}

float closet(points *P,int n){
  points px[n];
  points py[n];
  for(int i = 0;i<n;i++){
    px[i] = P[i];
    py[i] = P[i];
  }
  qsort(px,sizeof(points),compareX);
  qsort(py,sizeof(points),compareY);
  return closetUtil(px,py,n);

}


int main(){
  points P[] = {{2,3},{12,30},{40,50},{5,1},{12,10}};
   int n = sizeof(P) / sizeof(P[0]);
   cout<<"smallest distance pair"<<closet(P,n)<<endl;

  return 0;
}
