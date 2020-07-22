#include <stdio.h>

void merging(int arr[], int s1, int e1, int s2, int e2){
  
  // 2 3 5 6   0 1 2 3 3    -> 양쪽 다 정렬되어 있다고 가정하에 
  //     p              q
  int p = s1; int q = s2; 
  int temp[100000]; int temp_idx = 0;
  
  while(p <= e1 &&  q <= e2){ //범위 안에 있다는 가정 하에 
    if(arr[p] <= arr[q]){
      temp[temp_idx++] = arr[p];
      p++;
    }else{
      temp[temp_idx++] = arr[q];
      q++;
    }
  }
  
  //p나 q 둘 중 하나라도 범위에 벗어났을 경우
  if(p>e1){
    for(int i=q;i<=e2;i++)
      temp[temp_idx++] = arr[i];
  }else if(q>e2){
    for(int i=p;i<=e1;i++)
      temp[temp_idx++] = arr[i];
  }
  
  //temp -> arrd 옮기기
  for(int i=s1, j = 0;i<=e2;i++, j++){
    arr[i] = temp[j];
  }

  
}

void mergeSort(int arr[], int start, int end){
  //arr의 start부터 end까지 반으로 나누어 정렬해서 합병하는 함수 
  
  //기저조건
  if(start>=end){ //반으로 나눈 요소가 1개가 될 때
    return;
  }
  
  //1. 왼쪽 합병정렬
  //2. 오른쪽 합병정렬
  //3. 두 개 합병
  int mid = (start + end)/2;
  mergeSort(arr, start, mid);
  mergeSort(arr, mid+1, end);
  merging(arr, start, mid, mid+1, end);
  
}


int main() {

  int n; 
  scanf("%d", &n); //갯수 
  
  int numbers[100000];
  for(int i=0;i<n;i++)
    scanf("%d", &numbers[i]);
  
  mergeSort(numbers, 0, n-1); //배열, 배열의 start와 end
  
  for(int i=0;i<n;i++)
    printf("%d ", numbers[i]);
  

  return 0;
}