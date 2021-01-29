#include <vector>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {

    priority_queue<int> pq(works.begin(), works.end());    
    
    while(1){
        if(n==0) break; //시간 종료
        
        int top = pq.top()-1; 
        pq.pop();
        pq.push(top);
        n--;
    }
    
    long long answer = 0;
    while(!pq.empty()){
        if(pq.top()<=0) return answer; //예외처리
        
        answer += pow(pq.top(), 2);
        pq.pop();
    }
    
    return answer;
}