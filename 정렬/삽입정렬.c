#include <stdio.h>

int main() {

  /*
  1 2 4 5 | 2 8 8 3 2
  - 정렬이 되어 있는 앞 원소들 중에 현재 인덱스의 값을 삽입시키는 아이디어
  - 나랑 내 앞에것들 비교
  */
  int n, data[100];
  
  scanf("%d", &n);
  
  for(int i=0;i<n;i++)
    scanf("%d", &data[i]);
  
  
  //삽입정렬
  for(int i=0;i<n;i++){
    //i가 가리키고 있는 값을 넣어야 한다.
    //단, i 왼쪽은 모두 정렬되어 있어야 한다. 
    
    for(int j=i;j>=1;j--){
      if(data[j-1]>data[j]){
        int tmp;
        tmp = data[j-1];
        data[j-1] = data[j];
        data[j] = tmp;
      }else break;
    }
  }
  
  for(int i=0;i<n;i++)
    printf("%d ", data[i]);
  

  return 0;
  
}