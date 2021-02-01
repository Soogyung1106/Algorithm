#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    for(int i=0;i<n;i++){
        int res = arr1[i] | arr2[i]; //비트 연산
        
        string str = ""; int j=0;
        while(j<n){
            str += res % 2 ? '#' : ' ';
            res /= 2;
            j++;
        }
        
        reverse(str.begin(), str.end());
        answer.push_back(str);
    }
    
    return answer;
}