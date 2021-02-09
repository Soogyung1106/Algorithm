#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    //명령어 수행
    vector<int> v;
    for(int i=0; i< operations.size();i++){
        string str = operations[i];
        
        if( operations[i] == "D 1" && v.size()>0 ){ // 최대값 삭제 
            vector<int>::iterator iter = v.begin();
            v.erase(iter);
        }else if( operations[i] == "D -1" && v.size()>0) {// 최소값 삭제 
            v.pop_back();
        }else if(str[0] == 'I'){ //숫자 삽입.
            str = str.substr(2, str.size()-1); //문자열 자르기
            int digit = stoi(str); 
            v.push_back(digit);
            sort(v.begin(), v.end(), greater<int>()); //내림차순 정렬 
        }
    }
    
    //출력
    if(v.empty()){
        answer.push_back(0); answer.push_back(0);
    }else{
        answer.push_back(v.front()); answer.push_back(v.back());
    }
    
    return answer;
}