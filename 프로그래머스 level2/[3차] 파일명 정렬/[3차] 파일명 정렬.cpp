#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool compare(pair<int, pair<string, string>> a, pair<int, pair<string, string>> b){
    return a.second.first == b.second.first ? stoi(a.second.second) < stoi(b.second.second) : a.second.first < b.second.first;
}

vector<string> solution(vector<string> files) {
    
    vector<pair<int, pair<string, string>>> v; //인덱스, 헤드, 넘버
    for(int i=0;i<files.size();i++){
        string head =""; int h; //헤드
        for(h=0;h<files[i].size();h++){
            if(isdigit(files[i][h]))  break;
            else  head += tolower(files[i][h]); //소문자로
        }
        
        string number = ""; bool flag = true; //넘버
        for(int n=h;n<files[i].size();n++){
            if(!isdigit(files[i][n]))  break;
            number += files[i][n];  
        }
        
        v.push_back({i, {head, number}});
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    vector<string> answer;
    for(int i=0;i<v.size();i++) answer.push_back(files[v[i].first]);
    return answer;
}