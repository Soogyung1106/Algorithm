#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> graph[], bool visited[], int idx) {
	//idx를 기준으로 graph 연결리스트를 dfs 탐색
	//탐색하면서 방문한 idx는 visted에 true 표시 
	
	visited[idx] = true;

	for (int i = 0; i < graph[idx].size(); i++) {
		if (!visited[graph[idx][i]])
			dfs(graph, visited, graph[idx][i]);
	}

}

int main() {

	//그래프 생성(연결리스트)
	int N, M;  cin >> N >> M; //정점의 개수, 간선의 개수
	
	int u, v; vector<int>* graph = new vector<int>[N + 1];
	for (int i = 0; i < M; i++) { //간선 개수 만큼 for문
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 연결된 정점 끊어서 dfs 탐색 
	bool* visited = new bool[N + 1]; fill(visited, visited + N + 1, false); // 방문 여부 check 
	int count = 0;
	for (int i = 1; i < N + 1; i++) { //노드 개수 만큼 for문
		if (!visited[i]) {
			dfs(graph, visited, i);
			count++;
		}
	}

	// 연결 요수 개수 출력
	cout << count << endl;
	delete[] graph; delete[] visited;

}