#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue> 

using namespace std;

int N, M; // 2이상 100이하 
int map[100][100]; int visited[100][100] = { 0 };

void bfs(int i, int j) {
	// 큐를 사용하여 bfs로 탐색해 최단거리를 구함
	// visited의 마지막값에 도착지의 최단거리 값이 저장돼 있음 

	queue<pair<int, int>> q;
	q.push(make_pair(i-1, j-1)); visited[i-1][j-1] = 1;// (1, 1) 시작


	int moveX[4] = { 1, -1, 0, 0 }; int moveY[4] = { 0, 0, 1, -1 };
	
	while (!q.empty()) {
		
		//현재위치 x좌표, y좌표
		int currX = q.front().first; int currY = q.front().second;

		for (int k = 0; k < 4; k++) {
			// 이동한 x좌표, y좌표
			int nextX = currX + moveX[k];  int nextY = currY + moveY[k];
			
			//인덱스 범위 ok, 길인 경우, 처음 방문한 곳만
			//※ X가 가로가 아닌 배열의 [HERE][] 행으로 들어감! 
			if (0 <= nextX && nextX < N && 0 <= nextY && nextY < M && map[nextX][nextY] == 1 && visited[nextX][nextY] == 0){
				q.push(make_pair(nextX, nextY));
				visited[nextX][nextY] = visited[currX][currY] + 1;
			}
		}
		q.pop();

	}


}


int main() {
	
	//input 
	cin >> N >> M; //N행 M열 

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	}

	//탐색
	bfs(1, 1);

	//output 
	cout << visited[N-1][M-1] << "\n";

	return 0;
}