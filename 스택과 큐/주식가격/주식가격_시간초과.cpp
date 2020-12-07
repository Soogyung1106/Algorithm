#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    while(1){
        if(prices.size() == 1){
            answer.push_back(0); prices.erase(prices.begin());
            break;
        }
        
        int count =0;
        int front = prices.front();
        
        for(int i=0;i<prices.size();i++){
            count++;
            if(front > prices[i]){
                answer.push_back(count);
                prices.erase(prices.begin());
                break;
            }     
        }
    }    
    
    
    return answer;
}