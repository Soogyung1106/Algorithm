//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

const int MAX = 125 + 1;
const int INF = 987654321;
int N;
int graph[MAX][MAX];
int dp[MAX][MAX]; //graph[i][j]까지의 최단거리
int mv[4][2] = { {0, 1}, {0, -1}, {1, 0},  {-1, 0} };

void solution() { //다익스트라가 아닌 완전탐색을 이용한 방법
	
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dp[0][0] = graph[0][0];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = true;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nX = x + mv[i][0];
			int nY = y + mv[i][1];

			//범위 체크
			if (nX < 0 || nX > N - 1 || nY < 0 || nY > N - 1) continue;
			//if (visited[nX][nY]) continue;

			if (dp[nX][nY] > dp[x][y] + graph[nX][nY]){
				dp[nX][nY] = dp[x][y] + graph[nX][nY];
				q.push({ nX, nY });
			}
		

		}
	}
}

int main() {

	//freopen("input.txt", "r", stdin);
	int i = 1;
	while (true) {
		cin >> N;
		if (N == 0) break; 
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
				visited[i][j] = false; //초기화
				dp[i][j] = INF;
			}
		}

		solution();

		cout << "Problem " << i << ": " << dp[N - 1][N - 1]<<'\n';
		i++;
	}

	return 0;
}
