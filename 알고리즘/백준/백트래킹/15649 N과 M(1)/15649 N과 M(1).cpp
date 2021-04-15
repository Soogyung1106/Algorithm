//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> answer;

void getAllCases(vector<bool> visited, int depth) {
	//기저조건
	if (depth > M) {
		for (auto a : answer)
			cout << a << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;

		visited[i] = true; answer.push_back(i);
		getAllCases(visited, depth + 1);
		
		//원상복귀
		visited[i] = false; answer.pop_back();
	}
}

int main() {

	//freopen("input3.txt", "r", stdin);
	cin >> N >> M;
	
	vector<bool> visited(N+1, false);
	getAllCases(visited, 1); //깊이

	return 0;
}
