#include <stdio.h>
const int MAX = 100;

char result[MAX]; //경우의 수 1가지에 대해 결과물을 담을 배열
bool check[MAX]; // check[i] == true -> 알파벳 i+'a'는 사용중 
int n, r; //사용자 입력값 

void getResult(int x) {

	//함수 정의 : x번째 자릿수에 들어갈 문자에 대해 for문이 돌아가게 하는 함수

	//기저조건 
	if (x >= r)
		printf("%s\n", result);
	else {
		for (int i = 0; i < n; i++) { //한 자리수에 대해 n가지의 경우의 수 
			char alpha = i + 'a'; //아스키코드 

			if (check[i] == false) { //true이면 사용중
				result[x] = alpha;
				check[i] = true;

				getResult(x + 1); //a-- 

				//첫 번째 자리가 a인 모든 경우에 대해 출력하고 돌아옴. 

				check[i] = false;

			}

		}

	}
	

}



int main() {

	//n P r 순열의 경우
	// 3, 2 (입력) -> ab, ac, ba....(출력)
	scanf("%d %d", &n, &r); //입력 r에 따라 for 문의 개수가 달라짐.

	getResult(0);
	

	return 0;

}
