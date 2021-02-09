#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<bool>> nodes;
vector<bool> visited;
vector<int> path; //경로를 저장

bool dfs(int start, int level) {
	//start 노드부터 dfs 탐색
	visited[start] = true;
	path.push_back(start);

	//기저조건: 마지막 정점일 경우 종료
	if (level == nodes.size())
		return true;

	for (int i = 1; i < nodes.size(); i++) {
		if (nodes[start][i] && !visited[i]) {
			if (dfs(i, level+1)) return true;
			else {
				path.pop_back();
				visited[i] = false;
			} 
		}
	}

	//다 찾아봤는데 그 다음 노드 없을 경우.
	return false;
}

void bfs(int start) {

	queue<int> q;
	visited[start] = true;
	q.push(start);
	path.push_back(start);

	while (!q.empty()) {
		int front = q.front();
		q.pop();
		for (int i = 1; i < nodes.size(); i++) {
			if (nodes[front][i] && !visited[i]) {
				visited[i] = true;
				q.push(i);
				path.push_back(i);
			}
		}
	}

}

int main() {

	//Input
	int n, m, v; 
	cin >> n >> m >> v; //n은 정점의 개수, m은 간선의 개수, v는 탐색 시작 정점

	nodes.resize(n+1, vector<bool>(n+1, false));
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		nodes[from][to] = true;
		nodes[to][from] = true;
	}

	for (auto test : nodes) {
		for (auto t : test)
			cout << t << " ";
		cout << endl;
	}


	//Output
	visited.resize(n + 1, false);
	dfs(v, 1); //v부터 탐색 시작, 1레벨
	for (auto elem : path)
		cout << elem << " ";
	cout << endl;

	
	path.clear(); fill(visited.begin(), visited.end(), false); //path 초기화, visited 초기화 
	bfs(v); //v부터 탐색 시작
	for (auto elem : path)
		cout << elem << " ";

	return 0;
}

