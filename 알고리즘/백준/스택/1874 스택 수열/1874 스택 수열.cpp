#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> v;
stack<int>stk;
vector<char> answer;

int main() {

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int pos = 0;
	for (int i = 1; i <= n; i++) {
		stk.push(i);
		answer.push_back('+');
		while (stk.size() && stk.top() == v[pos]) {
			stk.pop();
			answer.push_back('-');
			pos++;
		}
	}

	if (stk.size()) cout << "NO" << "\n";
	else for (char a : answer) cout << a << "\n";

	return 0;
}
