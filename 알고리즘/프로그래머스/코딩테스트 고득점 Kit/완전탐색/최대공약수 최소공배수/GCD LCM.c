#include <stdio.h>

int main() {

	//Please Enter Your Code Here



	int A, B;
	scanf("%d %d", &A, &B);

	int tmp_A = A; int tmp_B = B;

	//GCD 구하기(유클리드 호제법) 
	int GCD = 0;
	int r; // A를 B로 나눈 나머지 

	while (1) {
		r = A % B;

		if (r == 0) {
			GCD = B;
			break;
		}
		A = B;
		B = r;
	}

	//LCM 구하기 
	int a = tmp_A / GCD;
	int b = tmp_B / GCD;
	//printf("%d\n", b); //test
	int LCM = a * b * GCD;

	printf("%d\n", GCD);
	printf("%d", LCM);



	return 0;
}