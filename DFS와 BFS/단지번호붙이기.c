#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// (-1, 0): 좌로 1칸, (1, 0): 우로 1칸 , (0, -1): 아래로 1칸, (0, 1): 위로 1칸 
int dx[] = { -1, 1, 0, 0 }; 
int dy[] = { 0, 0, -1, 1 };

int n;
int map[26][26]; //5<=N<=25
vector<int> town; int home; //타운에 속하는 집의 개수

void dfs(int i, int j){

	map[i][j] = 0; //한 번 들린 곳은 0으로 초기화(visited 배열 사용 대신)
	home++; //단지에 속하는 집의 개수 추가

	//상, 하, 좌, 우 살피기
	for (int k = 0; k < 4; k++){
		if (i + dx[k] < 0 || i + dx[k] >= n || j + dy[k] < 0 || j + dy[k] >= n )
			continue;
		if (map[i + dx[k]][j + dy[k]] == 1) 
			dfs(i + dx[k], j + dy[k]);
	}

}

int main(){

	//NxN 집 입력받기 
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]); //연속된 숫자들 중 1개씩 입력받기

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1){
				home = 0;
				dfs(i, j); //1인 현재 위치를 기준으로 주변에 1인 것은 모두다 카운팅 -> 단지 형성
				town.push_back(home);
			}

		}
	}
	
	//단지 개수 출력 
	printf("%d\n", town.size());

	//오름차순으로 집의 개수 출력 
	sort(town.begin(), town.end());

	for (int i = 0; i < town.size(); i++)
		printf("%d\n", town[i]);


	return 0;
}