/* 
 |Max값|길이
ㅡㅡㅡㅡㅡㅡㅡ
1|A[1] | 1
2|     |
3|     |
*/

#include <iostream>
using namespace std;

int dp[1001][2];
int A[1001]; //수열
int N;

int getMaxLength() {
	dp[1][0] = A[1]; //최댓값 
	dp[1][1] = 1; //길이

	//점화식
	for (int i = 2; i <= N; i++) {
		//증가할 경우
		if (dp[i - 1][0] < A[i]) { 
			dp[i][0] = A[i]; //최댓값 갱신
			dp[i][1] = dp[i - 1][1] + 1; //길이 갱신
		}
		//이전 값으로 갱신
		else { 
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
		}
	}

	return dp[N][1]; //길이

}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> A[i];

	cout<<getMaxLength();

	return 0;
}