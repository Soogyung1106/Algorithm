//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 1010
#define INF 987654321
int N, M, from, to;
int dp[MAX];
vector<pair<int, int>> adjList[MAX];
int route[MAX];
vector<int> vRoute; //경로 저장.


void dijktra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, from }); //출발지점.
	dp[from] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (cost > dp[curr]) continue;
		for (auto e : adjList[curr]) {
			int next = e.first;
			int nextCost = e.second;

			if (nextCost + cost < dp[next]) {
				route[next] = curr; //경로 저장
				dp[next] = cost + nextCost;
				pq.push({ cost + nextCost, next });
			}
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) dp[i] = INF; //초기화
	for (int i = 0; i < M; i++){
		int a, b, c; 
		cin >> a >> b >> c;
		adjList[a].push_back({ b, c }); //출발점 → 도착점, 비용
	}
	cin >> from >> to;
}

void output() {
	cout << dp[to] << '\n'; //최단비용
	
	//경로 저장
	int tmp = to;
	while (tmp) {
		vRoute.push_back(tmp);
		tmp = route[tmp];
	}

	cout << vRoute.size() << '\n'; //도시 개수
	
	for (int i = vRoute.size() - 1; i >= 0; i--) {
		cout << vRoute[i] << " ";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	input();
	dijktra();
	output();
	return 0;
}