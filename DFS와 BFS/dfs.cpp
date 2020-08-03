#include <iostream>
#include <vector>

using namespace std;

int number = 9;
int visit[9];
vector<int> graph[10]; //9행의 각 열에는 노드와 연결된 노드의 번호로 구성

void dfs(int start) {
	//start 정점부터 시작해서 깊이 우선으로 탐색을 수행하는 함수
	//탐색 시작 정점 start는 계속 바뀜. 
	
	//기저조건
	if (visit[start]) {
		//방문한 경우 바로 빠져나옴 
		return;
	}

	visit[start] = true; //방문
	printf("%d ", start);
	
	//깊이 우선 탐색
	for(int i = 0; i < graph[start].size(); i++) {
		int x = graph[start][i];
		dfs(x);
	}

}

int main(void) {
	//연결된 노드 이중벡터로 구현

	//1과 2를 연결
	graph[1].push_back(2);
	graph[2].push_back(1);

	//1과 3을 연결
	graph[1].push_back(3);
	graph[3].push_back(1);

	//2와 3을 연결 
	graph[2].push_back(3);
	graph[3].push_back(2);

	//2와 4를 연결 
	graph[2].push_back(4);
	graph[4].push_back(2);

	//2와 5를 연결
	graph[2].push_back(5);
	graph[5].push_back(2);

	//4와 8을 연결
	graph[4].push_back(8);
	graph[8].push_back(4);

	//5와 9를 연결
	graph[5].push_back(9);
	graph[9].push_back(5);

	//3과 6을 연결 
	graph[3].push_back(6);
	graph[6].push_back(3);

	//3과 7을 연결
	graph[3].push_back(7);
	graph[7].push_back(3);

	//1번 노트부터 dfs 탐색 실행
	dfs(1);

	return 0;

}