#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    
    //1. 스텍 생성
    vector<char> st;
    
    //2. 앞자리가 가장 큰 수가 되게씀 스택에 데이터 저장
    for(const auto& elem : number){
        while(!st.empty() && st.back() < elem && k > 0){
            st.pop_back(); k -= 1;
        }
        
        st.push_back(elem);
    }
    
    //3. k가 남았다면, 스택 뒤에서 k개 빼줌 
    while(k > 0){
        st.pop_back();
        k -= 1;
    }
    
    string answer = "";
    for(const auto& elem : st) answer += elem;
    return answer;
}