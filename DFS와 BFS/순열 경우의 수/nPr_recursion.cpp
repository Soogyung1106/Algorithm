#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

const int MAX = 100; //상수 최대 100
int n, r; //n개 중에 r개를 뽑는 경우의 수를 구함. 
char result[MAX]; //경우의 수 문자열을 담는 배열
bool check[MAX]; //i번째 알파벳을 사용중인지 확인하는 배열

void getResult(int x) { //result 문자열의 x번째를 정하기 위해 for문을 돌리는 함수.
	
	//기저조건
	if (x == r) { //끝
		printf("%s\n", result); 
	}
	else {
		for (int i = 0; i < n; i++) { //result의 x번째에 a부터 n개의 알파벳 대입
			char alpha = i + 'a'; 

			if (check[i] == false) {  //i번째 알파벳을 사용중이지 않다면.
				result[x] = alpha;
				check[i] = true; //사용중임을 표시  
             
				//x번째에 i알파벳을 넣는 모든 경우의 수를 고려함. 
				check[i] = false; //다시 사용할 수 있도록. 
			}
		}
	}


}

int main() {

	scanf("%d %d", &n, &r);

	getResult(0);

	return 0;
}