#include <stdio.h>

int main(){
  
  int colors[1000]={0};  //인덱스: 색, 해당 값 : 색의 갯수 
  int count = 0 ; // 칠할 수 있는 색의 수
  
  int n; scanf("%d", &n);
  

  for(int i=0;i<n;i++){
    
    int color; scanf("%d ", &color);
    
    if(colors[color]<2){
      colors[color]++; 
      count++;
    }
    
  }
  
  if(count>= 6){
    printf("YES");  
  }else{
    printf("NO");
  }
  

}