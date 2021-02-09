#include <iostream>
#include <algorithm>

using namespace std;

int counting =0; 

int binarySearch(int arr[], int start, int end, int value){
  //arr의 배열에서 start부터 end까지 찾고자 하는 value의 개수를 카운팅해서 반환 
  // 없으면 0 반환 
  
  //기저조건
  if(start>end) return 0;
  else if(start == end){ //1개 남았을 때 
    if(arr[start] == value) return 1;
    else return 0;
  }
  
  // 작동 -> 한번 mid와 같은 값을 찾으면 거기서 멈춰서 범위 안에서 카운팅하고 종료
  int mid = (start + end)/2;
    
  if(arr[mid]<value){
    //mid+1 부터찾아야 함 
    return binarySearch(arr, mid+1, end, value);
  }else if(arr[mid]>value) {
    //start~mid-1까지 찾아야 함.
    return binarySearch(arr, start, mid-1, value);
  }else{ //arr[mid] == value -> 동일한 값이 mid 앞에 있을수도, 뒤에 있을수도 있음.
    for(int i=start;i<=end;i++){
      if(arr[i] == value) counting++;
    }  
    return counting;
  }

  
}


int main(){
  
  int n; int q;
  cin>>n>>q;
  
  //정렬된 배열 입력받기 
  int arr[1000000]; 
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  sort(arr, arr+n); //정렬
  
  //찾고자 하는 수 입력받기 
  int answer[100000];
  for(int i=0;i<q;i++){
    int value; cin>>value;
    answer[i] = binarySearch(arr, 0, n-1, value); //판별 
    counting=0; //초기화
  }
  
  
  //정답 출력 
  for(int i=0;i<q;i++)
    cout<<answer[i]<<endl;
   
  
  
}