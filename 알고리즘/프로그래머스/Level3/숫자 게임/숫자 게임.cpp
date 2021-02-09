#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int solution(vector<int> A, vector<int> B) {
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>()); 
    
    queue<int> q;
    for(auto b : B) q.push(b);
        
    int answer = 0;
    for(int i=0;i<A.size();i++){
        if(A[i] < q.front()){
            answer++;
            q.pop();
        }
    }
    
    return answer;
}