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

	//freopen("input1.txt", "r", stdin);
	scanf("%d", &N); 
	for (int i = 0; i < N; i++) 
		cin >> A[i];

	sort(A, A+N); //정렬

	int M, x;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		cout << find(x) << '\n'; //이분 탐색
	}

	return 0;
}