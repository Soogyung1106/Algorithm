#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]) {
	// graph ���� start ������ ���� �켱���� Ž��
	// �ֻ�� ������ start

	//�湮 �� ���   
	visited[start] = true; printf("%d ", start); 
	
	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];

		//�湮���� �ʾҴٸ�
		if (visited[next] == false) {
			dfs(next, graph, visited); ////����Լ��� ȣ�� 
		}

	}


}


int main() {

	//����, ������, Ž�� ������ �� �Է� 
	int node, edge, start;
	cin >> node >> edge >> start;

	//�׷��� ����(���Ḯ��Ʈ ���)
	vector<int>* graph = new vector<int>[node + 1];
	
	for (int i = 0; i < edge; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	//����
	for (int i = 1; i <= edge; i++) {  //�� i=1 ����..
		sort(graph[i].begin(), graph[i].end());
	}
	

	//dfs�� Ž�� 
	bool* visited = new bool[node + 1];  fill(visited, visited + node + 1, false);

	dfs(start, graph, visited);
	printf("\n");

	return 0;

}