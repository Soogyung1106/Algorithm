//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

vector<int> v;

int lower_binary(int x) { //x이상인 노드의 위치. 
	int start = 0, end = v.size() - 1, mid = 0;

	while (start < end) {
		mid = (start + end) / 2;

		if (x <= v[mid]) end = mid;
		else start = mid + 1;
	}

	return end;
}

int upper_binary(int x) { //x 초과인 노드의 위치.
	int start = 0, end = v.size() - 1, mid = 0;

	while (start < end) {
		mid = (start + end) / 2;

		if (x < v[mid]) end = mid;
		else start = mid + 1;
	}
	
	return end;
}

int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x; 
		cin >> x;
		v.push_back(x);
	}

	//이분탐색 전 정렬. 
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		int upper = upper_binary(x);
		if (upper == N - 1 && v[N - 1] == x) upper++;

		int lower = lower_binary(x);

		cout << upper - lower << " ";
	}

	cout << '\n';
	return 0;
}