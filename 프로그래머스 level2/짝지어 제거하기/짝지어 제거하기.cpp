#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s)
{
    vector<int> v;
    for(int i =0;i<s.size();i++){
        if(!v.empty()){
            if(v.back() == s[i]) v.pop_back();
            else v.push_back(s[i]);
        }else v.push_back(s[i]);
    }

    return v.empty() ? 1 : 0;
}