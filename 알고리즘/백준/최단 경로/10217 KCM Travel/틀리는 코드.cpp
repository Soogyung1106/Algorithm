#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Tu; //자료형 정의
int T, N, M, K; 
const int INF = 987654321;
vector<Tu> graph[101]; //(시간, 도착 노드, 비용)
vector<vector<int>> dp;

void dijkstra() {

	//dp[N][cost] 1번에서 N번 노드까지 cost비용으로 가는 최단 경로
	dp.clear(); //초기화
	dp.resize(N + 1, vector<int>(10001, INF)); // N+1 x 10001 2차원 배열

	//시간을 기준으로 min heap 구성
	priority_queue<Tu, vector<Tu>, greater<Tu>> pq;
	pq.push({ 0, 1, 0 }); //(시간, 도착 노드, 비용)
	dp[1][0] = 0; //1번 노드에서 출발해 1번 노드로 비용 0과 시간 0으로 도착 가능 

	while (!pq.empty()) {
		int time, curr, cost;
		tie(time, curr, cost) = pq.top(); //최단 경로인 노드
		pq.pop();
		//cout << time << "\n";
		//갱신할 필요 체크 
		if (dp[curr][cost] < time) continue;

		for (int i = 0; i < graph[curr].size(); i++) {
			/*
			int nTime, next, nCost;
			tie(nTime, next, nCost) = graph[curr][i];
			//nTime = dp[curr][cost] + nTime; //거쳐갔을 때의 소요 시간  
			nTime += time;
			nCost += cost; //거쳐갔을 때의 소요 비용
			
			
			if (nCost > M) continue; //예산 안에서 못 간다면 pass
			
			if (dp[next][nCost] > nTime) { //갱신
				dp[next][nCost] = nTime;
				pq.push({ nTime, next, nCost });
			}
			*/

			int nTime = time + get<0>(graph[curr][i]); // 소요 시간
			int next = get<1>(graph[curr][i]); // 다음 공항
			int nCost = cost + get<2>(graph[curr][i]); // 소요 비용

			// 해당 공항에 해당 비용으로 갈때의 최소 시간보다 크다면 pass
			if (dp[next][nCost] <= nTime) continue;

			// 해당 공항에 최소시간으로 가는 비용보다 높은 비용으로 가는 방법들을
			// 최소시간으로 업데이트 해준다 (무의미한 계산을 막기 위함)
			for (int j = nCost; j <= M; j++) {
				if (dp[next][j] > nTime) {
					dp[next][j] = nTime;
				}
			}
			pq.push({ nTime, next, nCost });
		}
	}

	
}


int main() {

	//입력
	cin >> T; //테스트 케이스

	while (T--) {
		cin >> N >> M >> K; //공항 수, 비용 제약, 간선 개수
				
		while (K--) {
			int from, to, cost, time;
			cin >> from >> to >> cost >> time;
			graph[from].clear(); //초기화
			graph[from].push_back({ time, to, cost}); //(시간, 도착 노드, 비용)
		}

		dijkstra(); //다익스트라 호출 

		//dp[N][0]~dp[N][10000] min을 갱신하면서 최단경로 탐색.
		int MIN = *min_element(dp[N].begin(), dp[N].end());
		if (MIN == INF) cout << "Poor KCM" << "\n";
		else cout << MIN << "\n";

	}
	
	return 0;

}