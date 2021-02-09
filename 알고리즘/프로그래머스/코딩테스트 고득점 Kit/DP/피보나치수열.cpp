#include <stdio.h>
#include <iostream>

using namespace std;

int memo[100]; //인덱스 n에 피보나치수열의 n번째 요소가 저장

int dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;

	if (memo[n] != 0) return memo[n]; //메모이제이션: 이미 연산되어있으므로 배열의 값 가져다 씀.
	else return memo[n] = dp(n - 1) + dp(n - 2);
	
}

int main() {
	
	cout << "피보나치 수열의 n번째수 구하기" << endl;
	cout << "첫번째 값과 두번째 값은 1" << endl; 
	cout << "입력: "; int n; cin >> n;

	cout << dp(n);

}