#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i=1;i<prices.size();i++){
    
        int front = prices.front();
        if(front > prices[i] || i == prices.size()-1){ // 갱신
            answer.push_back(i); prices.erase(prices.begin());
            i = 0;
        
        }
        
    }
    
    answer.push_back(0);  prices.erase(prices.begin());
   
    return answer;
}