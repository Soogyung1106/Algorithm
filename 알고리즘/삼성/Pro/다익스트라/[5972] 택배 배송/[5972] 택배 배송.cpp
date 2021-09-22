/*

백준 5972 - 다익스트라

*/

#include <iostream>

#include <queue>

#include <vector>

using namespace std;

 

const int INF = 100000000;

const int MAX = 500000 + 1;

int dp[MAX]; //start 노드부터 i노드까지의 최단거리를 저장.

vector<pair<int, int>> adjList[MAX]; //(인접노드, 비용)

int N, M;

 

void dijkstra(int start) {

 

	//MIN heap 구성

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, start }); //(비용, 노드)

 

	while (!pq.empty()) {

		int from = pq.top().second;

		int cost = pq.top().first;	

		pq.pop();

 

		if (cost > dp[from]) continue;

 

		//릴렉세이션

		for (int i = 0; i < adjList[from].size(); i++) {

 

			//거쳐가는 노드와 비용

			int to = adjList[from][i].first;

			int newCost = cost + adjList[from][i].second;

			if (newCost < dp[to]) {

				dp[to] = newCost;

				pq.push({ newCost, to});

			}

		}		

	}

}

 

 

int main() {

 

	freopen("input.txt", "r", stdin);

	cin >> N >> M;

 

	while (M--) {

		int u, v, w;

		cin >> u >> v >> w;

		//양방향 그래프임. 

		adjList[u].push_back({ v, w });

		adjList[v].push_back({ u, w });

	}

 

	for (int i = 1; i <= N; i++) dp[i] = INF; //dp 배열 초기화.

	dijkstra(1); //1번 노드 to N 최단거리. 

	

	cout << dp[N]<<'\n'; //도착지점에서의 최소비용.

 

	return 0;

}