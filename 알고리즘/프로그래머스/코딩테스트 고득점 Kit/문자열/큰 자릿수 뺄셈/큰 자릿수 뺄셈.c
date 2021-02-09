//정수 범위 초과해서 에러뜨는 코드 -> 작은 수에서는 돌아감

#include <iostream>
#include <string>
using namespace std;

int main() {
	/*
	크기 제한 o 문자열 입력 -> C언어 char[] 배열
	공백이 없는 문자열 및 크기 제한x 입력 -> C++언어 string 자료형
	공백이 있는 문자열 입력 -> C++언어 getline 함수

	C++ <string> -> stoi() 인자로 char형 배열이 들어감
	C <string.h> -> atoi() 인자로 string 자료형이 들어감
	*/
	string strA; 
	string strB;
	cin >> strA >> strB;

	int numA = stoi(strA);
	int numB = stoi(strB);

	cout << numA - numB;
  

}
