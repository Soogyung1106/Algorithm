#include <iostream>
#include <algorithm>

using namespace std;

int memo[1001]; //메모이제이션: 1이상 1,000 이하 

int tiling(int n) {
	// 2xn 주어질 경우 1x2 또는 2x1로 주어진 면적을 채울 수 있는 경우의 수
	// 이미 연산한 수는 메모이제이션으로 기록 
	// 점화식 D[N] = D[N-1] + D[N-2] ☞ 피보나치 수열과 비슷
	
	if (n == 1) return memo[1] = 1;
	if (n == 2) return memo[2] = 2;

	if (memo[n] != 0) return memo[n]; //연산 중복 x

	return memo[n] = tiling(n - 1) + tiling(n - 2);

}

int main() {

	int n; cin >> n;
	cout << tiling(n) % 10007;
}