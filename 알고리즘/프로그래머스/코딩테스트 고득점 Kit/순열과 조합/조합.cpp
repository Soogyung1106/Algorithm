#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	// 1부터 6까지 담을 벡터
	vector<int> n;
	for (int i = 0; i < 6; i++) {
		n.push_back(i + 1);
	}

	// k=4, 4개를 뽑으니까 4개의 1과 2개의 0 저장
	int k = 4;
	vector<int> idx(k, 1);
	for (int i = 0; i < n.size() - k; i++) {
		idx.push_back(0);
	}

	// 정렬
	sort(idx.begin(), idx.end());

	//순열
	do {
		// 출력
		for (int i = 0; i < idx.size(); i++) {
			if (idx[i] == 1) {
				printf("%d ", n[i]);
			}
		}

		printf("\n");

	} while (next_permutation(idx.begin(), idx.end())); //중복된 원소를 감안해 순열 구해줌. 

	return 0;

}