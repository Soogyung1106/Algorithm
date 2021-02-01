#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(int x) {

    int sum = 0; int k = x; //원래 값 저장
    while(1){
        if(x == 0) return k % sum == 0 ? true : false;
        sum = sum + x % 10;
        x /= 10;
    }
            
}