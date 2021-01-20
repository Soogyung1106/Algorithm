#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

void bfs(vector<vector<bool>> graph, vector<int>& d){
    
    vector<bool> visited(graph.size(), false); //방문 여부 체크
    queue<int> q;
    
    q.push(1); visited[1] = true;
    while(!q.empty()){
        int start = q.front();
        q.pop();
        
        for(int i=1;i<=graph.size()-1;i++){
            if(!visited[i] && graph[start][i]){
                q.push(i);
                visited[i] = true;
                d[i] = d[start] + 1; //거리 재기 
            } 
        }
    }
    
}

int solution(int n, vector<vector<int>> edge) {
    
    //재구성
    vector<vector<bool>> graph(n+1, vector<bool>(n+1));
    for(auto e : edge){
        graph[e[0]][e[1]] = true;
        graph[e[1]][e[0]] = true;
    }
        
    //BFS 호출해 1번 노드에서 각 노드까지의 최단거리 구해서 저장하기 
    vector<int> d(n+1, 0);
    bfs(graph, d);
    
    //가장 먼 노드 구하기 
    sort(d.begin(), d.end());
    
    int answer = 0;
    for(auto dis : d){
        if(dis == d[n]) answer++;
    }
    return answer;
}