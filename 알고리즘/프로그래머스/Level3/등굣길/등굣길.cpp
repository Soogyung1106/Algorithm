#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {

    //초기화
    vector<vector<int>> path(m+1, vector<int>(n+1,0));
    for(auto p : puddles) path[p[0]][p[1]] = -1;
    
    //최단경로의 개수 구하기
    vector<vector<int>> memo(m+1, vector<int>(n+1,0));
    memo[0][1] = 1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(path[i][j] == -1) memo[i][j] = 0;
            //과정에서 나눠야지 결과에서 나눠주면 시간초과 뜸.
            else memo[i][j] = (memo[i-1][j] + memo[i][j-1])% 1000000007; 
        }
    }
    
    return memo[m][n];
}
