#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	int y, x; //현재 위치
	bool arrived; //도착했는지 여부
}INFO;

int dice[11]; 
int maxScore;
bool occupied[4][30]; //말이 현재 있는 위치들을 표시
int board[5][30] = { { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40 },
{ 10, 13, 16, 19, 25, 30, 35, 40 }, //10에서 출발할 경우
{ 20, 22, 24, 25, 30, 35, 40 }, //20에서 출발할 경우
{ 30, 28, 27, 26, 25, 30, 35, 40 } //30에서 출발할 경우
}; 


void search(int turn, INFO horses[5], int curScore) {
	//dfs로 모든 경우의 수 탐색
	
	//기저조건.
	if (turn > 10) {
		maxScore = max(maxScore, curScore); //score 갱신
		return; //종료 
	}

	//1. i번 말을 움직임.  
	for (int i = 1; i <= 4; i++) { 
		//(조건1.)이미 도착한 말의 경우 고려 x
		if (horses[i].arrived) continue; 

		//(조건2.) 도착한 곳이 10, 20, 30중 하나일 경우 노선 변경.
		int nY = horses[i].y; int nX = horses[i].x + dice[turn]; //이동

		if (board[nY][nX] == 10 && nY == 0) {
			nY = 1, nX = 0; 
		}else if (board[nY][nX] == 20 && nY == 0) {
			nY = 2, nX = 0;
		}else if (board[nY][nX] == 30 && nY == 0) { //1번 노선의 30일 경우
			nY = 3, nX = 0;
		} 

		//(조건3.)이동시키려는 곳에 다른 말 이미 o 
		if (occupied[nY][nX]) {

			if (board[nY][nX] == 0 ){ //도착했다면..
				horses[i].arrived = true; //도착 표시
				
				//원래 있던 곳은 점유 false 표시
				occupied[horses[i].y][horses[i].x] = false; 
				//좌표 이동 
				horses[i].y = nY, horses[i].x = nX; 

				search(turn + 1, horses, curScore); //그 다음 턴 호출.
			}
			continue;
		}
		else { //다른 말 x

			if (board[nY][nX] == 0)   //도착했다면..
				horses[i].arrived = true; //도착 표시
			else 
				curScore += board[nY][nX]; //점수 갱신.

			//원래 있던 곳은 점유 false 표시
			occupied[horses[i].y][horses[i].x] = false;
			//좌표 이동 
			horses[i].y = nY, horses[i].x = nX; 
			
			//새로 간 곳 점유 true 표시
			occupied[nY][nX] = true; 
		
			
			//2. 그 다음 턴 호출.
			search(turn + 1, horses, curScore);
		}

	}

} 

int main() {
	//입력
	freopen("input1.txt", "r", stdin);
	for (int i = 1; i <= 10; i++)	
		cin >> dice[i];
	
	//탐색(백트래킹), 처음 시작 라인: 0행
	INFO horses[5] = { {0, 0, false}, {0, 0, false}, {0, 0, false}, {0, 0, false}, {0, 0, false} };

	search(1, horses, 0); //(턴 1번 부터 시작, 말의 위치 정보를 줌, 현재 점수)

	//출력
	cout << maxScore <<'\n';

	return 0;
}