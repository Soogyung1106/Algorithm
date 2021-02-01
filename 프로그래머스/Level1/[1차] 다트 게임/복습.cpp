#include <string>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult) {
    
    string& s = dartResult;
    vector<int> score; int idx = -1; 
    for(int i=0;i<s.size();i++){
        //점수 
        if(isdigit(s[i])){
            if(isdigit(s[i+1])){ //두 자리 수
                score.push_back(10);
                i++;    
            }else{
                string str = ""; 
                str += s[i];
                score.push_back(stoi(str));
            }
            idx++;
            
        }else{
            //영역
            if(s[i] == 'S') score[idx] = pow(score[idx], 1); 
            else if(s[i] == 'D')  score[idx] = pow(score[idx], 2);    
            else if(s[i] == 'T')  score[idx] = pow(score[idx], 3);
            
            //옵션
            else if(s[i] == '#')  score[idx] *= -1;
            else if(s[i] == '*'){  
                score[idx] *= 2; //현재
                if(idx != 0) score[idx-1] *= 2; //이전 값
            }   
        } 
        
    }//end for
    
    int answer = 0;
    for(int i=0;i<score.size();i++) answer += score[i];
    return answer;
}