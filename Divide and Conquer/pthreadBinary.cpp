#include<bits/stdc++.h>
using namespace std;

int arr[] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };
int key = 14;
bool found = false;
int part =0;

void* binary_search(void *arg){
  int thread_part = part++;
  int mid;
  int low = thread_part*(16/4);
  int high = (thread_part+1)*(16/4);

  while(low < high && !found){
    mid = (high -low)/2+low;
    if(a[mid] == key){
      found = true;
      break;
    }
    else if(a[mid] > key){
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
}

int main(){
pthread_t threads[16];
for(int i =0;i<16;i++){
  pthread_create(&threads[i],NULL,binary_search,(void*)NULL);
  }
for(int i =0;i<16;i++){
  pthread_join(threads[i],NULL);
}
if(found){
  cout<<key<<"found"<<endl;
}
else{
  cout<<key<<"not found"<<endl;
}


  return  0;
}
