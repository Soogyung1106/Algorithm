#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	int N;
	vector<int> v;
	v.push_back(INT_MAX);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		
		if (v.back() < x) v.push_back(x);
		else *lower_bound(v.begin(), v.end(), x) = x;
	}

	cout << v.size()<<'\n';
	return 0;
}