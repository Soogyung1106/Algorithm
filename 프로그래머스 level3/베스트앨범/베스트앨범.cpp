#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>


using namespace std;

bool compare1(pair<string, int> a, pair<string, int> b){
    return a.second>b.second;
}

bool compare2(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ?  a.first < b.first : a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
   
    // 중복 여부 체크 및 조회수 총합.
    unordered_map<string, int> m; 
    for(int i=0;i<genres.size();i++){
        if(m.count(genres[i]) == 0) m[genres[i]] = plays[i];
        else m[genres[i]] += plays[i];
    }
    
    //장르별로 페어링 및 정렬
    vector<pair<string, int>> vp; 
    for(auto elem : m) vp.push_back(make_pair(elem.first, elem.second));
    sort(vp.begin(),vp.end(), compare1);
    
    //장르별로 벡터에 인덱스와, 재생수 pair로 저장 후 정렬
    vector<int> answer;
    for(int i=0;i<vp.size();i++){
        vector<pair<int, int>> tmp; //고유번호 i, 재생수 
        for(int j=0;j<genres.size();j++){
            if(vp[i].first == genres[j])
                tmp.push_back(make_pair(j, plays[j]));
        }
        
        sort(tmp.begin(), tmp.end(), compare2);
        answer.push_back(tmp[0].first);
        if(tmp.size() >= 2)  answer.push_back(tmp[1].first);
    }
    
    return answer;
}