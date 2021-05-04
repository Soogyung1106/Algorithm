#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <utility>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    deque<int> wait_trucks(truck_weights.begin(), truck_weights.end()); //대기트럭
    deque<pair<int, int>> onBridge; //다리에 올라와있는 트럭.(무게, 다리에 올린 시간)
    
    //다리 위에 트럭 한 대를 올려놓고 시작.
    int time = 1;
    int cur_weight = wait_trucks.front(); //현재 다리 위에 올려진 무게.
    onBridge.push_back({wait_trucks.front(), 1});
    wait_trucks.pop_front();
    
    while(1){
        //종료? 대기 트럭에도 다리에도 더 이상 트럭이 남아있지 않을 경우.
        if(wait_trucks.empty() && onBridge.empty()) return time;
        
        //1. 시간 1초 지남. 
        time++; 
        
        //2. 다리 위에 있는 모든 트럭의 위치 1증감.
        if(time - onBridge.front().second >= bridge_length){ 
            cur_weight -= onBridge.front().first; //다리에 올려진 무게에서도 빼기
            onBridge.pop_front(); //다리에서도 pop   
        }
         
        //3. 트럭을 다리에 올릴 수 있으면 올리기     
        if(wait_trucks.empty()) continue;
        int new_truck = wait_trucks.front();
        if(cur_weight + new_truck <= weight){
            onBridge.push_back({new_truck, time}); //다리에 올려주기 
            wait_trucks.pop_front(); //대기 트럭에서 빼주기
            cur_weight += new_truck; //현재 다리에 올려진 무게 업뎃.
        }   
    }

    return time;
}
