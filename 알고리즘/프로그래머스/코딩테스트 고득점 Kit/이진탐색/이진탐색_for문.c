#include <stdio.h>

int binarySearch(int arr[], int start, int end, int value){
  //arr의 start부터 end까지 중에서 value 값을 찾아 그 위치를 반환
  //그렇지 않다면 -1을 반환 
  
  
  //start: value보다 항상 작은 값을 가리킴
  //end: value보다 항상 큰 값을 가리킴 
  
  
  if(arr[start] > value) return -1; 
  else if(arr[start] == value) return start;
  
  if(arr[end] < value) return -1;
  else if(arr[end] == value) return end;

  
  int mid;
  while(start+1<end){ // e와 s가 붙어있을 겨웅 반복문 끝나게 됨. 
    mid = (start+end) /2;
    
    if(arr[mid] == value) return mid;
    else if(arr[mid]>value)  end = mid; 
    else start = mid; 
    
  }
  
  //start와 end가 붙어있어서 while문을 빠져나오게 된다면. 찾고자 하는 값 x 
  return -1;
  
}


int main() {

  int n;scanf("%d", &n);
  
  int arr[100];
  for(int i=0;i<n;i++){
    scanf("%d ", &arr[i]); 
  }
  
  int x; scanf("%d", &x);

  int idx = binarySearch(arr, 0, n-1, x);
  
  if(idx == -1){
    printf("찾을 수 없습니다.");
  }else{
    printf("%d번째에 있습니다.", idx+1); 
  }

  return 0;
}