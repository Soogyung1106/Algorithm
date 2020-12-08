#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    
   for(int i=0;i<reserve.size();i++){
        for(int j=0;j<lost.size();j++){
             //예외상황(여벌을 갖고 있지만 도난당한 경우)
            if( reserve[i] == lost[j]){
                reserve.erase(reserve.begin()+i);
                lost.erase(lost.begin()+j);
                if(i==reserve.size()){
                    
                }
                i--;j--;
            }
        }
    }
    

    //체육복을 1벌 갖고 있는 사람 
    answer += n - lost.size();
        
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