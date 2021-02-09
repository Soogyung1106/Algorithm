//N to M 더하기 예제 (for문으로 할 수 있지만)

#include <stdio.h>

int getSum(int n, int m){
  //n부터 m까지 더하는 함수 
  
  //기저 조건
  if (n == m)
    return m;
    
  return n + getSum(n+1, m); 
    
}


int main() {

  //Please Enter Your Code Here
  int n, m;
  scanf("%d %d", &n, &m);
  
  printf("%d", getSum(n,m));
  
  return 0;
}