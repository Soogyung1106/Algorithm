//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int N, A[100001];
int find(int x) {

	int start = 0, end = N-1, mid = 0; //탐색 인덱스 

	while (start<=end) {
		mid = (start + end) / 2;

		if (A[mid] == x) 
			return 1;
		else if (A[mid] < x) 
			start = mid + 1;
		else 
			end = mid - 1;
	}
	
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input1.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> A[i];

	sort(A, A+N); //정렬

	int M, x;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x;
		cout << find(x) << '\n'; //이분 탐색
	}

	return 0;
}