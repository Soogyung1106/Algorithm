//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

int main() {

	//ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);

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

		cout << upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x) << " ";
	}

	cout << '\n';
	return 0;
}