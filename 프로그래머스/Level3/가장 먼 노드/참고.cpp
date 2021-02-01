/*
문제풀이 참고 
https://hochoon-dev.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EA%B0%80%EC%9E%A5-%EB%A8%BC-%EB%85%B8%EB%93%9C-c */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int solution(int n, vector<vector<int>> edge) {
    
    //재구성
    vector<vector<int>> conInfo(n+1); 
    for(int i = 0 ; i < edge.size(); i++) {
        int start = edge[i][0];
        int end = edge[i][1];

        conInfo[start].push_back(end);
        conInfo[end].push_back(start);
    }

    vector<bool> visited(n+1, false); //방문 여부 
    vector<int> distance(n+1, 0); //각 인덱스에 1번부터 N번노드까지 최단거리 저장
    queue<int> q;
    
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int startNode = q.front();
        q.pop();

        // startNode와 연결된 노드들 방문
        for(int i = 0; i < conInfo[startNode].size(); i++) {
            int endNode = conInfo[startNode][i];
            if(!visited[endNode]) {
                visited[endNode] = true;

                distance[endNode] = distance[startNode] + 1;
                cout<<"["<<endNode<<"]"<<" = "<<distance[endNode]<<endl;
                q.push(endNode);
            }
        }
    }

    sort(distance.begin(), distance.end(), comp);

    int answer = 0;
    for(auto d : distance) {
        if(d == distance[0]) answer++;
    }
    return answer;
}