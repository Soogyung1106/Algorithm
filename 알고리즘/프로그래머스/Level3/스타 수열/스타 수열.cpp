#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    
    //빈도수 체크 
    vector<int> cnt(a.size(), 0);
    for(int i=0;i<a.size();i++) cnt[a[i]]++; 
    
    //스타수열 조건 체크
    int max = 0;
    for(int i = 0;i<cnt.size();i++){ //교집합 원소가 i일때
        
        //시간초과 해결
        if(cnt[i] == 0 || cnt[i] == 1) continue; 
        if(cnt[i]<max) continue;
        
        int count = 0;
        for(int j=0;j<a.size()-1;j++){
            //스타수열 조건 체크
            if(a[j] == a[j+1]) continue;
            if(a[j] != i && a[j+1] != i) continue;
            
            count++;
            j++;            
        }
        
        if(max<count) max = count;
    }
    
    return max*2;
}