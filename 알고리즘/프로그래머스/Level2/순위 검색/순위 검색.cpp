#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

map<string, vector<int>> db; //info 정보가 map 형식으로 db에 들어감.
vector<int> answer; //쿼리에 해당하는 로우의 개수 

void infoToMap(string info){
    
    //토큰화하기 
    int score = 0; string tokens[4][2]={{"-"}, {"-"}, {"-"}, {"-"}};
    
    istringstream iss(info);
    iss>>tokens[0][1]>>tokens[1][1]>>tokens[2][1]>>tokens[3][1]>>score;
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int h=0;h<2;h++){
                    //key만들기
                    string key = tokens[0][i]+tokens[1][j]+tokens[2][k]+tokens[3][h];
                    //map에 value와 함께 저장
                    db[key].push_back(score);
                }
            }
        }
    }

}

void findQuery(string key, int score){
    
    vector<int> scores = db[key];
    
    //이진탐색
    int x = scores.end() - lower_bound(scores.begin(), scores.end(), score);
    answer.push_back(x);
   
}


vector<int> solution(vector<string> info, vector<string> query) {
    
    //info를 토큰화해서 map에 저장
    for(auto elem : info)
        infoToMap(elem); 
    
    //정렬 -> 시간 효율 때문에 밖으로 뺌.
    for(auto& elem : db)
        sort(elem.second.begin(), elem.second.end());
   
    for(auto elem : query){  
        //query를 토큰화해서 key로 만듬.
        istringstream iss(elem);
        string data[4]; string trash = ""; int score = 0;
        iss>>data[0]>>trash>>data[1]>>trash>>data[2]>>trash>>data[3]>>score;
        string key = data[0] + data[1] + data[2] + data[3];
        
        //key에 해당하는 값 들 중 x점 이상이 몇 개 있는지 카운트해서 answer에 저장
        findQuery(key, score);
    }
        
    return answer;
    
}