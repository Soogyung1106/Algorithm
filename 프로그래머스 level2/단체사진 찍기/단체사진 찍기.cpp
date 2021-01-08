#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

bool isRight(int dist, char c, char cmp){
    
    if(c == '=')  return dist == cmp-'0';
    else if(c == '<')  return dist < cmp-'0';
    else if(c == '>')  return dist > cmp-'0';
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    
    string kfriends = "ACFJMNRT"; int answer = 0;
    do{
        bool flag = true;
        for(auto condition : data){
            int dist = kfriends.find(condition[0]) - kfriends.find(condition[2]);
            if(isRight(abs(dist)-1, condition[3], condition[4])) continue;
            else{
                flag = false; 
                break;
            } 
        }
        
        if(flag) answer++;
        
    }while(next_permutation(kfriends.begin(), kfriends.end()));
    return answer;
}