#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    
    sort(B.begin(), B.end()); //오름차순 정렬
    
    //이분탐색
    int answer = 0;
    for(int i=0;i<A.size();i++){
        if(upper_bound(B.begin(), B.end(), A[i]) != B.end()){
            int idx = upper_bound(B.begin(), B.end(), A[i])-B.begin();
            B.erase(B.begin()+idx);
            answer++;
        }
    }
    
    return answer;
}