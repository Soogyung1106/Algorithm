#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    
    int answer = 0;
    while(1){ 
        int cnt = 0, maxCnt = 0;
        for(int i=0;i<stones.size();i++){
            if(stones[i] == 0){
                cnt++;
            }else{
                //건널 수 없는 연속된 디딤돌 최대 개수 갱신.
                if(i!=0 && stones[i-1] == 0){
                    maxCnt = max(maxCnt, cnt);
                    cnt = 0;
                    if(maxCnt >= k)
                        return answer; //종료
                }
                stones[i] -= 1; //건너기.
            }     
        }
        
        maxCnt = max(maxCnt, cnt);
        
        //건널 수 없는 경우? 건너 뛰어야 하는 칸이 k 이상..
        if(maxCnt >= k) return answer; //종료
        else answer++; //건넌 사람 수 증가
    }
    
}