#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    //에라토스테네스의 체
    int i = 2; vector<int> v(n+1, 0); //인덱스 0~n까지
    while(i<=n/2){ // 2x2, 2x3, 2x4
        for(int j=2;i*j<=n;j++){
            if(v[i*j] != 1) v[i*j] = 1;
        }   
        i++;
    }
    
    //개수 세기
    int answer = 0;
    for(int i=2;i<=n;i++){
       if(v[i] == 0) answer++; 
    } 
    return answer; 
    
}