#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer="";
    for(int i=0;i<seoul.size();i++){
        if(seoul[i] == "Kim"){
            string pos = to_string(i);
            answer = "김서방은 "+pos+"에 있다";
            return answer;    
        } 
    }
    
}