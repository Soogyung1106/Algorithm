#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); // max 힙에 데이터 삽입함.
    
    while(pq.size() >= 2 ){
        
        if(pq.top()< K){
            int first = pq.top(); pq.pop();
            int second = first + pq.top() * 2; pq.pop();
            pq.push(second); answer++; //섞기    
            
            if(pq.size() == 1 && pq.top() < K ) //예외처리
                return -1;         
        }else{  
            break; 
        }
            
    }
    
    return answer;
}