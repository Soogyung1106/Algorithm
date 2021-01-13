#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    
    vector<int> answer;
    for(auto elem : commands){
        vector<int> v(array.begin()+elem[0]-1, array.begin()+elem[1]);
        sort(v.begin(), v.end());
        answer.push_back(v[elem[2]-1]);
    }
    
    return answer;
}