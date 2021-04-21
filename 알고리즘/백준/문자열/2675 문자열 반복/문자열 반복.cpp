//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {

	//freopen("input1.txt", "r", stdin);
	int N;
	cin >> N;
	while (N--) {
		int n; cin >> n; 
		string s; cin >> s;

		string answer;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < n; j++) {
				answer += s[i];
			}
		}

		cout << answer << '\n';
	}


	return 0;
}