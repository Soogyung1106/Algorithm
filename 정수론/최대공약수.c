#include <stdio.h>

int main() {

  
  int a, b;
  int GCD; //최대공약수 
  
  scanf("%d %d", &a, &b);
  
  //유클리드 호제법
  while(1){
    int r = a%b;
    if(r == 0){
      GCD = b;
      printf("%d", GCD);
      break;
    }else{
      a = b; 
      b = r;
    }
  }
  
  return 0;
}