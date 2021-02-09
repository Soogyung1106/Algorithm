#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size, 0);
    stack<int> s; //스텍
    
    for(int i=0; i<size;i++){
        //스텍이 비어있지 않고, 주식 가격이 떨어졌다면
        while(!s.empty() && prices[s.top()] > prices[i]){
            // 가격이 떨어진 인덱스는 answer에 넣어버리고 스텍에서 pop해주기
            answer[s.top()] = i-s.top(); 
            s.pop(); 
        }
        s.push(i); //인덱스를 푸시
    }
    
    //이제 스택에 남아있는 인덱스 정리해주기 
    //prices 벡터가 끝날때까지 주식 가격이 떨어진지 않은 값들임.
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    
    return answer;
    
}