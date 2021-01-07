#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2, 0);
    
    int a = n; int b = m; int r = 0; 
    while(1){
        r = a % b;
        
        if(r == 0) {
            answer[0] = b; 
            break;
        }else{
            a = b; 
            b = r;
        }
    }
    
    answer[1] = answer[0] * (n/answer[0]) * (m/answer[0]);
    return answer;
}