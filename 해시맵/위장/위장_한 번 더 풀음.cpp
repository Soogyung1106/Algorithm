#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> map; //key: 옷의 종류, value: 의상수
    
    for(int i=0;i<clothes.size();i++){
        string type = clothes[i][1];
        string name = clothes[i][0];
        
        if(!map.count(type)) //map에 없다면
            map.insert(make_pair(type, 1));
        else     
            map[type]++;   // 있다면 value값 ++
        
    }
    
    //옷을 매칭하는 모든 경우의 수
    answer = 1; 
    for(auto ptr = map.begin(); ptr != map.end(); ptr++)    
        answer *= (ptr->second + 1); //
    
    return answer-1; //예외처리: 아무것도 안 입은 경우 제외
}