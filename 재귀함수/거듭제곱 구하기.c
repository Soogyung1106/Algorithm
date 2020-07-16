#include <stdio.h>

int getPower(int n, int m){
  //(1) 정의 : n^m을 반환하는 함수 
  
  //(2) 기저조건 
  if(m == 0){
    return 1;
  }
  
  return n*getPower(n,m-1);
  
  
  
}

int main() {

  //Please Enter Your Code Here
  int n, m;
  scanf("%d %d", &n, &m);
  printf("%d", getPower(n, m));
  
  return 0;
}