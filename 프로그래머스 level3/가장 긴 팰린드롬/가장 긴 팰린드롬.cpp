#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    //i번째와 j번째 문자가 같다면 memo[i][j] = 1
    vector<vector <int>> memo(s.size()+1, vector<int>(s.size()+1, 0));
    
    //1자리 
    for(int i=0;i<s.size();i++) memo[i][i] = 1;
    int answer = 1;

    //2자리
    for(int i=0;i<s.size()-1;i++){
        if(s[i] == s[i+1]){
            memo[i][i+1] = 1;
            answer = 2;
        } 
    }
          
    //3자리 이상.x
    for(int len=3;len<=s.size();len++){ //길이
        for(int j=0;len+j-1<=s.size();j++){ //인덱스 위치
            if(s[j] == s[j+len-1] && memo[j+1][j+len-2] == 1){
                memo[j][j+len-1] = 1;
                if(answer<len) answer = len;
            }   
        }
    }
    
    return answer;
}