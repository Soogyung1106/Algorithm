#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char board[50][50];
int N, M;
char case1[9][9] = { "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW" };
char case2[9][9] = { "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW", "WBWBWBWB"};

int main() {

	//입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	vector<int> answer;
	
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) { // 시작점 (i, j)

			int diffToCase1 = 0, diffToCase2 = 0;
			for (int col = i; col < col + 8; col++) {
				for (int row = j; row < row + 8; row++) { //8x8 다른개수 체크
					if (board[col][row] != case1[col - i][row - j]) diffToCase1++;
					if (board[col][row] != case2[col - i][row - j]) diffToCase2++;
				}
			}
			answer.push_back(min(diffToCase1, diffToCase2));
		}
	}

	cout << *min_element(answer.begin(), answer.end());
		
	return 0;
}
