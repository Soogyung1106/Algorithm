#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    sort(arr.begin(), arr.end());
    
    vector<int> answer;
    for(int i=0;i<arr.size();i++){
        if(arr[i] % divisor == 0) answer.push_back(arr[i]);
    }
    
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}