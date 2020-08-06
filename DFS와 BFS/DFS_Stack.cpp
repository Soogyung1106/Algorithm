#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int start, vector<int> graph[], bool visited[]) {
	stack<int> s;
	s.push(start); //�ؽ��� STL ������ push_back �ƴ�!
	printf("%d ", start); //����ϰ� üũ
	visited[start] = true;
	
	
	while (!s.empty()) {
		int curr = s.top();
		s.pop();

		//��忡 �޸� ������ ���ٸ� ���ÿ� ���� �� ���ʷ� pop 
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i];

			if (visited[next] == false) {
				printf("%d ", next); //����ϰ� üũ
				visited[next] = true; 

				s.push(curr); //��忡 �޸� ������ ���ٰ� �����ϰ� pop�� �߾��� ������  
				s.push(next);
				break;
			}
		}

	}

}


int main() {
	int node, edge, start;
	cin >> node >> edge >> start; //����, ������, Ž���� ������ ���� ��� �Է�


	//�׷��� ����
	vector<int>* graph = new vector<int>[node + 1];

	for (int i = 0; i < edge; i++) { //���� ���� ��ŭ
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);

	}

	//����: ��� ���� ���������� ����
	for (int i = 0; i <= node; i++) { //��� ���� ��ŭ
		sort(graph[i].begin(), graph[i].end());
	}

	//dfs Ž�� 
	bool* visited = new bool[node + 1]; fill(visited, visited + node + 1, false); //�湮 ���� üũ�� �迭
	dfs(start, graph, visited);
	cout << endl;

	return 0;

}
