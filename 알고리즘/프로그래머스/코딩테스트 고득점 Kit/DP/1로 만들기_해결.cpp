#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;
int memo[1000001]; //메모이제이션: N은 최대 10^6, memo[i]는 i값을 1로 만드는데 필요한 최소 연산 횟수

int doOperation(int n) {
	//n을 1로 만드는데 필요한 연산 횟수를 구함.
	//연산의 중복을 제거하기 위해 이미 연산한 값은 배열에 기록

	int n1 = n, n2 = n, n3 = n;	int min = 0;

	if (n == 1) return memo[1] = 0;	
	if (n == 2) return memo[2] = 1;
	if (n == 3) return memo[3] = 1;
	if (memo[n] != 0) return memo[n]; //이미 연산을 했다는 뜻. 중복 방지


	if (n % 3 == 0) {
		n1 /= 3; min = 1 + doOperation(n1);
	}if (n % 2 == 0) {
		n2 /= 2; 

		/* 아래 1줄 코드로 해결
		if (min == 0) { //첫 번째 연산 수행 x
			min = 1 + doOperation(n2);
		}else{ //첫 번째 연산 수행 o
			if (min > 1 + doOperation(n2)) min = 1 + doOperation(n2);
			//else min = min;
		}
		*/
		min = (min == 0 || (min != 0 && min > 1 + doOperation(n2))) ? min = 1 + doOperation(n2) : min;

	}if (n > 0) { //항상 수행하는 연산
		n3 -= 1; 
		return memo[n] = (min == 0 || (min!=0 &&min > 1 + doOperation(n3))) ? 1 + doOperation(n3) : min; // 최종적으로 연산의 최소 횟수를 배열에 저장 
	}
	  

}


int main() {

	int n;	cin >> n; //최대 10의 6승 

	cout << doOperation(n);


}