/*
참고: https://algosu.tistory.com/99
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
 
using namespace std;
 
map<string, vector<int>> m; //value가 벡터인 이유? 쿼리에 해당하는 점수가 여러개.
 
//info 벡터를 map 구조롤 만들어주는 함수.
void infoIntoMap(string info) {
 
    string infoArr[4][2] = {
        {"-"},
        {"-"},
        {"-"},
        {"-"}
    };
    int infoScore = 0;
 
    //info 띄어쓰기 분리
    istringstream iss(info);
    iss >> infoArr[0][1] >> infoArr[1][1] >> infoArr[2][1] >> infoArr[3][1] >> infoScore;
 
    //info가 해당될 수 있는 모든 쿼리 만들기 (경우의 수 )
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    //map의 key
                    string infoString = infoArr[0][i] + infoArr[1][j] + infoArr[2][k] + infoArr[3][l];     
                    //map에 저장
                    m[infoString].push_back(infoScore);
                }
            }
        }
    }
}
 
//query를 키로 만들어주고 map에서 조건에 해당하는 것의 개수를 반환하는 함수.
int findQueryFromMap(string query) {
    
    //query 띄어쓰기 분리
    string queryArr[4]; int queryScore = 0; string trash = "";
    istringstream iss(query);
    iss >> queryArr[0] >> trash >> queryArr[1] >> trash 
        >> queryArr[2] >> trash >> queryArr[3] >> queryScore;
 
    //map의 key만들기
    string queryString = "";
    for (int i = 0; i < 4; i++) 
        queryString += queryArr[i];
    
    //findScores = map의 value
    vector<int> findScores = m[queryString]; //쿼리 스트링에 해당하는 info 점수들 모두 벡터에 저장
 
    //해당 백터에서 queryScore의 lower_bound를 찾고 개수 계산
    int output = findScores.end() - lower_bound(findScores.begin(), findScores.end(), queryScore);
 
    //개수 반환
    return output;
}
 
vector<int> solution(vector<string> info, vector<string> query) {
 
    //주어진 info를 map에 담기 - value는 점수, key는 나머지 정보
    for (int i = 0; i < info.size(); i++) 
        infoIntoMap(info[i]);
    
    //map에서 키에 해당하는는 값들 정렬
    for (auto& elem: m) 
        sort(elem.second.begin(), elem.second.end());
 
    //query를 분리해서 answer에 저장
    vector<int> answer;
    for (int i = 0; i < query.size(); i++) 
        answer.push_back(findQueryFromMap(query[i]));
    
    //반환
    return answer;
}
