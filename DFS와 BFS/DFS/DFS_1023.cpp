#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 100; 
int n, m;
vector<int> myGraph[MAX]; // myGraph[x] = x의 인접 리스트
bool visited[MAX];

void DFS(int x) {
	//노드 X부터 시작해서 DFS하여 그 순서를 출력하는 함수 
	//단, visited에 방문 기록이 있음.
	visited[x] = true;
	printf("%d ", x);

	for (int i = 0; i < myGraph[x].size(); i++) {
		int y = myGraph[x][i];

		if (visited[y] == false) {
			DFS(y);
		}
	}
}


int main() {
	

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}

	DFS(1); //노드 1부터 시작해서 그래프 순회
	
	printf("\n");

	return 0;

}