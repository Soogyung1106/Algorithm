#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    
    vector<int>v(1, -1);
    if(arr.size() == 1) return v;
    
    arr.erase(min_element(arr.begin(), arr.end())); return arr;
}