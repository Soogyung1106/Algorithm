#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[26][26]; 
vector<int> town; //단지  
int home; //단지에 속하는 집의 수  
int N; //N x N

//상하좌우 1칸씩 (x, y) 
int x[4] = {1, -1, 0, 0};
int y[4] = {0, 0, 1, -1};

void search(int i, int j) {
	//현재 집 위치 map[i][j]를 기준으로 주변에 집이 있는지 탐색하고 home에 추가
	//방문한 곳은 0으로 초기화

	map[i][j] = 0; 
	home++;

	//map[i][j]의 상하좌우에 1의 값이 있는지 탐색 
	for (int k = 0; k < 4; k++) {

		//예외처리(인덱스 범위 초과시)
		if (i + x[k] < 0 || i + x[k] >= N || j + y[k] < 0 || j + y[k] >= N) 
			continue;

		//(i,j) 기준 상하좌우에서 집 발견시 
		if (map[i + x[k]][j + y[k]] == 1) { 
			search(i + x[k], j + y[k]); //(i + x[k], j + y[k]) 기준으로 탐색
		}
	}

}


int main() {

	//집 입력받기
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	//단지 생성 및 집의 개수 카운팅 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			if (map[i][j] == 1) {
				home = 0; //매번 집의 개수 초기화 
				search(i, j);
				town.push_back(home); //단지에 속하는 집의 개수
			}
		}
	}
	
	//단지 개수 출력
	cout << town.size() << endl;

	//집의 개수 오름차순 출력
	sort(town.begin(), town.end());
	
	for (int i = 0; i < town.size(); i++) 
		cout << town[i] << endl;
	






}