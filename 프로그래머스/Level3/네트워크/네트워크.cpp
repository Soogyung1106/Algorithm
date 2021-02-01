#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> nodes;
int N;

//visited. 방문 여부 체크 
//한번에 연결되어 있는것을 모두 탐색함. 
void dfs(int startNode){
    visited[startNode] = true;
    
    for(int i=0;i<N;i++){ //startNode에 연결되어 있는 노드들 탐색
        if(nodes[startNode][i] == 1 && visited[i] == false)
            dfs(i); //연결된 노드에 또 다른 노드가 연결되어 있는지 깊이우선해서 탐색.
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    N = n;
    nodes = computers;
    visited.resize(N+1);
    
    int answer = 0;
    for(int i=0;i<N;i++){ 
        //0부터 N-1 노드까지 순회하면서 네트워크 개수 카운팅
        //이미 방문된 노드는 다른 네트워크에 묶여있다는 뜻.
        //방문 하지 않았을 경우만 dfs 탐색.
        if(visited[i] == false){
            answer++; //네트워크 개수 카운팅
            dfs(i); //i번 노드 탐색.
        }    
    }
    
    return answer;
}