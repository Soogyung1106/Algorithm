#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{   
    int x = min(a, b); int y = max(a, b);
    int answer = 1;
    while(1){
        x = (x % 2 ==0) ? x /= 2 : (x+1) / 2;
        y = (y % 2 ==0) ? y /= 2 : (y+1) / 2;
        answer++;
        
        if(y-x == 1 && y%2 ==0) return answer;
        if(x == y) return 1; 
    }
    
    
}