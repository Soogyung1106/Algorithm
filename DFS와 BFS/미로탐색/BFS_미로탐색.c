// 이해시 참고 : https://sdcodebase.tistory.com/14 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N, M;  // NxM 입력
int graph[101][101]; // N, M은 2이상 100이하 


void bfs() { //bfs는 재귀 사용x, 큐 사용o
	
	//BFS 탐색시 사용할 큐 
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0)); //시작 위치 집어넣기

	//상하좌우 방향 
	int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	
	while (!q.empty()) {

		//현재 좌표가 curr에 담김
		pair<int, int> curr = q.front();
		q.pop();

		//현재 위치에서 상하좌우 검사
		for (int i = 0; i < 4; i++) {
			int x = curr.first + direction[i][0]; int y = curr.second + direction[i][1];

			if (0 <= x && x < N && 0 <= y && y < M && graph[x][y] == 1) { //처음 방문하는 곳이여야 
				q.push(make_pair(x, y)); 
				//뻗어나가면서 값을 갱신함. -> 큐에서 빼면 마지막값이 항상 최단경로길이임.
				graph[x][y] = graph[curr.first][curr.second] + 1; 

			}
				
		}

	}//end while

	return;

}

int main() {

	//입력
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	//bfs로  탐색 
	bfs();

	//최단 거리 출력 
	cout << graph[N-1][M-1] << endl;

	return 0;
}
