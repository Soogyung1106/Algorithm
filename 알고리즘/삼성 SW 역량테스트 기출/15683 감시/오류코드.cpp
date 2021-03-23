#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M; //세로, 가로
vector<vector<int>> dir = { //동:1, 북:2, 서:3, 남:4
	{},{1},{1,3}, {1,2}, {1,2,3}, {1,2,3,4}
}; 
vector<tuple<int, int, int>> cctv; //(cctv 번호, 좌표Y, 좌표X)
int blindSpot = 100;

int countSpot(vector<vector<int>> tmp) {
	int cnt = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			if (tmp[i][j] == 0) cnt++;

	return cnt;
}

vector<vector<int>> monitorUpdate(int dir, vector<vector<int>> update, tuple<int, int> pos) {
	//cctv 위치에서 dir 방향으로 감시하기, 감시한 것은 -1로 표시하기
	int y, x;
	tie(y, x) = pos;
	
	
	switch (dir)
	{
	case 1: //동
		if (x+1 < M) {
			for (int i = x + 1; i <= M - 1; i++) {
				if (update[y][i] == 6) break;
				if (update[y][i] == 0) update[y][i] = -1;
			}
		}
	case 2: //북
		if (y-1 >= 0) {
			for (int i = y - 1; i >= 0; i--) {
				if (update[i][x] == 6) break;
				if (update[i][x] == 0) update[i][x] = -1;
			}
		}
	case 3: //서
		if (x-1 >= 0) {
			for (int i = x - 1; i >= 0; i--) {
				if (update[y][i] == 6) break;
				if (update[y][i] == 0) update[y][i] = -1;
			}
		}
	case 4: //남
		if (y+1 < N) {
			for (int i = y + 1; y <= N-1; i++) {
				if (update[i][x] == 6) break;
				if (update[i][x] == 0) update[i][x] = -1;
			}
		}
	}
	
	return update;
}

void dfs(vector<vector<int>> tmp, int depth) {
	
	//기저조건 
	if (depth == cctv.size()) {
		blindSpot = min(countSpot(tmp), blindSpot);
		return;
	}

	//cctv[depth]에 대해서 모든 방향에 대해 감시 영역을 갱신. 
	int cctvNum, y, x;
	tie(cctvNum, y, x) = cctv[depth];

	if (cctvNum == 1 || cctvNum == 3 || cctvNum == 4) { 

		for (int i = 1; i <= 4; i++) { //4방향 회전
			vector<vector<int>> update = tmp;
			for (int j = 0; j < dir[cctvNum].size(); j++) {  //1, 3 방향일 경우..
				int nextDir = (dir[cctvNum][j] + i) % 4;
				update = monitorUpdate(nextDir, update, {y, x});
			}
			dfs(update, depth + 1); 
		}
	}
	else if (cctvNum == 2) {

		for (int i = 0; i < 2; i++) {  //2방향 회전
			vector<vector<int>> update = tmp;
			if (i == 0) {
				update = monitorUpdate(1, update, { y, x });
				update = monitorUpdate(3, update, { y, x });
				dfs(update, depth + 1);
			}
			if (i == 1) {
				update = monitorUpdate(2, update, { y, x });
				update = monitorUpdate(4, update, { y, x });
				dfs(update, depth + 1);
			}
		}
	}
	else { //1방향
		vector<vector<int>> update = monitorUpdate(1, tmp, { y, x });
		update = monitorUpdate(2, update, { y, x });
		update = monitorUpdate(3, update, { y, x });
		update = monitorUpdate(4, update, { y, x });

		dfs(update, depth + 1);
	}
}

int main() {

	freopen("input1.txt", "r", stdin);
	cin >> N >> M;

	vector<vector<int>> map(N+1, vector<int>(M+1, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 6 && map[i][j] != 0) cctv.push_back( {map[i][j], i, j });
		}
	}

	dfs(map, 0); //사각지대 영역 최소 개수 탐색 
	
	cout << blindSpot << '\n';

	return 0;
}