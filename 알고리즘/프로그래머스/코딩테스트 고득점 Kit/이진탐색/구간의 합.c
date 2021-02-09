#include <stdio.h>

const int MAX = 100000;
int n;
int S;
int data[MAX];

// 2 1 8 3 7 2 6 3 
// -----  
//   -----
//      ------
bool check(int interval){
  //구간 길이 interval 만틈 정했을 때, 그 합이 S이상인 경우가 있는지 o/x 반환
  
  //sum에 첫 번째 구간의 합
  int sum = 0;
  for(int i=0;i<interval;i++)
    sum +=data[i];
    
  if(sum >= S) return true;
  
  //2번째 구간부터 검사(하나씩 칸 옮겨가면서 sum 구하기) 
  for(int i=0;i<n-interval;i++){
    sum = sum-data[i]+data[i+interval];
    
    if(sum >= S) return true;
  }
  
  return false;

}

int main() {

  //구간의 합 
  
  // 1 2 3 4 5 6 7 8 9 10 11 12
  // x x x x x o o o o o o o o
  
  scanf("%d %d", &n, &S);
  
  for(int i=0;i<n;i++){
    scanf("%d", &data[i]);
  }
  
  int start = 1; int end =n;//start는 무조건 x를 가리킴, end는 무조건 0을 가리킴
  
  //구간1이 될 경우
  if(check(1)){ //이게 아니라면 구간 1일 때 x 
    printf("1"); 
    return 0;
  } 
  
  //어떤 구간도 안 될 경우
  if(!check(n)){ //이게 아니라면 구간 n일 때 o
    printf("-1"); 
    return 0;
  }
  
  //1 2 3 4 5 .... 10 11 12 
  //x x x x x      x  o  o
  //               s     e
  //               s  e
  
  //이진탐색 원리 이용
  while(start+1<end){ //start와 end가 안 붙어있을 동안
    int mid = (start+end)/2;
    
    if(check(mid)) end = mid;
    else start = mid;
  }
  
  //while문이 끝나고 나서는 x와 o가 붙어있음, 원하는 값은 end가 가지고 있음 
  printf("%d", end); 
  
  return 0;
}