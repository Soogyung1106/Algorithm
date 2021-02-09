#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;
int row;
int col;
vector<string> combination;

bool compare(string& str1, string& str2) {
    return str1.size() < str2.size() ? true : false;
}

//가능한 모든 조합을 구하는 함수
void comb(int k, string tmp) { //k=0
    for (int i = k; i < col; i++) {
        tmp += to_string(i);
        combination.push_back(tmp);
        comb(i + 1, tmp);
        tmp = tmp.substr(0, tmp.length() - 1);
    }
}

//컬럼 조합이 후보키가 되는지 판별
bool isCandidate(vector<vector<string>> relation, string combi) { 
    map<string, bool> isUnique; //중복 여부 판단하기 위해 
    for (int i = 0; i < row; i++) {
        string tmp = "";
        for (int j = 0; j < combi.size(); j++) {
            int checkCol = combi[j] - '0';
            tmp += relation[i][checkCol]; 
            //(이름 0행, 전공 0행) => tmp
            //(이름 1행, 전공 1행) => tmp 
        }
        if (isUnique[tmp]) return false; //중복 존재
        else isUnique[tmp] = true; //데이터 삽입
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;

    row = relation.size();
    col = relation[0].size();

    comb(0, ""); //가능한 조합의 수를 구한다.
    sort(combination.begin(), combination.end(), compare); //조합된 개수가 적은 것 순으로 정렬함. 
                                                            //(앞쪽에 기본키 위치)
        
    for (int i = 0; i < combination.size(); i++) {
        
        if (isCandidate(relation, combination[i])) { //후보키이면.
            string tmp = combination[i];
            for (int j = combination.size() - 1; j >= i; j--) { //기본키가 중복돼 사용된 조합 검색
                bool find = true;
                for (auto t : tmp) {
                    if (combination[j].find (t) == string::npos) {
                        find = false;
                        break;
                    }
                }
                if (find) combination.erase(combination.begin() + j); //삭제
            }
            i--; answer++;
        }//end if 
        
    }
    return answer;
}

// 코드 참조 https://velog.io/@seovalue/%EC%B9%B4%EC%B9%B4%EC%98%A4-%ED%9B%84%EB%B3%B4%ED%82%A4-C 