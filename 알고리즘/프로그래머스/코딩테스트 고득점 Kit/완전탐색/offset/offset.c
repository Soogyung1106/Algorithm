#include <stdio.h>

int main() {

  //Please Enter Your Code Here
  int arr[5][5];
  
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      scanf("%d ", &arr[i][j]);
    }
  }
  
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      //개행
      if(j == 0 && i!=0){
        printf("\n");
      }
      
      //비교 
      
      // 상, 하, 좌, 우 비교 
      if((1<=i && i<=3) &&  (1<=j && j<=3) ){
        if(arr[i-1][j]> arr[i][j] && arr[i+1][j]> arr[i][j] && arr[i][j-1]> arr[i][j] && arr[i][j+1]> arr[i][j])
          printf("* ");
        else
          printf("%d ", arr[i][j]);
      }  
      
      //상, 하, 우 비교 (좌x)
      if(j == 0 && 1 <= i && i <=3) {
          
        if(arr[i-1][j]> arr[i][j] && arr[i+1][j]> arr[i][j] &&  arr[i][j+1]> arr[i][j]){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }
      }
      
      //상, 하, 좌 비교 (우x)
      
      if(j==4  && 1 <= i && i <=3 ){
          
        if(arr[i-1][j]> arr[i][j] && arr[i+1][j]> arr[i][j] && arr[i][j-1]> arr[i][j]){
            printf("* ");
        }else{
          printf("%d ", arr[i][j]);  
        }
      }
      
      //하, 좌, 우 비교 (상x)
      if(i==0 && 1<= j && j <=3){
        if(arr[i+1][j]> arr[i][j] && arr[i][j-1]> arr[i][j] && arr[i][j+1]> arr[i][j]){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }  
        
      }
      
      //상, 좌, 우 비교 (하x)
      if(i==4 && 1<= j && j <=3){
        if(arr[i-1][j]> arr[i][j] && arr[i][j-1]> arr[i][j] && arr[i][j+1]> arr[i][j]){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }    

      }
      
      if(i==0 && j==0){ // [0][1], [1][0]
        if(arr[0][1]> arr[i][j] && arr[1][0] > arr[i][j] ){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }
        
      }
      
      if(i==0 && j == 4){ // [0][3], [1][4]
        if(arr[0][3]> arr[i][j] && arr[1][4] > arr[i][j]){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }
      }
      
      if(i==4 && j == 0){ // [3][0], [4][1]
        if(arr[3][0]> arr[i][j] && arr[4][1] > arr[i][j]){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }
      }
      
      
      if(i==4 && j == 4){ // [4][3], [3][4]
        if(arr[4][3]> arr[i][j] && arr[3][4] > arr[i][j]){
          printf("* ");
        }else{
          printf("%d ", arr[i][j]); 
        }
      }      
      
      
      
    }
  }
  
  


  return 0;
}