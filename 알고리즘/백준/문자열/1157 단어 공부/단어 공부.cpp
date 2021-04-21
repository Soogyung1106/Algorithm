//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, char> a, pair<int, char> b) {
	return a.first > b.first;
}

int main() {

	//freopen("input1.txt", "r", stdin);
	string s;
	cin >> s;

	map<char, int> m; //(문자, 등장횟수)
	for (int i = 0; i < s.size(); i++) {
		char c = toupper(s[i]);
		if (m.find(c) != m.end()) m[c] += 1;
		else m[c] = 1;
	}

	//정렬 
	vector<pair<int, char>> v;
	for (auto e : m) v.push_back({ e.second, e.first });
	sort(v.begin(), v.end(), compare);

	//출력
	if (s.size() >= 2) {
		if (v[0].first == v[1].first) cout << '?';
		else cout << v[0].second;
	}
	else cout << v[0].second;
	return 0;
}