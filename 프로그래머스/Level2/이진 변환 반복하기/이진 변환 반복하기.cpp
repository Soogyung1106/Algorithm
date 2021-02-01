#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer{0, 0};
    
    while(!(s.size() == 1 && s[0] == '1')){
        //0제거
        for(int i=0;i<s.size();i++){
            if(s[i] == '0'){
                answer[1]++; 
                s.erase(i, 1);
                i--;
            }
        }
        
        //2진 변환
        int len = s.size();
        s = "";
        while(len != 0){
            s += to_string(len%2);
            len /= 2; 
        }
        reverse(s.begin(), s.end());
        answer[0]++; 
    }
    
    return answer;
}