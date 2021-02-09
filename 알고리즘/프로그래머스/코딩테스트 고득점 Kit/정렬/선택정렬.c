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
  
  
  //선택 정렬
  for(int i=0;i<n;i++){
    //이제 i번째에 최솟값을 넣어라
    //i번째부터 맨 끝까지의 값을 최솟값
    int min = i;
    
    for(int j=i;j<n;j++){
      if(data[min] > data[j]){
        min  = j;
      }
    }
    
    //최솟값 위치 넣어주기 
    int tmp;
    tmp = data[i];
    data[i] = data[min];
    data[min] = tmp;
    
    
  }
  
  
  for(int i=0;i<n;i++){
    printf("%d ", data[i]);
  }
  
  
  return 0;
}