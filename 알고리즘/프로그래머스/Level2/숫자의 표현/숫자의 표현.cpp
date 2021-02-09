#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int answer = 0; //n
    for(int i=1;i<=n;i++){
        
        int sum = 0;
        for(int j=i; j<=n;j++){ //i로 시작하는 연속된 숫자 조합으로 만들 수 있는가?
            sum += j;
            if(sum == n){ //찾았다!
                answer++;
                break;
            }else if(sum > n) break; //i로 시작하는 숫자로는 만들 수 없음.
        }  
    }
    
    return answer;
}