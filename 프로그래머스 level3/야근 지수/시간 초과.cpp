#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
        
    //n은 남은시간
    while(1){
        if(n==0) break;
        make_heap(works.begin(), works.end());
        works[0]-=1;
        n--;
    }
    
    long long answer = 0;
    for(auto w : works){
        if(w<=0) continue;
        answer += pow(w, 2);
    }
    
    return answer;
}