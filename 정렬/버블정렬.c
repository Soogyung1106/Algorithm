#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  
  /*
  10개의 숫자 
  
  1 5 6 8 3 4 5 9 2 10
  1 2 3 4 5 5 6 8 9 10 
  */
  int n;
  int data[100];
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++){
    scanf("%d", &data[i]);
  }
  
  
  //버블 정렬
  for(int i=0;i<n;i++){
    // n번 훑겠다! 
    // 1 7 10 8 3 2 9 7 3 8 4 
    //                    j
    // j는 뒤에서 두 번째까지  
    // i = 0 -> j = 0~9
    // i = 1 -> j = 0~8
    // i = 2 -> j = 0~7
    
    for(int j=0;j<n-i;j++){
      if(data[j]>data[j+1]){
        int tmp;
        tmp = data[j];
        data[j] = data[j+1];
        data[j+1] = tmp;
      } 
    }
    
    
  }
  
  
  for(int i=0;i<n;i++){
    printf("%d ", data[i]);
  }
  
  
  return 0;
}