#include <stdio.h>

//이진탐색 재귀함수로 구현 
int binarySearch(int arr[], int start, int end, int value){
  //arr의 start부터 end까지의 값들 중 value가 존재한다면 그 위치를 반환하고, 
  //없다면 -1을 반환하는 함수
  //기저조건: 숫자가 아예 없는 경우, 숫자가
   1개 있는 경우 
  if(start>end){
    return -1;
  }else if(start == end){
    if(arr[start] == value) return start;
  }
  
  int mid = (start+end)/2;
  if(arr[mid] == value){
    return mid;
  }else if(arr[mid] > value){
    binarySearch(arr, start, mid-1, value);
  }else{
    binarySearch(arr, mid+1, end, value);
  }

  
}

int main() {


  int n;  scanf("%d", &n); //(1)갯수 입력
  
  //가정: arr은 정렬된 상태 
  int arr[100];
  for(int i=0;i<n;i++){
    scanf("%d ", &arr[i]); //(2)정렬된 배열 입력
  }
  
  int x; scanf("%d", &x); //(3)찾고자 하는 수 입력
  int idx = binarySearch(arr, 0, n-1, x); //배열, start, end, 찾고자 하는 수 
  
  if(idx == -1){
    printf("찾고자 하는 수가 없습니다. \n");
  }else{
    printf("%d번째에 있습니다. \n", idx+1);
  }
  
  
  return 0;
}