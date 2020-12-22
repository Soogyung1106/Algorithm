#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    //long형 to 벡터
    vector<int> v; 
    while(n > 0){
        v.push_back(n%10); n /= 10;  
    }
    sort(v.begin(), v.end()); //오름차순
    
    //벡터 to long형
    long long answer = 0;
    for(int i=0;i<v.size();i++) answer += v[i]*pow(10, i);     
    return answer;
    
}