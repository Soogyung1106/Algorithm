#include <string>
#include <cctype>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    int score[3] = {0, };
    
    int idx = -1; 
    for(int i=0;i<dartResult.size();i++){
        //점수
        if(isdigit(dartResult[i])){
            idx++;
        
            if(isdigit(dartResult[i+1])){
                score[idx] = 10;
                i++;
            }else score[idx] = dartResult[i]-'0';
            
        }else{
            //보너스
            if(dartResult[i] == 'S') score[idx] = pow(score[idx], 1);
            if(dartResult[i] == 'D') score[idx] = pow(score[idx], 2);
            if(dartResult[i] == 'T') score[idx] = pow(score[idx], 3);
        
            //옵션
            if(dartResult[i] == '*'){
                if(idx==0) score[idx] *= 2;
                else{
                    score[idx] *= 2; score[idx-1] *= 2;
                } 
            }if(dartResult[i] == '#') score[idx] *= -1;  
        }      
    }
                   
    return score[0] + score[1] + score[2];
}