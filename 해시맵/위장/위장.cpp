#include <string>
#include <vector>
#include <unordered_map>
#include <utility> // Pair 클래스 사용-> make_pair(), first, second 사용  

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map <string, int> hash_map; // 키: 옷의 종류(A), 값: 개수(A에 해당하는 옷들의 개수)
    string key = ""; int value = 0;
    
        
    //(1) 종류 개수 카운팅
    for(int i=0;i<clothes.size();i++){
        key = clothes[i][1];
        
        // 해시맵에 없으면 넣기  
        if(!hash_map.count(key)) //키가 해시맵에 없으면 넣기
            hash_map.insert(make_pair(key, 1)); 
           
        else  //해시맵에 있으면 키에 해당되는 '값'을 증감시키기 
            hash_map[key]++;
    }
    
    //(2) 경우의 수 세기 -> 옷의 종류가 1개일 경우, 2개일 경우...n개일 경우
    for(auto i=hash_map.begin();i!=hash_map.end();i++){
        answer *= (i -> second)+1;  //안 입을 경우도 추가
    }
    
    answer--;
    
    return answer;
}