#include <iostream>
using namespace std;

int solution(int n)                                                                                                 
{
    int ans = 0;
    
    while(1){
        if(n == 0) return ans;
        
        if(n % 2 == 0) n /= 2;
        else{
            n -= 1; ans++;
        }
    }
    
}