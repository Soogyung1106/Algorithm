#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
//가중치에 따른 오름차순 정렬을 위한 비교
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
 
//부모노드찾기
int getParent(vector<int>& parent, int x) {
    //부모노드가 자신이라면 자신을 리턴
    if (parent[x] == x)        return x;
    //부모노드가 자신이 아니라면 최상위 부모노드 찾기
    return parent[x] = getParent(parent, parent[x]);
}
 
//부모노드 병합하기
void unionParent(vector<int>& parent, int a, int b) {
    //두개의 부모를 가져와서
    a = getParent(parent, a);
    b = getParent(parent, b);
    //작은 노드쪽의 부모로 병합시키기
    a < b ? parent[b] = a : parent[a] = b;
}
 
//부모노드가 같은지 비교
bool find(vector<int>& parent, int a, int b) {
    //부모노드를 가져와서
    a = getParent(parent, a);
    b = getParent(parent, b);
    //비교내용 리턴, 사이클 방지용
    return a == b;
}
 
int solution(int n, vector<vector<int>> costs) {
    int answer = 0, max = 0;
    //가중치 기준으로 정렬
    sort(costs.begin(), costs.end(), cmp);
    //costs를 순회해서 제일 높은 노드찾기
    for (auto a : costs)    if (max < a[1])        max = a[1];
    //부모노드용 리스트 생성
    vector<int> parent;
    //부모노드용 리스트 초기화
    for (int i = 0; i <= max; i++)        parent.push_back(i);
    //코스트를 처음부터 순회
    for (auto a : costs) {
        //두개의 부모노드가 같지않다면->사이클이 생성 안된다면
        if (!find(parent, a[0], a[1])) {
            //결과에 가중치 추가
            answer += a[2];
            //부모노드 병합하기
            unionParent(parent, a[0], a[1]);
        }
    }
    return answer;
}