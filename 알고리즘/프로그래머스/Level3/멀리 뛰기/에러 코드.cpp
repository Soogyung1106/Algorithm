#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long factorial(int x){
    if(x == 1) return 1;
    else return x*factorial(x-1);
}


long long solution(int n) {
    
    long long answer = 0;
    long long b = 0; 
    for(long long a = 0; a<=n;a++){ //a는 1칸 움직인 횟수
        if((n-a) % 2 == 0){ //가능한 조합이라면..
            b = (n-a)/2;
            
            if(a == 0 || b ==0) answer = (answer+1)%1234567;
            if(a != 0 && b!=0)
                answer = (answer+factorial(a+b)/factorial(a)*factorial(b))%1234567;
            
            answer %= 1234567;
        }  b
    }
    
    return answer;
}