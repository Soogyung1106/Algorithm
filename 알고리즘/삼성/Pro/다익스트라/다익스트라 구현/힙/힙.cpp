/*

문제 : https://www.acmicpc.net/problem/1753

다익스트라 알고리즘 - O(E*logV)을 이용

*/

#include <iostream>

#include <queue>

#include <vector>

using namespace std;

 

const int MAX = 20000 + 1;

const int INF = 1000000000;

int vertex, edge, start;

vector<pair<int, int>> adjList[MAX]; //(i노드와 연결된 인접노드, 비용)

vector<int> dp; //start부터 i노드까지 최단 거리(비용) 저장

 

void dijkstra() {

 

	dp[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //최소비용이 맨 위로 오도록 힙 활용

	pq.push({ 0, start }); //(비용, 출발노드)

 

	while (!pq.empty()) {

 

		//최소 비용의 인덱스

		int costHere = pq.top().first;

		int here = pq.top().second;

		pq.pop(); //최소 비용의 경로가 pop됨.

 

		if (dp[here] < costHere) continue; 

 

		//선택된 노드의 인접 노드 순회(start 노드부터 there 노드까지의 거리 갱신) 

		for (int i = 0; i < adjList[here].size(); i++) {

			int there = adjList[here][i].first; //curr 노드와 연결된 인접노드 

			int thereCost = costHere + adjList[here][i].second;

			

			if (thereCost < dp[there]) { //기존의 최소 비용보다 더 저렴하면 갱신

				dp[there] = thereCost;

				pq.push({ thereCost, there });

			}

		}

	}

}

 

int main() {

	//입력

	cin >> vertex >> edge;

	cin >> start;

 

	//dp 초기화

	dp.resize(vertex + 1, INF); //기본적으로 연결되지 않은 경우 비용은 무한.

 

	for (int i = 0; i < edge; i++) {

		int from, to, weight;

		cin >> from >> to >> weight;

		adjList[from].push_back({ to, weight });

	}

 

	//다익스트라 호출

	dijkstra();

 

	//출력

	for (int i = 1; i <= vertex; i++) {

		if (dp[i] == INF) cout << "INF" << "\n";

		else cout << dp[i] << "\n";

	}

 

	return 0;

}