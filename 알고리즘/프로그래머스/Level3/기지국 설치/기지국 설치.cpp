#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    
    vector<int> len; //전파가 도달하지 않는 아파트의 길이
    for(int i=0;i<stations.size();i++){
        if(i==0)  len.push_back(stations[i]-1-w);
        else  len.push_back(stations[i]-stations[i-1]-1-2*w);
        
        if(i==stations.size()-1)  len.push_back(n-stations[i]-w);
    }

    int answer = 0;
    for(int i=0;i<len.size();i++){
        if(len[i]<=0) continue;
        answer += len[i]/(2*w+1);
        if(len[i]%(2*w+1) != 0) answer += 1;
    }
    
    return answer;
}