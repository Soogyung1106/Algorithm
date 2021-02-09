#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>


using namespace std;

bool compare(pair <int, double> a, pair <int, double> b){
    return a.second == b.second ? a.first < b.first : a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    
    sort(stages.begin(), stages.end());
    
    vector<pair <int, double>> v; //(스테이지, 실패율)
    for(int i= 1;i<=N;i++){
        if(stages.size() == 0)  v.push_back(make_pair(i, 0)); //실패율 0임.
        else{
            //레벨별로 i이하인 것 count 
            double count = 0;
            for(int j=0;j<stages.size();j++){
                if(stages[j] <= i) count++;
                else break;
            }
            
            v.push_back(make_pair(i, count/stages.size()));
            
            //삭제
            while(count>0){
                stages.erase(stages.begin());
                count--;
            }
            //if(count!=0) stages.erase(stages.begin(), stages.begin()+count+1);
        }

    }
    
    sort(v.begin(), v.end(), compare);
    
    vector<int> answer;
    for(int i=0;i<v.size();i++) answer.push_back(v[i].first);
    return answer;
}