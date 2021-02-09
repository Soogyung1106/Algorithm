#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    
    vector<int> answer;
    if(n > s){ //예외처리
        answer.push_back(-1);
        return answer;
    }
    
    // s % n = a(몫)...b(나머지)
    int a = s/n;
    int b = s%n;
    int num = (s % n == 0) ? 0 : 1;
    
    //분배
    for(int i=1;i<=n;i++){
        if(i<=b) answer.push_back(a+1);
        else answer.push_back(a);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}