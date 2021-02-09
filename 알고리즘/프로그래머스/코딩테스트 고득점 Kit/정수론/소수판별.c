#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int n;
  scanf("%d", &n);
  
  for(int i=2;i<=n-1;i++){
    if (n % i ==0){
      printf("no");
      break; 
    }else if (i == n-1){
      printf("yes");
    }
  }
  
  
  return 0;
}