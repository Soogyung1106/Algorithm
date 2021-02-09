#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    
    int pos=find(seoul.begin(),seoul.end(),"Kim")- seoul.begin();
    return "김서방은 "+to_string(pos)+"에 있다";
    
}