#include<iostream>
using namespace std;
int fib[120];
//bottom up approach
/*int bottomUpFibo(int n){
  int memo[n+1];
  memo[0] = 0;
  memo[1] = 1;
  for(int i = 2;i<=n;i++){
    memo[i] = memo[i-1]+memo[i-2];
    }
    return memo[n];
}*/
//top down approach
void initiate(){
  for(int i = 0;i<120;i++){
    fib[i] = -1;
  }
}

int topDownFibo(int n){
  if(fib[n] == -1){
    if(n <= 1){
      fib[n] = n;
    }
    else{
      fib[n] = topDownFibo(n-1)+topDownFibo(n-2);
    }
    return fib[n];
  }
  else{
    return fib[n];
  }
}

int fibo(int n){
  if(n <= 1){
    return n;
  }
  else{
    return fibo(n-1)+fibo(n-2);
  }
}

int main(){
  //int n;
//  cin >> n;
initiate();
cout<<topDownFibo(100)<<endl;
//cout<<fibo(100);

  return 0;
}
