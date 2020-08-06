#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]) {
	stack<int> s;
	s.push(start); //※스택 STL 에서는 push_back 아님!
	printf("%d ", start); //출력하고 체크
	visited[start] = true;
	
	
	while (!s.empty()) {
		int curr = s.top();
		s.pop();

		//노드에 달린 가지가 없다면 스택에 쌓인 것 차례로 pop 
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];

			if (visited[next] == false) {
				printf("%d ", next); //출력하고 체크
				visited[next] = true; 

				s.push(curr); //노드에 달린 가지가 없다고 가정하고 pop을 했었기 때문에  
				s.push(next);
				break;
			}
		}

	}

}


int main() {
	int node, edge, start;
	cin >> node >> edge >> start; //노드수, 엣지수, 탐색을 시작할 정점 노드 입력


	//그래프 생성
	vector<int>* graph = new vector<int>[node + 1];

	for (int i = 0; i < edge; i++) { //간선 개수 만큼
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	//정렬: 노드 값에 순차적으로 접근
	for (int i = 0; i <= node; i++) { //노드 개수 만큼
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs 탐색 
	bool* visited = new bool[node + 1]; fill(visited, visited + node + 1, false); //방문 여부 체크할 배열
	dfs(start, graph, visited);
	cout << endl;

	return 0;

}
