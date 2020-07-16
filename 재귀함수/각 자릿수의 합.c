#include <stdio.h>

int getDigitSum(int x){
  // x의 각 자리수의 합을 더해서 반환해주는 함수 
  
  //x가 한 자리수일 경우 
  if(x/10 == 0)
    return x;
    
  return x%10 + getDigitSum(x/10);
  
}


int main() {

  //Please Enter Your Code Here
  int x;
  scanf("%d", &x);
  printf("%d", getDigitSum(x));

  return 0;
}