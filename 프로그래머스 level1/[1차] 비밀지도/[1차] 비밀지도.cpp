#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<string> answer;
    vector<int> map(n, 0); 
    for(int i=0;i<n;i++){
        //10진수 -> 2진수 
        int j=n-1;
        while(j>= 0){
            if(arr1[i] % 2 == 0 && arr2[i] % 2 == 0) map[j] = 0;
            else map[j] = 1;
            
            arr1[i] /= 2; arr2[i] /= 2;
            j--;
        }
         
        //해독
        string tmp=""; j=0;
        while(j <= n-1){
            if(map[j] == 1) tmp += '#';
            else tmp += ' ';
            j++;
        }
        answer.push_back(tmp);
    
    }
    
    return answer;
}