#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int size = s.size();
    int midIdx = (size + 1) / 2 - 1;
    
    string answer = "";
    answer += s[midIdx];
    if(size % 2 == 0) answer += s[midIdx+1]; //짝수
    return answer; 
}