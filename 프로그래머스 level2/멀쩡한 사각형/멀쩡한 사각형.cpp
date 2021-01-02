#include <algorithm>
using namespace std;

long long solution(int w,int h) {
    
    /* 규칙
    (w/gcd + h/gcd - 1) * gcd
    = w + h - gcd 
    */
    
    int i = 1; int gcd = 0;
    while(1){ //gcd 구하기 
        
        if(i > min(w, h))   return (long long)w*h-(long long)(w+h-gcd); 
    
        if(w % i ==0 && h % i == 0) gcd = i;
        i++;

    }
    
    
}