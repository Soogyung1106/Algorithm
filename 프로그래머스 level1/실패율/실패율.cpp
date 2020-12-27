#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

bool compare(pair<int, double>& a, pair<int, double>& b){
    return a.second == b.second ? a.first < b.first : a.second>b.second;
}

vector<int> solution(int N, vector<int> stages) {
    
    //실패율 구하기
    vector<pair<int, double>> v; int tmp =0;
    for(int i=1;i<= N;i++){
        int j=0; double count = 0;
        while(j<=stages.size()-1){  
            if(stages[j] == i) count++; //개수 카운팅
            j++;
        }
        
        if((stages.size()-tmp) != 0) v.push_back(pair<int, double>(i, count / (stages.size()-tmp)));   
        else v.push_back(pair<int, double>(i, 0));    
        
        tmp += count;
    }
    
    
    //정렬하기
    sort(v.begin(), v.end(), compare);
    
    vector<int> answer;
    for(int i=0;i<v.size();i++) answer.push_back(v[i].first);
    return answer;
}