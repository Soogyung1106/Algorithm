#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0;i<n;i++){
        int x = arr1[i]|arr2[i]; //비트 연산
        
        string s = ""; //2진화
        int count = 0;
        while(count < n){
            if(x%2==1) s += '#';
            else s += ' ';
            x /= 2;
            count++;
            
            //1을 2로 나누면 몫은 0 나머지는 1
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }

    return answer;
}