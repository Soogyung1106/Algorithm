#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    while(1){
        if(n == 0)  return answer;        
        answer.push_back(n % 10);
        n /= 10;
    }
    
}