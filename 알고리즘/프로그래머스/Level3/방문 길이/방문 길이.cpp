#include <string>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

int solution(string dirs) {
    
    int curX = 0, curY = 0; //현재 위치
    int answer = 0; //처음 걸어 본 길이
    set<vector<vector<int>>> s; //경로를 넣을 집합.
    
    for(int i=0;i<dirs.size();i++){
        
        vector<int> from = {curX, curY};
        int tmpX = curX, tmpY = curY;
        if(dirs[i] == 'U') tmpY++;
        if(dirs[i] == 'D') tmpY--;
        if(dirs[i] == 'L') tmpX--;
        if(dirs[i] == 'R') tmpX++; 
        
        //범위 확인하기 
        if(tmpX < -5 || tmpX > 5 || tmpY < -5 || tmpY > 5 )
            continue;
        
        //현재 위치 갱신
        curX = tmpX; curY = tmpY; 
        
        vector<int> to = {curX, curY};
        vector<vector<int>> tmp = {from, to};
        
        //정렬 
        sort(tmp.begin(), tmp.end(), compare);
        
        //중복 확인
        if(s.find(tmp) == s.end()){
            s.insert(tmp);
            answer++;
        }
            
    }
    return answer;
}