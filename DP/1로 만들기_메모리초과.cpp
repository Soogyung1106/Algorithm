#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

void doOperation(int n, int count) {
	//연산 1, 2, 3 중 가능한 모든 연산을 수행. 수행할 때 횟수를 카운팅
	//연산 결과가 1이 될 경우 횟수를 return 

	int tmp_n = n;	int tmp_count = count; //n과 count 값이 변해 있음. 

	if (n == 1) {
		v.push_back(count);
		return;
	}
		
	if (n % 3 == 0) {
		n /= 3;
		count++;
		doOperation(n, count);
	} else if (n % 2 == 0) {
		n /= 2;
		count++;
		doOperation(n, count);
	}
	
	//항상 수행하는 연산
	tmp_n -= 1;
	tmp_count++;
	doOperation(tmp_n, tmp_count);

}


int main() {

	int n;	scanf("%d", &n);
	
	int count = 0; //연산횟수

	doOperation(n, count); //모든 경우의 수에 대해 연산의 횟수 벡터에 저장

	printf("%d", *min_element(v.begin(), v.end()));
	printf("\n");

	/* 테스트
	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}
	*/

}