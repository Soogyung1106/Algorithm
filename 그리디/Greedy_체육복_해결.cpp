#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    //예외상황(여벌을 갖고 있지만 도난당한 경우)
   for(int i=0;i<reserve.size();i++){
        for(int j=0;j<lost.size();j++){
             
            if( reserve[i] == lost[j] && reserve[i] != -1 && lost[j] != -1){
                reserve[i] = -1;
                lost[j] = -1;
            }
        }
    }
    
    for(int i=0;i<reserve.size();i++){
            if( reserve[i] == -1){
                reserve.erase(reserve.begin()+i); i--;
            }
    }
    
   for(int j=0;j<lost.size();j++){
            if( lost[j] == -1){
                lost.erase(lost.begin()+j); j--;         
            }
    }
    
    
    //체육복을 1벌 갖고 있는 사람 = 수업에 참여 가능
    answer += n - lost.size();
    
    //체육복 잃어버린 사람 중 참여 가능 인원
    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            
            if(reserve[j] != 0 && reserve[j]-1 == lost[i]){
                reserve[j] = 0; //체육복을 빌렸다면 0으로 초기화
                answer++; i++; j=0;

            }else if(reserve[j] != 0 && reserve[j]+1 == lost[i]){
                reserve[j] = 0; //체육복을 빌렸다면 0으로 초기화
                answer++; i++; j=0;                
            } 
        }        
    }
    
    
        
    return answer;
}