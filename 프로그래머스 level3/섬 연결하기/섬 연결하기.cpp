#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> parent;

bool compare(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

//x노드의 루트 노드를 구해주는 함수.
int getRoot(int x){
    if(parent[x] == x) return x;
    else return parent[x] = getRoot(parent[x]);
}

//Find: 두 노드의 루트 노드를 확인 = 같은 집합에 속했는지 확인 = 사이클 여부
bool Find(int a, int b){
    return getRoot(a) == getRoot(b);
}

//(사이클 x) → Union: 두 집합을 합치기.
void Union(int a, int b){
    //두개의 부모를 가져와서
    int x = getRoot(a);
    int y = getRoot(b);
    //작은 노드쪽의 부모로 병합시키기
    x < y ? parent[y] = x : parent[x] = y; 
}

int solution(int n, vector<vector<int>> costs) {
    
    //크루스칼 알고리즘 - 비용 순으로 정렬
    sort(costs.begin(), costs.end(), compare);
    
    //초기화
    parent.resize(n+1);
    for(int i=0;i<=n;i++) parent[i] = i;
    
    int edge = 0, answer = 0; //간선의 개수, 최소 비용 
    for(auto c : costs){
        if(edge == n-1) return answer; //MST 생성됨. 
        
        //사이클 생성 x -> Union-Find 알고리즘 사용 
        if(!Find(c[0], c[1])){  
            edge++; //간선 개수 갱신
            answer += c[2]; //최소비용 갱신
            Union(c[0], c[1]);
        }
    }
   
}