#include <stdio.h>

void printBinary(int x){
 //x의 이진수를 출력하는 함수
 
 //기저 조건 
  if(x/2 ==0){
    printf("%d", 1);
  }else{
    printBinary(x/2);
    printf("%d", x%2);
  }
  
}

int main() {

  //Please Enter Your Code Here
  int x;
  scanf("%d", &x);
  
  printBinary(x);
  
  return 0;
}