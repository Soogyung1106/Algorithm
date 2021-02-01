#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    
    //재구성: i는 j를 이겼다. 
    vector<vector<bool>> match(n+1, vector<bool>(n+1, false));
    for(auto r : results) 
        match[r[0]][r[1]] = true;
    
    //'플로이드 와샬' 알고리즘 추론
    for(int k=1;k<=n;k++){ 
        for(int i=1;i<=n;i++){  
            for(int j=1;j<=n;j++){
                //i→k, k→j ----> i→j
                if(match[i][k] && match[k][j]) match[i][j] = true;
                //if (match[j][i] && match[i][k]) match[j][k] = true;
            }
        }
    }
    
    
    //승패를 확실히 가릴 수 있는 선수 카운팅 
    int answer = 0;
    for(int i=1;i<=n;i++){ //i번 선수 판단.
        int count =0;
        for(int j=1;j<=n;j++){
            //i→j 혹은 j→i  i와 j의 관계는 확실해짐.
            if(match[i][j] || match[j][i]) count++; 
        }
        
        //확실한 관계가 n-1개라면 순위를 가릴 수 있음. 
        if(count == n-1) answer++;
    }
    return answer;
}