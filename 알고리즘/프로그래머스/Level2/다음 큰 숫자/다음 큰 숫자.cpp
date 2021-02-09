#include <string>
#include <vector>

using namespace std;

int count(int x){
   //2진수로 변환 
    int count = 0;
    while(1){
        if(x % 2 == 1) count++;
        x /= 2;
        if(x == 0) return count; //1의 개수 반환
    } 
}

int solution(int n) {
    
    int x = n+1; int num = count(n); 
    while(1){
        if(count(x) == num) break;
        x++;
    }
    
    return x;
}