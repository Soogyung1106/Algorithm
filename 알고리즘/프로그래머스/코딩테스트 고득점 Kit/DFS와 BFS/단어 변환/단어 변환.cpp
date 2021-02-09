#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool canChange(string from, string to){
    //변환 가능여부를 체크하는 함수.
    int cnt = 0;
    for(int i=0;i<from.size();i++)
        if(from[i] != to[i])
            cnt++;
    
    return cnt >= 2 ? false : true;    
}

int solution(string begin, string target, vector<string> words) {
    
    
    //사전순 정렬
    sort(words.begin(), words.end());
    
    vector<pair<string,int>> vp; //문자, 해당 위치 인덱스
    for(int i=0;i<words.size();i++)
        vp.push_back(make_pair(words[i], i));
    
    //bfs 탐색
    vector<int> visited(words.size(), 0); //방문 여부 체크 및 최소 단계 저장
    queue<pair<string, int>> q;
    q.push(make_pair(begin, 0)); 
    while(!q.empty()){
        pair<string, int> front = q.front();
        q.pop();
        
        for(int i=0;i<vp.size();i++){
            //변환 가능하다면.
            if(canChange(front.first, vp[i].first) && !visited[i]){ 
                q.push(make_pair(vp[i].first, vp[i].second));
                visited[i]  = visited[front.second] + 1;
            }
        }
    }
    
    vector<string>::iterator it = find(words.begin(),words.end(), target);
    if(it == words.end()) return 0;
    else  return visited[it-words.begin()];
    
}