//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll N, K;

ll binary() {

	//x(특정 수 = mid)이하인 것이 K개인 경우를 찾아야 함. 
	ll start = 1, end = K, mid = 0, res = 0;

	while (start <= end) {
		mid = (start + end) / 2;

		//x(특정 수 = mid)이하인 것이 A배열에서 몇개인지 찾아야 함. 
		ll cnt = 0;
		for (ll i = 1; i <= N; i++)
			cnt += std::min(N, mid / i);

		if (cnt < K) 
			start = mid + 1;
		else { 
			res = mid;
			end = mid-1;
		}
	}

	return res;
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> N >> K;

	cout<< binary()<< '\n';

	return 0;
}