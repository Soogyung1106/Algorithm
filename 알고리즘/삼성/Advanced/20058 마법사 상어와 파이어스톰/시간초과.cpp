//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace std;

const int MAX = 2 * 2 * 2 * 2 * 2 * 2 + 1;
int N, Q, visited[MAX][MAX], ice[MAX][MAX], tmp[MAX][MAX], iceSize;
int moveY[4] = { 0, 0, 1, -1 };
int moveX[4] = { 1, -1, 0, 0 };


void turn(int y, int x, int size) {
	//부분 격자의 시작 위치(y, x)를 기준으로 2^L 사이즈의 정사각형 영역을 90도 회전
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
			tmp[i][j] = ice[y + size - 1 - j][x + i];

	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
			ice[y + i][x + j] = tmp[i][j];
}
	
void meltIce() {

	vector<tuple<int, int>> pos;
	for (int i = 1; i <= pow(2, N); i++) { //행
		for (int j = 1; j <= pow(2, N); j++) { //열
			
			if (ice[i][j] == 0) continue; //얼음이 없는 곳이라면..

			int cnt = 0; //인접한 얼음의 개수
			for (int k = 0; k < 4; k++) {
				int nextY = i + moveY[k], nextX = j + moveX[k]; 

				if (nextY < 1 || nextY > pow(2, N) || nextX < 1 || nextX > pow(2, N)) continue; //범위 밖
				if (ice[nextY][nextX] != 0) cnt++;
			}

			if (cnt <= 2) pos.push_back({ i, j }); //동시에 녹이기 위해 좌표 모아두기
		}
	}

	for (auto p : pos) ice[get<0>(p)][get<1>(p)]--;
}

void makeFireStorm(int L) { 

	//2^L 길이 정사각형 크기로 격자를 나눔. 
	int size = pow(2, L);
	for (int i = 1; i < (int)pow(2, N); i = i + size) {
		for (int j = 1; j  < (int)pow(2, N); j = j + size){
			turn(i, j, size); //시계방향으로 90도 회전
		}
	}

	//얼음의 양을 줄이기 
	meltIce();
}

int sumIce() {
	int sum = 0;
	for (int i = 1; i <= pow(2, N); i++) 
		for (int j = 1; j <= pow(2, N); j++) 
			sum += ice[i][j];

	return sum;
}

/*
void dfs(int y, int x) {
	visited[y][x] = 1;
	iceSize++;

	for (int i = 0; i < 4; i++) {
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (nextY < 1 || nextY > pow(2, N) || nextX < 1 || nextX > pow(2, N)) continue;
		if (ice[nextY][nextX] && !visited[nextY][nextX])  //얼음이 있고, 방문한 적 없다면..
			dfs(nextY, nextX);
	}
}
*/

int dfs(int y, int x) {
	visited[y][x] = 1;
	int size = 1;

	for (int i = 0; i < 4; i++) {
		int nextY = y + moveY[i];
		int nextX = x + moveX[i];

		if (nextY < 1 || nextY > pow(2, N) || nextX < 1 || nextX > pow(2, N)) continue;
		if (ice[nextY][nextX] && !visited[nextY][nextX])  //얼음이 있고, 방문한 적 없다면..
			size += dfs(nextY, nextX);
	}

	return size;
}

int getBiggestIce() { //bfs로 가장 큰 얼음 덩어리의 크기를 구하는 함수.	
	
	int maxIce = 0;
	for (int i = 1; i <= pow(2, N); i++){
		for (int j = 1; j <= pow(2, N); j++) {

			//방문한 적 없고 얼음이 있다면.
			/*
			if (!visited[i][j] && ice[i][j]) {
				dfs(i, j); //(i, j)를 기준으로 dfs로 얼음의 크기 탐색 
				maxIce = max(maxIce, iceSize);
				iceSize = 0;
			}
			*/

			if (!visited[i][j] && ice[i][j]) {
				//dfs(i, j); //(i, j)를 기준으로 dfs로 얼음의 크기 탐색 
				maxIce = max(maxIce, dfs(i, j));
				//iceSize = 0;
			}
		}
	}

	return maxIce;
}

int main() {

	//입력
	//freopen("input1.txt", "r", stdin);
	cin >> N >> Q;
	for (int i = 1; i <= pow(2, N); i++) 
		for (int j = 1; j <= pow(2, N); j++) 
			cin >> ice[i][j];
	
	while(Q--) {
		int L;
		cin >> L;
		makeFireStorm(L); //파이어스톰 생성
	}

	//출력
	cout << sumIce()<<'\n'; //남아있는 얼음의 합
	cout << getBiggestIce() << '\n'; //남아있는 얼음 중 가장 큰 덩어리 크기

	return 0;
}