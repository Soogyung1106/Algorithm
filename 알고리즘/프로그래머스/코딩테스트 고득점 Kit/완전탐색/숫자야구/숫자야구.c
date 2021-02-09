#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<vector<int>> baseball; //이차원 벡터 

	for (int i = 0; i < n; i++) {
	  int one;int two; int three; 	
		cin >> one >> two >> three; //세자리 수, 스트라이크, 볼
		
		vector<int> temp;
		temp.push_back(one); temp.push_back(two); temp.push_back(three);
	
		baseball.push_back(temp);
	}
	
	int answer = 0;
	int x, y, z;
	
	//완전탐색으로 답 찾기
	for(int i=123 ;i <= 987; i++){ //1~9 서로 다른 세 숫자
	  
	  //각 자리수 
	  x = i/100; y = (i/10)%10; z = i%10;
	  
	  //skip
	  if((x==y || y==z || z==x) || (y==0||z==0)) 
	    continue;
	  
	  //n개의 힌트(조건)에 맞는지 확인 
	  for(int j = 0; j<n;j++){
	    int num = baseball[j][0]; 
	    //자리수
	    int num_x = baseball[j][0] / 100; int num_y = (baseball[j][0] /10)%10; int num_z = baseball[j][0] %10;
	    
	    //스트라이크 체크
	    int strike = 0;
	    if(num_x == x) strike++; if(num_y == y) strike++; if(num_z == z) strike++; 
	    if(strike != baseball[j][1])
	      break; //i는 답 X  
	    
	    //볼 체크 
	    int ball = 0;
	    if(num_x == y || num_x == z) ball++; if(num_y == x || num_y == z) ball++; if(num_z == x || num_z == y) ball++; 
	    if(ball != baseball[j][2])
	      break; //i는 답 X  
	    
	    //마지막 n번째 조건까지 성립한다면 i는 답 o 
	    if(j == n-1)
	      answer++;
	    
	  }
	}//end for 
	
	cout<<answer;
	 
	return 0;

}