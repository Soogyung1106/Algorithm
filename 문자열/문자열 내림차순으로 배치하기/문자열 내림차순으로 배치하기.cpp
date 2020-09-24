#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    sort(s.begin(), s.end(), greater<int>()); // 내림차순 정렬 
    //cout<<s;
    answer = s;
    
    return answer;
}