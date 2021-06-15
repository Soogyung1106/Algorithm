//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <set>
#include <cstring>
using namespace std;

string str;
set<string> st;

void backTracking(string pre, bool visited[]) {
	//기저조건
	if (pre.size() == str.size()) {
		if (!st.count(pre)) st.insert(pre);
		return;
	}

	//재귀 호출하면서 이전것 문자랑 같은지 다른지 판단...->같으면 종료 혹은 넘어가기 
	for (int i = 0; i < str.size(); i++) {
		if (visited[i]) continue;
		if (pre != "" && pre.back() == str[i]) continue;
		
		visited[i] = true;
		backTracking(pre + str[i], visited);
		visited[i] = false; //복귀
	}

}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	//freopen("input1.txt", "r", stdin);
	cin >> str;

	bool visited[11]; memset(visited, false, 11);
	backTracking("", visited); 
	
	cout << st.size()<<'\n';

	return 0;
}