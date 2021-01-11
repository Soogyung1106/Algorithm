#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<pair<int, int>> v;

    for(int i=0;i<priorities.size();i++)
        v.push_back(make_pair(i, priorities[i])); //first: 인덱스, second: 우선순위 값.
    
    int count =0;
    while(1){

        int max = *max_element(priorities.begin(), priorities.end()); //최댓값
        
        if(v[0].second < max){ //맨 뒤로 
            pair<int, int> front = v[0];
            v.erase(v.begin());
            v.push_back(front);
        }else{ //출력(pop)
        
            count++; //몇 번째로 출력되는지 기록
            if(v[0].first == location){
                answer = count;
                break;
            }
            v.erase(v.begin());
            
        }
        
    }
    
    
    return answer;
}