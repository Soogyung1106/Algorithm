#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
vector<string> answer;
vector<string> path; //경로 임시 저장 및 true 반환되면 answer에 path 복사
vector<bool> visited;
vector<vector<string>> nodes;

bool dfs(string start, int depth){
      
    path.push_back(start);
    
    //depth가 size와 같다면 도착했다는 소리. 종료 
    if(depth == N){
        answer = path;
        return true;
    }
    
    //start로 시작하는 노드를 찾아서, path에 넣어줌 
    //없다면. return false, 방문 여부도 false로 바꿔주고 path에서도 빼주기 
    
    for(int i=0;i<N;i++){ //방문 안 한 곳 중에서 start가 있는 노드 찾기
        if(!visited[i] && nodes[i][0] == start){ 
            visited[i] = true;
            if(dfs(nodes[i][1], depth+1)) return true; //성공한 경우
            else  visited[i] = false; //실패한 경우
        }
    }
    
    //찾기 실패한 경우
    path.pop_back();
    return false; //돌아가기
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    nodes = tickets;
    N = nodes.size(); 
    visited.resize(N); //방문 여부 체크, false로 초기화.
    
    //사전순 정렬.
    sort(nodes.begin(), nodes.end());
    //처음 시작 위치 ICN, 사전순 가장빠른 여행경로를 찾아서 answer에 대입됨.  
    dfs("ICN", 0);

    return answer;
}