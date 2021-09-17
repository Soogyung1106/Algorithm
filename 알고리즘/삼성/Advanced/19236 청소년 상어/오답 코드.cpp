#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
	int y, x, dir;
}FISH;

typedef struct {
	int y, x, dir;
}SHARK;

const int moveY[] = { 0, -1,-1,0,1,1,1,0,-1 };
const int moveX[] = { 0, 0,-1,-1,-1,0,1,1,1 };

bool isInRange(int y, int x) {
	return y >= 0 && x >= 0 && y < 4 && x < 4;
}

int search(FISH fish[17], SHARK shark, int map[4][4]) { //이동할 수 있는 모든 경우에 대해 먹은 물고기 번호의 최대 합 저장.
	
	//상어는 물고기의 방향으로 바뀜.
	int ate = map[shark.y][shark.x];
	shark.dir = fish[ate].dir;
	
	//상어가 물고기를 먹음.
	//fish[ate].y = fish[ate].x = -1;
	fish[ate].dir = -1;
	map[shark.y][shark.x] = -1; 
	
	//물고기 이동.
	for (int i = 1; i <= 16; i++) { //1~16번 물고기 차례차례 이동
		if (fish[i].dir == -1) continue; //물고기가 없으면 skip

		int dir = fish[i].dir;
		int nextY = 0, nextX = 0;
		bool fail = false; 
		/*
		while (1) {
			nextY = fish[i].y + moveY[dir], nextX = fish[i].x + moveX[dir];

			//이동 할 수 없다면(범위 밖, 상어가 있는 칸) 반시계방향 45도 회전.
			if (!isInRange(nextY, nextX) || (shark.y == nextY && shark.x == nextX)) {
				dir += 1; 
				if (dir == 9) dir = 1;
			}
			else {
				canMove = true;
				break; //이동 가능
			} 

			if (dir == fish[i].dir) break;
		}
		*/

		while (1) {
			nextY = fish[i].y + moveY[dir]; nextX = fish[i].x + moveX[dir];

			//이동 가능하다면..
			if (isInRange(nextY, nextX) && (shark.y != nextY || shark.x != nextX)) break;

			//아닌 경우 반시계방향 회전
			if (++dir > 8) dir = 1; 
			
			//물고기가 이동할 수 있는 방향이 없는 경우
			if (dir == fish[i].dir) { 
				fail = true;
				break;
			}
		}



		//물고기가 이동 불가능하다면..
		if (fail) continue;

		//다른 물고기와 위치 바꾸기(map에서 바꿔주기, fish 방향과 위치 바꿔주기)
		if (map[nextY][nextX] != -1) { // 다른 물고기와 위치 변경
			fish[map[nextY][nextX]].y = fish[i].y;
			fish[map[nextY][nextX]].x = fish[i].x;
		}

		map[fish[i].y][fish[i].x] = map[nextY][nextX];
		map[nextY][nextX] = i;
		fish[i].y = nextY;
		fish[i].x = nextX;
	}

	//상어가 움직일 수 있는 곳 모두 탐색.
	int nyShark = shark.y, nxShark = shark.x;
	int ret = ate;
	/*
	for (int i = 0; i < 4; i++) { //이동 가능 최대 4가지
		nyShark += moveY[shark.dir]; nxShark += moveX[shark.dir];

		if (!isInRange(nyShark, nxShark) || map[nyShark][nxShark] == -1) continue;

		shark.y = nyShark, shark.x = nxShark; //상어 이동.
		ret = max(ret, ate + search(fish, shark, map));
	}
	*/
	while (1) {
		nyShark += moveY[shark.dir]; nxShark += moveX[shark.dir];

		if (!isInRange(nyShark, nxShark)) break; 
		if(map[nyShark][nxShark] == -1) continue;

		shark.y = nyShark, shark.x = nxShark; //상어 이동.
		ret = max(ret, ate + search(fish, shark, map));
	}

	return ret;
}

int main() {

	//입력
	FISH fish[17]; //현재 물고기의 위치, 방향 저장.
	int map[4][4]; //맵에는 물고기의 번호가 들어감.

	freopen("input1.txt", "r", stdin);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;
			fish[num].y = i, fish[num].x = j, fish[num].dir = dir;
			map[i][j] = num;
		}
	}
	
	//초기 상어의 위치 
	SHARK shark; //상어의 위치, 방향 저장.
	shark.y = 0, shark.x = 0;
	
	//탐색(shark 위치의 물고기를 먹음 => 물고기 이동 ) 후 출력
	cout << search(fish, shark, map) << '\n';
	return 0;
}