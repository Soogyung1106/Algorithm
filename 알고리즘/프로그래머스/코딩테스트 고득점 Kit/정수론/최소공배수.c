#include <stdio.h>

int main() {

  
  int a, b; 
  int GCD; //최대공약수 
  int LCM; //최소공배수 
  scanf("%d %d", &a, &b);
  int A = a; int B = b; 
  /*최소공배수 -> L(최소공배수), G(최대공약수)
  A = aG 
  B = bG 
  L = abG
  */
  
  //유클리드 호제법
  while(1){
    int r = a%b;
    if(r == 0){
      GCD = b;
      printf("최대공약수 %d\n", GCD);
      break;
    }else{
      a = b; 
      b = r;
    }
  }
  
  LCM = (A/GCD) * (B/GCD) * GCD;
  printf("최소공배수 %d", LCM);
  
  
  return 0;
}