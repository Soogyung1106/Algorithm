#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    
    //그래프 초기화
    vector<vector<int>> contest(n+1, vector<int>(n+1, -1)); 
    for(auto result : results){
        //-1은 판단 불가능, 1은 i가 j를 이김, 0은 i가 j에게 짐을 의미 
        contest[result[0]][result[1]] = 1;
        contest[result[1]][result[0]] = 0;
    }
    
    //플로이드 와샬로 승패 추론
    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(contest[i][k]==1 && contest[k][j]==1){
                    contest[i][j] = 1;
                    contest[j][i] = 0;
                }
            }   
        }
    }
  
    
    //자기를 제외한 모든 사람과의 승패가 확실하다면 순위 확정 가능.
    int answer = 0;
    for(int i=1;i<n+1;i++){
        if(count(contest[i].begin(), contest[i].end(), -1) == 2) //0번째 -1 포함 2개
            answer++;
    }
    
    return answer;
}