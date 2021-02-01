#include <string>
#include <vector>

using namespace std;

long long dp[60001];
int solution(int n) {
    
    dp[1] = 1; dp[2] = 2; 
    
    if(n<=2) return dp[n]; //예외처리
    for(int i=3;i<=n;i++)  
        dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    
    return dp[n];
}