#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    
    for(int i = 0;i<s.size();i++){
       if(isalpha(s[i])) s[i] = tolower(s[i]); //모두 소문자로
    }

    if(isalpha(s[0])) s[0] = toupper(s[0]);
    
    for(int i = 0;i<s.size();i++){ 
        if(s[i] == ' ' && isalpha(s[i+1])){ //맨 앞 글자 처리
            s[i+1] = toupper(s[i+1]);             
        }
    }
    
    return s;
}