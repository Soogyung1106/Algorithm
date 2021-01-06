#include <string>
#include <vector>

using namespace std;

int solution(int n) {    
    
    int answer = 0; int div=1;
    while(1){
        if(div > n) return answer;
        if(n%div == 0) answer += div;
        div++;
    }
    
}