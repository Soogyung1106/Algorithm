#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  //60 
  // 2 2 3 5 
  
  //180 -> 2,2, 3, 3, 5 -> 
  //i = 2, 3, 4, 5, 6, 7, ...
  int n;
  
  scanf("%d", &n);
  
  for(int i=2; n>1;){
    if(n % i == 0){   //나누어 떨어질 때까지 같은 수로 계속 나누기
      printf("%d ", i);
      n /= i; 
    }else{ 
      i++; //더 이상 안 나누어지면 그 다음숫자로 나누기 
    }
    
  }
  
  return 0;
}