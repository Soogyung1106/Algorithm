/*참고
https://mungto.tistory.com/58
*/
#include <string>
#include <vector>
#include <iostream>
 
using namespace std;
 
int solution(int n, vector<vector<int>> results) {
    
    //승리한 경우 추가
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    for (auto r : results)  graph[r[0]][r[1]] = true; //4x3 true, 3x2 true 
    
    //플로이드 와샬 알고리즘 (추론)
    for (size_t i = 1; i <= n; i++) { 
        for (size_t j = 1; j <= n; j++) { //graph[i][j]
            for (size_t k = 1; k <= n; k++) {
                if (match[j][i] && match[i][k]) match[j][k] = true;
            }
        }
    }
    
    //순위를 메길 수 있는 선수 카운트
    int answer = 0;
    for (size_t i = 1; i <= n; i++) {
        int count = 0;
        for (size_t j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) count++; //승패 여부를 확실히 알 수 있는 것 카운팅.
        }
        if (count == n - 1) answer++; //5명 중에 4명에게 졌다면 꼴등.
    }
    return answer;
}