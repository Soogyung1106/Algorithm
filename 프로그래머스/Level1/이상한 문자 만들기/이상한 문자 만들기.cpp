#include <string>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string s) {
    
    int idx=0;int pos=0;
    while(pos<s.size()){
        if(s[pos] == ' ') idx = -1;
        if(idx %2 == 0 && islower(s[pos]))  s[pos] = toupper(s[pos]);//소문자면 대문자로
        if(idx %2 == 1 && isupper(s[pos]))  s[pos] = tolower(s[pos]);//대문자면 소문자로
        
        pos++;
        idx++;
    }
    
    return s;
}