#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int arr[MAX];
int dp[MAX]; 
/* 
dp[i] = arr[i]가 끝에 올 경우 "최대 수열"의 길이
*/


int main() {
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	for (int i = 1; i <= N; i++) { //arr[i]가 가장 끝에 오는 경우
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i] && dp[j] + 1>dp[i]) //숫자 비교 
				dp[i] = dp[j] + 1; //갱신
		}
	}
	
	cout << *max_element(dp, dp + N + 1);
	return 0;
}