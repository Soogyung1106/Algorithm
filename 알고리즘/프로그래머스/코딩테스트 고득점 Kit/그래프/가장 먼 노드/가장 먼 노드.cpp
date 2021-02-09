#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

vector<vector<bool>> edges;
vector<int> visited; //방문 여붕와 동시에 노드 1에서부터의 최단거리를 저장.

void bfs(int node){
    //node를 기점으로 bfs 탐색해 각 노드까지의 거리를 구하는 함수.
    queue<int> q;
    q.push(node); 
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //2번 노드부터 탐색해야 함.
        for(int i=2;i<edges.size();i++){
            if(edges[front][i] && !visited[i]){
                q.push(i);
                visited[i] = visited[front] +1;
            }
        }
    }
    
}

int solution(int n, vector<vector<int>> edge) {
    
    //visited, node 초기화
    visited.resize(n+1, 0);
    edges.resize(n+1, vector<bool>(n+1, false));
    for(auto elem : edge){ //양방향이므로
        edges[elem[0]][elem[1]] = true;
        edges[elem[1]][elem[0]] = true; 
    }
        
    bfs(1); //1번 노드 기준으로 bfs 탐색
    
    //가장 멀리 떨어진 노드의 개수 구하기
    int maxE = *max_element(visited.begin(), visited.end());
    cout<<maxE<<endl;
    int answer = 0; 
    for(auto elem : visited)
        if(elem == maxE)
            answer++;
    
    return answer;
}