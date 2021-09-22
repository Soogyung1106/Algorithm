#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int MAX = 125 + 1;
const int INF = 987654321;
int N;
int graph[MAX][MAX];
int dp[MAX][MAX]; //graph[i][j]까지의 최단거리
int mv[4][2] = { {0, 1}, {0, -1}, {1, 0},  {-1, 0} };

void dijkstra() { //다익스트라를 이용한 방법
	
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ graph[0][0], {0, 0 } });
	dp[0][0] = graph[0][0];

	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		 
		pq.pop();

		for (int i = 0; i < 4; i++) {
			int nX = x + mv[i][0];
			int nY = y + mv[i][1];

			//범위 체크
			if (nX < 0 || nX > N - 1 || nY < 0 || nY > N - 1) continue;

			if (dp[nX][nY] > dp[x][y] + graph[nX][nY]){
				dp[nX][nY] = dp[x][y] + graph[nX][nY];
				pq.push({ dp[nX][nY], {nX, nY} });
			}
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	int i = 1;
	while (true) {
		cin >> N;
		if (N == 0) break; 
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> graph[i][j];
				dp[i][j] = INF;
			}
		}

		dijkstra();

		cout << "Problem " << i << ": " << dp[N - 1][N - 1]<<'\n';
		i++;
	}

	return 0;
}
