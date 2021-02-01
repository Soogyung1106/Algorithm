#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx; //compare 함수에서 사용하기 위해 선언

bool compare(string a, string b){
    return a[idx] == b[idx] ? a < b : a[idx] < b[idx];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    idx = n;
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}