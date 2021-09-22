//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstdio>
using namespace std;

const int MAX = 100 + 1;
const int INF = 987654321;
int M, N; //가로, 세로 
int graph[MAX][MAX];
int dp[MAX][MAX]; //graph[i][j]까지 부순 문의 최소 개수
bool visited[MAX][MAX];
int mX[] = {0, 0, 1, -1};
int mY[] = {1, -1, 0, 0};

void input() {
	//freopen("input.txt", "r", stdin);
	cin >> M >> N; //가로, 세로 (1~100)

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &graph[i][j]);
			dp[i][j] = INF;
		}
	}
}

void dijkstra() {

	dp[0][0] = 0; //(1, 1)은 항상 뚫려 있으므로.

	queue<pair<int, int>> q;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int curX = q.front().first;
		int curY = q.front().second;
		visited[curX][curY] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = curX + mX[i];
			int nextY = curY + mY[i];
			
			//범위 검사 
			if (nextX < 0 || nextX > N - 1 || nextY < 0 || nextY > M - 1) continue;

			visited[nextX][nextY] = true;
			if (graph[nextX][nextY] == 1) { //벽을 만난 경우
				if (dp[nextX][nextY] > dp[curX][curY] + 1){
					dp[nextX][nextY] = dp[curX][curY] + 1;
					q.push({ nextX, nextY });
				}
			}
			else {
				if (dp[nextX][nextY] > dp[curX][curY]) {
					dp[nextX][nextY] = dp[curX][curY];
					q.push({ nextX, nextY });
				}
			}
		}
	}

}


int main() {

	input();
	dijkstra();
	cout<<dp[N-1][M-1]<<'\n';

	return 0;
}