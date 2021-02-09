#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int arr[35]; 
    fill(arr, arr+35, 1); arr[0] = 0;
    
    //여벌 있으면 2 
    //1개만 있으면 1
    //없으면 0
    for(int i : reserve) arr[i] += 1;
    for(int i : lost) arr[i] -= 1;
        
    for(int i=1;i<=n;i++){
        if(arr[i] == 0){
            if(arr[i-1] == 2){
                arr[i-1] = arr[i] = 1;
            }else if(arr[i+1] == 2){
                arr[i+1] = arr[i] = 1;
            }
        }
    }
    
    int answer = 0;
    for(int i=1;i<=n;i++){
        if(arr[i]!=0) answer++;
    }
    return answer;
}