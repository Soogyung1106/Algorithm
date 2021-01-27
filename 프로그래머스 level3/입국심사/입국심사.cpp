#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    s  e
    27 29  mid = 28 
    27 27 mid = 27 
    27 26 > break
    */

long long solution(int n, vector<int> times) {
    
    //가장 오래 걸리는 심사대
    long long Max = *max_element(times.begin(), times.end());
    long long start = 1, end = Max*n; //이진 탐색 시작과 끝
    long long answer = 0;
       
    while(start<=end){
        
        //평균시간 동안 처리할 수 있는 사람들 수 
        long long mid = (start + end)/2;
        long long cntPeople = 0;
        for(int i=0;i<times.size();i++) cntPeople += mid/times[i];
        
        //이진탐색
        if(cntPeople<n) start = mid + 1;
        else{
            answer = mid;
            end = mid - 1; //최솟값을 찾아야 하므로 범위를 좁혀준다.    
        } 
    }
    
    return answer;
}