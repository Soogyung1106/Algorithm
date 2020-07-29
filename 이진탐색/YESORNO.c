#include <stdio.h>


int binarySearch(int arr[], int start, int end, int value){
  //arr의 배열에서 start부터 end까지 찾고자 하는 value 값의 위치를 반환 
  // 없으면 -1 반환 
  
  //기저조건
  if(start>end) return -1;
  
  else if(start == end){ //1개 남았을 때 
    if(arr[start] == value) return start;
    else return -1;
  }
  
  // 작동 
  int mid = (start + end)/2;
    
  if(arr[mid]<value){
    //mid+1 부터찾아야 함 
    return binarySearch(arr, mid+1, end, value);
  }else if(arr[mid]>value) {
    //start~mid-1까지 찾아야 함.
    return binarySearch(arr, start, mid-1, value);
  }else{ //찾고자 하는 값일 경우 
    return mid;
  }

  
}



int main() {


  int n; int q;
  scanf("%d %d", &n, &q);

  
  //정렬된 배열 입력받기 
  int arr[1000000]; 
  for(int i=0;i<n;i++){
    scanf("%d ", &arr[i]);
  }
  
  //찾고자 하는 수 입력받기 
  int answer[100000];
  for(int i=0;i<q;i++){
    int value; scanf("%d ", &value);
    answer[i] = binarySearch(arr, 0, n-1, value); //판별 
  }
  
  
  //정답 출력 
  for(int i=0;i<q;i++){
    if(answer[i] != -1 ) printf("YES\n");
    else printf("NO\n");
  }
  
  

  return 0;
}