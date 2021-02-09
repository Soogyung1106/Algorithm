#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s){
    
    int end = s.size()/2 + s.size()%2; 
    for(int i=0;i<end;i++){
        if(s[i] != s[s.size()-1-i]) return false;
    }
    return true;
}

int solution(string s)
{
    for(int i=s.size();i>=1;i--){ //길이
        for(int j=0;j+i<=s.size();j++){ //시작 위치 
            //팰린드롬 확인
            if(isPalindrome(s.substr(j, i))) return i;
        }
    }
    
}