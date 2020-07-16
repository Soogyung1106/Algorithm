#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main() {

	//아주 큰 자리수는 int로도 받지 못하고 string도 받지 못하므로 배열로 데이터를 저장하는 수밖에 없음.
	char num1[101]; char num2[101]; int answer[101] = { 0 };
	scanf("%s", num1); scanf("%s", num2);

	// 문자의 끝 위치 
	int len_num1 = strlen(num1); int len_num2 = strlen(num2);

	//크기 비교 
	char* A = 0; char* B = 0; //절대값이 큰 것을 A로 두고 플마(A-B) 로 계산
	int val = 0;

	if (len_num1 > len_num2) {
		A = num1; B = num2;
	}
	else if (len_num1 < len_num2) {
		A = num2; B = num1; //나중에 결과값에 val 값 곱해야 함 .
		val = -1;
	}
	else { //자리수 같을 경우

		for (int i = 0; i < len_num1; i++) {

			if (num1[i] > num2[i]) {
				A = num1; B = num2;
				break;
			}
			else if (num1[i] < num2[i]) {
				A = num2; B = num1;
				val = -1;
				break;
			}
			else if (i == len_num1 - 1) {
				printf("0");
				return 0;
			}

		}//end for
	}//end else


	// 계산 
	int len_A = 0; int len_B = 0;
	if (len_num1 > len_num2) {
		len_A = len_num1; len_B = len_num2;
	}
	else if (len_num1 < len_num2) {
		len_A = len_num2; len_B = len_num1;
	}
	else { //자리수같지만 A, B다른 값이라면 
		len_A = len_num1; len_B = len_num2;
	}

	//printf("%c\n", B[0]); //테스트 

	int j = len_B - 1;
	for (int i = len_A - 1, idx = 0; i >= 0; i--, idx++) {
		int a = A[i] - '0'; //char to int

		if (j >= 0) {
			int b = B[j] - '0';

			if (a < b) {
				a += 10;
				A[i - 1] -= 1;
			}
			
			answer[idx] = a - b; //답 출력시 뒤에서부터 출력해야 함. 거꾸로 배치
			j--;
		}
		else {
			answer[idx] = a;
		}

	}//end for


	//답 출력
	if (val == -1)
		printf("-");

	for (int i = len_A - 1; i >= 0; i--)
		printf("%d", answer[i]);


}