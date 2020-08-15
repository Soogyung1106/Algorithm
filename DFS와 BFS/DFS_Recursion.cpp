#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]) {
	// graph 에서 start 노드부터 깊이 우선으로 탐색
	// 최상단 노드부터 start

	//방문 후 출력   
	visited[start] = true; printf("%d ", start); 
	
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		//방문하지 않았다면
		if (visited[next] == false) {
			dfs(next, graph, visited); ////재귀함수를 호출 
		}

	}


}


int main() {

	//노드수, 간선수, 탐색 시작할 값 입력 
	int node, edge, start;
	cin >> node >> edge >> start;

	//그래프 생성(연결리스트 사용)
	vector<int>* graph = new vector<int>[node + 1];
	
	for (int i = 0; i < edge; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//정렬
	for (int i = 1; i <= edge; i++) {  //※ i=1 부터..
		sort(graph[i].begin(), graph[i].end());
	}
	

	//dfs로 탐색 
	bool* visited = new bool[node + 1];  fill(visited, visited + node + 1, false);

	dfs(start, graph, visited);
	printf("\n");

	return 0;

}