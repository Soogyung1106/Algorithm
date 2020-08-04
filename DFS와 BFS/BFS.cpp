#include <iostream>
#include <stdio.h> // c와 c++ 입출력 방식 섞어서 써도 나쁘지 x
#include <vector>
#include <algorithm>
#include <queue>  

using namespace std;

void bfs(int start, vector<int> graph[], bool check[]) {
	//graph 배열에서 start 값을 정점으로 bfs 방식으로 탐색하는 함수 

	queue<int> q;

	q.push(start);
	check[start] = true;

	while (!q.empty()) { //큐에 있다면
		
		//뺄 때 출력 
		int front = q.front();
		q.pop(); cout << front<<" "; 

		//큐에 넣기 
		for (int i = 0; i < graph[front].size(); i++) {

			//방문하지 않았다면 
			if (check[graph[front][i]] == false) {
				//큐에 넣어주고 방문했음을 표시
				q.push(graph[front][i]);
				check[graph[front][i]] = true;
			}

		}



	}


}


int main() {
	int node, edge, start;
	cin >> node >> edge >> start; //입력할 노드(정점) 개수, 간선의 개수, 탐색을 시작할 값 

	//그래프를 담을 배열  
	vector<int>* graph = new vector<int>[node + 1];
	
	//방문했는지 확인할 배열
	bool* check = new bool[node + 1];  fill(check, check + node + 1, false); // false로 초기화

	//그래프 생성 
	for (int i = 0; i < edge; i++) {
		int u, v;
		cin >> u >> v;  //연결되어 있는 두 노드 입력 
		
		//연결
		graph[u].push_back(v);
		graph[v].push_back(u);

	}
	
	//각 노드에 연결된 노드들 정렬(순차적으로 탐색 목적)
	for (int i = 1; i <= node; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	//bfs로 그래프 탐색 
	bfs(start, graph, check); 
	printf("\n");

	return 0;


}