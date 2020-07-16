#include <stdio.h>

int getPactorial(int x){
  
  if(x==0){
    return 1;
  }
  
  
  return x * getPactorial(x-1);
}


int main() {

  //Please Enter Your Code Here
  
  int x; 
  scanf("%d", &x);
  printf("%d", getPactorial(x));
  
  
  return 0;
}