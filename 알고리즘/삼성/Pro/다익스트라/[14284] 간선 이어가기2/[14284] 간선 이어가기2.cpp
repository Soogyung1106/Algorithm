/*

백준 [14284] 간선 이어가기 2

*/

 

#include <iostream>

#include <vector>

#include <queue>

using namespace std;

 

const int INF = 100000000;

const int MAX = 5000 + 1;

vector<pair<int, int>> adjList[MAX]; //(인접노드, 가중치)

vector<int> dp;

 

void dijkstra(int start) {

	

	//MIN 힙 생성 

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, start}); //(비용, 출발지점)

	dp[start] = 0;

 

	//인접 리스트에서 end 발견시 dp 갱신 후 바로 종료!!

	while (!pq.empty()) {

		int here = pq.top().second;

		int hereCost = pq.top().first;

		pq.pop();

 

		if (hereCost > dp[here]) continue;

 

		//릴렉세이션

		for (int i = 0; i < adjList[here].size(); i++) { //인접노드 순회

			int there = adjList[here][i].first;

			int thereCost = hereCost + adjList[here][i].second;

			

			if (thereCost < dp[there]) {

				dp[there] = thereCost;

				pq.push({ thereCost, there });

			}

		}

	}

}

 

int main() {

 

	//입력

	freopen("input.txt", "r", stdin);

	int N, M;	cin >> N >> M;

	while (M--) {

		int u, v, w;

		cin >> u >> v >> w;

		adjList[u].push_back({v, w}); 

		adjList[v].push_back({u, w}); 

	}

	

	int start, end; cin >> start >> end; 

 

	//최단경로 구하기 

	dp.resize(MAX, INF);

	dijkstra(start);

	

	//출력

	cout << dp[end] << '\n';

 

	return 0;

}