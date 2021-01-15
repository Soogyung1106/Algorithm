#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

vector<vector <string>> tokens;

// , 코마를 기준으로 토큰화
void tokenize(vector<string>& minfo){ 
    
    for(auto m : minfo){
        string tmp = ""; vector<string> v;
        for(int i=0;i<m.size();i++){
            if(m[i] == ','){
                v.push_back(tmp);
                tmp = "";
            }else tmp += m[i];
        } 
        v.push_back(tmp);
        tokens.push_back(v);
    }
}

//#이 들어있을 경우 악보 바꾸기
void changeScore(){
    for(auto& t : tokens){
        
        for(int i=0;i<t[3].size();i++){
            if(t[3][i] == '#'){
                
                switch(t[3][i-1]){
                    case 'C' :
                        t[3][i-1] = 'c'; break;
                    case 'D' :
                        t[3][i-1] = 'd'; break;
                    case 'F' :
                        t[3][i-1] = 'f'; break;
                    case 'G' :
                        t[3][i-1] = 'g'; break;
                    case 'A' :
                        t[3][i-1] = 'a'; break;
                }
                
                t[3].erase(i, 1); 
                i--;
            }
        }//end for1  
    }//end for2

}

// 재생 시간 구하고 악보 재구성  
void getTime(){
    for(auto& t : tokens){
        
        int a = stoi(t[1].substr(0, 2)) * 60 + stoi(t[1].substr(3, 2));
        int b = stoi(t[0].substr(0, 2)) * 60 + stoi(t[0].substr(3, 2));
        
        //재생시간 원소 추가
        int play = (a-b < 0) ? (a-b) + 24*60 : a-b;
        t.push_back(to_string(play));
        
        //악보 재구성
        if(t[3].size() < play){
            int mod = play % t[3].size();
            int div = play / t[3].size();
            
            string copy = t[3];
            for(int i=0;i<div-1;i++) t[3] += copy;    
            t[3] += t[3].substr(0, mod);  
        }else if(t[3].size() > play) t[3] = t[3].substr(0, play);
        
    }//end for
}

void change(string& m){
    
    for(int i=0;i<m.size();i++){
            if(m[i] == '#'){
                
                switch(m[i-1]){
                    case 'C' :
                        m[i-1] = 'c'; break;
                    case 'D' :
                        m[i-1] = 'd'; break;
                    case 'F' :
                        m[i-1] = 'f'; break;
                    case 'G' :
                        m[i-1] = 'g'; break;
                    case 'A' :
                        m[i-1] = 'a'; break;
                }
                
                m.erase(i, 1); 
                i--;
            }
        }//end for1
}


bool compare(pair<int, int> a, pair<int, int> b){ //(재생시간, 인덱스)
    return a.first == b.first ? a.second < b.second : a.first > b.first;
}


string solution(string m, vector<string> musicinfos) {
    
    
    //코마별로 끊기 time, 제목, 악보 
    tokenize(musicinfos);
    
    //악보 #붙은거 소문자 알파벳으로 바꾸기
    changeScore();
        
    //시간 변환하기(몇 분동안?) → 재생시간에 맞게 악보수정하기
    getTime();    
    
    //m에 #이 있다면 소문자로 바꾸기
    change(m);
    
    //m이 악보에 있는지 find 하기
    int idx = 0;
    vector<pair<int, int>> p; //(재생시간, 인덱스)
    for(auto& t : tokens){
        if(t[3].find(m) != string::npos)  p.push_back(make_pair(stoi(t[4]), idx));
        idx++;
    }
    
    sort(p.begin(), p.end(), compare); //정렬
    
    return p.empty() ? "(None)": tokens[p[0].second][2]; //맨 앞 제목 출력
    
    
}