#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());//오름차순으로 우선순위 큐 

    
    int first = 0; int second = 0;
    
    while(pq.top() < K){ //맨 앞요소 
        
        //불가능 case 
        if(pq.size() == 1 )  return answer = -1;
    
        first = pq.top(); pq.pop(); //첫 번째 삭제  
        second = pq.top();  pq.pop(); //두 번째 삭제
        pq.push(first + second*2); //믹스해서 삽입
        answer++;
        
    }//end while
    
    return answer;
    
}