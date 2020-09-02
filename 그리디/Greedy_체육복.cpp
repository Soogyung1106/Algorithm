#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //체육복을 잃어버리지 x 사람  
    answer += n - lost.size();
    
   for(int i=0;i<reserve.size();i++){
        for(int j=0;j<lost.size();j++){
             //예외상황(여벌을 갖고 있지만 도난당한 경우)
            if( reserve[i] == lost[j]){
                reserve.erase(reserve.begin()+i);
            }
        }
    }
    
    
    
    //체육복 잃어버렸지만 빌릴 수 있는 사람 
    for(int i=0;i<reserve.size();i++){
        for(int j=0;j<lost.size();j++){
            
            if(reserve[i]-1 != 0 && lost[j] != 0 && reserve[i]-1 == lost[j]){
                lost[j] = 0; //체육복을 빌렸다면 0으로 초기화
                answer++;
                break;
            }
            if(reserve[i]+1 <= lost[lost.size()-1] && lost[j] != 0 && reserve[i]+1 == lost[j]){
                lost[j] = 0; //체육복을 빌렸다면 0으로 초기화
                answer++;
                break;
            } 
        }        
    }
        
    return answer;
}