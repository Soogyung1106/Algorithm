#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int arr[1000][5] = {0}; // 5개의 반, 학생 수 최대 1000명 
  int count[1000][1000]={0}; //같은 반인 학생 수  -> 아는 사이라면 1 
  int friends[1000]={0}; //총 알고 있는 학생 수 
  
  int n; scanf("%d", &n); 
  
  for(int i =0;i<n;i++){
    for(int j=0;j<5;j++){
      scanf("%d ", &arr[i][j]);
    }
  }
  
  //계산
  for(int i =0;i<n;i++){ //학생1, 학생2, 학생3, ...학생5 
    for(int j=0;j<5;j++){ //학년별 반   
      //arr[i][j]  학생 1, 1반
      
      for(int k = 0; k<n && k!=i;k++){ // 비교 
        if(arr[i][j] == arr[k][j])  
          count[i][k] = 1;
      }
      
    }
  }
  
  // 아는 학생수 더하기  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      friends[i] += count[i][j];
    }
  }
  
  //제일 많이 아는 학생 구하기 
  int president =0; int max = 0;
  
  //test 
  for(int i =0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%d ", count[i][j]);
      if(j == n-1)
         printf("\n");
      
    }
  }
  
  
  for(int i=0;i<n;i++){
    if(max < friends[i]){
      president = i;
    }else if(president == friends[i]){
      continue;
    }
  }
  
  printf("%d", president++); //0부터 돌았으므로
  
  return 0;
  
}