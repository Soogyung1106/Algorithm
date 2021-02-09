#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(string begin, string target, vector<string> words) {
  
    int n = begin.size();
    bool visited[50] = {false};
    queue<pair <string, int>> q; //(변환한 문자열, 연산 몇번째인지)
    q.push({begin, 0});
    
    while(!q.empty()){
        
        string before = q.front().first;
        int count = q.front().second;
        q.pop();
        
        for(int i=0;i<words.size();i++){ //i번째로 변환 가능한지 check 
            if(visited[i]) continue; //방문한 것은 skip
            
            int diff = 0;
            for(int j=0;j<n;j++){
                if(words[i][j] != before[j]) diff++;
            }
            
            if(diff == 1){ //변환 가능한 단어임. 
                if(words[i] == target) return count+1;
                visited[i] = true;
                q.push({words[i], count+1});   
                cout<<words[i]<<", "<<count+1<<" ";
            }
        }
        cout<<endl;
    }
    
    //여기까지 왔다는 것은 target으로 바꿀 수 없다는 뜻.
    return 0; 
}