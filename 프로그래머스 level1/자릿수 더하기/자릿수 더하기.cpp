#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    string s = to_string(n); //int to string 
    int answer = 0;
    for(int i=0;i<s.size();i++)
        answer+=s[i]-48;
    
    return answer;
}