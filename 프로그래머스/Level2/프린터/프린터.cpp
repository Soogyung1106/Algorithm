#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int getMax(vector<pair <int, int>> dic){
    
    int Max = 0;
    for(int i=0;i<dic.size();i++){
        if(Max < dic[i].second) Max = dic[i].second;
    }
    
    return Max;
}


int solution(vector<int> priorities, int location) {
    
    vector<pair <int, int>> dic;  // (인덱스, 중요도)
    for(int i=0;i<priorities.size();i++)   dic.push_back(make_pair(i, priorities[i]));
    
    int answer = 0; 
    while(1){
        
        if(dic[0].second < getMax(dic)) dic.push_back(make_pair(dic[0].first, dic[0].second));     
        else{
            answer++;
            if(dic[0].first == location) return answer;
        }
        
        dic.erase(dic.begin());
    }
    
}