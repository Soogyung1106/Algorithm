#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, int m) {
    
    int a = max(n, m); int b = min(n, m); 
    while(a % b != 0){
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    
    vector<int> answer(2);
    answer[0] = b;
    answer[1] = answer[0] * (n/answer[0]) * (m/answer[0]);

    return answer;
}