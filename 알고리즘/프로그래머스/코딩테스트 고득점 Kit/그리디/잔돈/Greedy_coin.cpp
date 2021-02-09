#include <iostream>
#include <cstdio>

using namespace std;

int greedy(int* arr, int N, int K) {
	//arr 배열에 있는 동전들을 통해 K원을 만드는데 필요한 동전의 개수를 출력 

	int count = 0; int curr = K;

	for (int i = N-1; i >= 0; i--) { //뒤에서부터 접근 
		if (curr >= arr[i] && curr != 0 ) {
			int tmp = curr / arr[i]; 
			curr = curr - tmp * arr[i];
			count += tmp;
		}
	}

	return count;

}


int main() {

	//입력 
	int N, K; // N개의 줄에 동전, K원을 만들어야 함. 
	cin >> N >> K;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	//출력 
	cout << greedy(arr, N, K);



}