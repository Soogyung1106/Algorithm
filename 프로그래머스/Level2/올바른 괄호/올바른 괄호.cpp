#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    
    stack<char> st; 
    for(int i=0;i<s.size();i++){

        if(!st.empty()){
            //'('와 ')'가 만나면 상쇄
            if(st.top() == '(' && s[i] == ')') st.pop();
            else st.push(s[i]);
        }else st.push(s[i]);
    }
 
    return st.empty() ? true: false;
}