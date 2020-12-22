#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    vector<bool> v(n+1, true); //n+1 크기의 벡터를 true 값으로 채운다.
    
    int i=2; int answer = 0;
    while(i<=n){
        if(v[i] != false){
            for(int j=2;i*j<=n;j++) v[i*j] = false;
            answer++;
        }
        i++;
    }

    return answer;
    
}