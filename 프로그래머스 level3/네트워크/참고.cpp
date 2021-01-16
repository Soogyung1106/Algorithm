#include <string>
#include <vector>

using namespace std;
vector<bool> visited;
vector<vector<int>> node;
int N;

void dfs(int cur){
    visited[cur] = true; //방문했으면 1로 바꾸고 
    for(int i=0; i<N; i++){ //0행(노드0)에 연결되어 있는 것 모두 탐색.
        if(!visited[i] && node[cur][i] == 1) //가로로 탐색.
            dfs(i); //연결되어 있는 것에 또 다른 노드가 연결되어 있는지 깊이우선탐색.
    }
}

int solution(int n, vector<vector<int>> computers) {
    N = n; 
    node = computers;
    int answer = 0;
    //그래프가 주어진다. 
    visited.resize(N+1);
    //전체 탐색을 생각한다.-> 총 경로가 몇개가 나오는지.
    for(int i=0; i<N; i++){
        if(!visited[i]){ //아직 들리지 않은 곳일때만 DFS 호출
            answer++;
            dfs(i);
        }
    }
    return answer;
}