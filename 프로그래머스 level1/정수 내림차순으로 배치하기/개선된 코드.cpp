#include <string>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    
    string s = to_string(n);
    sort(s.begin(), s.end(), greater<int>()); 
    long long answer = stoll(s); //string to long long
    return answer;
}