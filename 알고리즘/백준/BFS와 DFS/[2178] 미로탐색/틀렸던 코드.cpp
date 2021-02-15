#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;

int v, e; 
vector<vector<int>> graph;
vector<int> visited;
 
bool bfs() {

	//연결된 시작 노드(가장 작은 번호)와 끝 노드(큰 번호) 찾기 
	int start = 0, end = 0;
	bool flag = true;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (graph[i][j]) {
				if (flag) {
					start = i;
					flag == false;
				}else end = i;
			} 
		}
	}

	//1번 혹은 -1번 색으로만 칠할 수 있음, 0번은 아직 칠하지 않은 노드 
	queue<int> q;
	q.push(start);
	visited[start] = 1;  //처음 시작 노드는 1번으로 색칠

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		//정점과 연결되어 있는 모든 노드 순회
		for (int i = 1; i <= v; i++) {

			if (graph[front][i]) { //연결되어 있다면.
				//처음 방문
				if (visited[i] == 0) {
					visited[i] = 0 - visited[front]; //같은 레벨은 반대 색으로 색칠
					q.push(i);
					cout << i << endl;
				}
				//이전에 방문했었는데
				else { 
					if (visited[i] != 0 - visited[front]) //반대 색이 색칠 되어 있지 않다면
						return false;
					else {
						q.push(i);
						cout << i << endl;
					} 
				}	
			}
		}

		if (front == end) return true; //문제 없이 모든 정점이 잘 색칠 되어있다면
	
	}
}

int main() {

	//입력 
	int K; //테스트 케이스
	cin >> K; 

	vector<string> answer;
	for (int i = 0; i < K; i++) {

		cin >> v >> e; //정점, 간선의 개수 
		graph.resize(v+1, vector<int>(v+1, false));
		visited.resize(v+1, 0);
		
		for (int i = 0; i < e; i++) {
			int from, to;
			cin >> from >> to; //간선
			graph[from][to] = graph[to][from] = true; //양방향 연결
		}
		
		
		//탐색 
		if (bfs()) answer.push_back("YES"); //이분 그래프 가능하다면
		else answer.push_back("NO");
		
		//초기화 
		graph.clear();
		visited.clear();
	}

	//출력
	for (auto e : answer)
		cout << e << endl;

	return 0;
}
