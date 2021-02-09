#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long k) {
    
    //배열 초기화 
    vector<int> v(n, 0);    
    for(int i=0;i<n;i++) //0번째에는 1이 저장., n-1번째에는 n이 저장
        v[i] = i+1;
    
    //정렬
    sort(v.begin(), v.end());
    
    //순열
    int cnt = 0;
    do{
        cnt++;
        if(cnt ==k) return v;
    }while(next_permutation(v.begin(), v.end()));
    
}