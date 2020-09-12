#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string new_id) {
	string answer = "";

	string tmp = "";
	for (int i = 0; i < new_id.size(); i++) {
		new_id[i] = tolower(new_id[i]); // 1단계: 대문자를 소문자로 치환
		char check = new_id.at(i);

		//2단계 
		if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (97 <= check && check <= 122) || (48 <= check && check <= 57))
			tmp += new_id[i];
	}
	new_id = tmp;


	//3단계 
	int i = 0;
	while (1 && new_id.size() > 1) {
		if (i == new_id.size() - 1)
			break;

		if (new_id[i] == '.' && new_id[i] == new_id[i + 1]) {  //2개 연속된다면 하나로 줄이기    
			new_id.replace(i, 2, "."); i--;
		}
		i++;
	}

	//4단계
	if (new_id[0] == '.') //처음 삭제
		new_id.replace(0, 1, "");

	int end = new_id.size() - 1; //끝 삭제
	if (new_id[end] == '.')
		new_id.replace(end, 1, "");

	//5단계
	if (new_id.empty())
		new_id = "a";

	//6단계 
	if (new_id.size() >= 16)
		new_id.replace(15, new_id.size() - 15, "");

	//예외처리
	end = new_id.size() - 1;
	if (new_id[end] == '.')
		new_id.replace(end, 1, "");

	//7단계
	string x = "";
	if (new_id.size() <= 2)
		x = new_id.back();

	while (1) {
		if (new_id.size() >= 3)
			break;
		new_id += x;
	}


	answer = new_id;
	return answer;
}