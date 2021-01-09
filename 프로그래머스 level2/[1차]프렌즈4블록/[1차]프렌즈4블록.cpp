#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector <char>> v;
vector<pair <int, int>> p; //삭제할 좌표 <행, 열>

void check(char c, int i, int j){
    
    if(v[i][j+1]==c && v[i+1][j] == c && v[i+1][j+1] == c){
        
        if(find(p.begin(), p.end(), make_pair(i, j)) == p.end())
            p.push_back(make_pair(i, j));
        if(find(p.begin(), p.end(), make_pair(i, j+1)) == p.end())
            p.push_back(make_pair(i, j+1));
        if(find(p.begin(), p.end(), make_pair(i+1, j)) == p.end())
            p.push_back(make_pair(i+1, j));
        if(find(p.begin(), p.end(), make_pair(i+1, j+1)) == p.end())
            p.push_back(make_pair(i+1, j+1));
    
    } 
        
}


int solution(int m, int n, vector<string> board) {
    
    
    //재구성(지우기 쉽게)
    vector<char> tmp;
    for(int i=0;i<n;i++){ //열
        for(int j=m-1;j>=0;j--){ //행
            tmp.push_back(board[j][i]);
        }
        v.push_back(tmp);
        tmp.clear();
    }
    
    
    int answer = 0;
    while(1){
        for(int i=0;i<v.size()-1;i++){
            for(int j=0;j<v[i].size()-1;j++){
                if(v[i][j] == '0') continue;
                check(v[i][j], i, j); //2x2체크
            }     
        }
        
        //리스트에 담긴 원소 수 -> 0이면 break 
        //아니면 answer에 누적 
        if(p.size() == 0) return answer;
        else answer += p.size();
        
        //그 후 표시한 좌표 부분 제외하고 삽입
        vector<vector <char>> tmp_v; vector<char> t;
        for(int i =0;i<v.size();i++){
            int count = 0; 
            for(int j=0;j<v[0].size();j++){
                bool flag = false;
                for(int k =0;k<p.size();k++){
                    if(i == p[k].first && j == p[k].second){
                        count++; 
                        flag = true; 
                        p.erase(p.begin()+k); k--;
                        break;  
                    }
                }
                if(flag == false) t.push_back(v[i][j]);
                
            }
            for(int u=0;u<count;u++) t.push_back('0');
            tmp_v.push_back(t);
            t.clear();
            
        }
        
        v = tmp_v; //복사
        
        //좌표 리스트 비워주기
        p.clear(); tmp_v.clear(); 
        
    }
  
    
}