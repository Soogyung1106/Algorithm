#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    
    for(int i=0;i<s.size();i++){
        if(s[i] != ' '){
            int move = s[i]+n;
            if(isupper(s[i]) && move>'Z') move = (move-'Z')+('A'-1);
            if(islower(s[i]) && move>'z') move = (move-'z')+('a'-1);
            s[i] = move; 
        }
    }
    
    return s;
}