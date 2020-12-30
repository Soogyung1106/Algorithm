#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    int max = arr[arr.size()-1];
    
    int j = 1;
    while(1){
        
        bool flag = true;
        for(int i=0;i<=arr.size()-2;i++){
            if(max*j % arr[i] != 0){
                flag = false; 
                j++; 
                break;
            }
        }
        
        if(flag == true) return max*j; //종료조건
    }
    
}