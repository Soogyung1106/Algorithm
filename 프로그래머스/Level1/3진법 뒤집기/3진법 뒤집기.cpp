#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
    
    //3진법
    vector<int> v;
    while(1){
        if(n<3){
            v.push_back(n);
            break;
        }
        v.push_back(n%3);
        n /= 3;
    }
    
    //10진법 변환
    int answer = 0;
    for(int i=v.size()-1;i>-1;i--){
        answer += v[i] * pow(3, v.size()-i-1); 
    }
    return answer;
}