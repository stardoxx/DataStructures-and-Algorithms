#include<bits/stdc++.h>
using namespace std;
//typedef pair<int,int> p;

class dates{
public:
  int buy,sell,diff;
  dates(int buy,int sell){
    this->buy = buy;
    this->sell = sell;
    this->diff = buy-sell;
  }

};

dates* profit(int *arr,int start,int size){
  if(size == 2){
    int mini = min(arr[start],arr[start+size-1]);
    int maxi = max(arr[start],arr[start+size-1]);
    dates* d = new dates(mini,maxi);
    return d;
  }
  dates* d1 = profit(arr,start,size/2);
  dates* d2 = profit(arr,(start+(size/2),size/2);
  dates* d3(d1->buy,d2->sell);
  dates* d4(d2->buy,d1->sell);
  int maximum = max(d1->diff,d2->diff,d3->diff,d4->diff);
  if(max == d1->diff){
    return d1;
  }
  else if(max == d2->diff){
    return d2;
  }
  else if(max == d3->diff){
    return d4;
  }
  else
   return d5;

}


int main(){
  int arr[] ={23,10,12,1,34,45,21,19,9,10};
  dates *d = profit(arr,0,10);
  cout<<"to buy "<<d->buy<<endl;
  cout<<"to sell "<<d->sell<<endl;


  return 0;
}
