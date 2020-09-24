#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //정렬시 동명이인끼리 붙어있게 정렬됨.
    sort(participant.begin(), participant.end()); sort(completion.begin(), completion.end());  
   
    for(int i=0;i<participant.size();i++){
        if(i == participant.size()-1)
            answer = participant[i];
        
        if(participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
            
    } 

    
    return answer;
}