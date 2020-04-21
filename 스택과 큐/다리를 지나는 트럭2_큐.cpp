/* 생각

<다리에 트럭이 올라올 조건> //push 
다리가 무게를 견딜 수 있는 경우 -> o

<다리에서 트럭이 내려올 조건>//pop
(1) 다리에 올라온 트럭 수 = 다리 길이 -> o (트럭 1개 내리기) 
(2) 다리에 올라온 트럭 수 != 다리 길이

트럭이 다 올라왔을 때 < 다리 길이 
트럭이 다 올라왔을 때 >= 다리 길이

*/

#include <iostream>
#include<algorithm>
#include <vector>
#include<queue> 
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int count = 0; // 다리에 올라온 트럭 수 
    int Time = 0; //??? 흐르고 있는 시간
    int Truck_weight = 0; //다리에 올라와 있는 현재 무게
    queue<pair<int, int>> truck_move; // 큐페어 사용 (트럭의 무게, 시간) -> 다리 위에 올라온 트럭
                                        // 시간(second): 모든 트럭들이 다리를 건너는데 소요되는 시간 누적해서 넣기
    while (true)
    {
        //push 조건: 다리가 견딜 수 있는 하중 >= 현재 다리에 올라와 있는 무게
        if (weight >= Truck_weight + truck_weights.at(count)) 
        {
            truck_move.push(make_pair(truck_weights.at(count), bridge_length + 1 + Time)); //다리에 추가     101s(1번째), 102s(2번째), 103s(3번째)
            Truck_weight += truck_weights.at(count);  //10kg(1번째), 20kg(2번째)
            count++;//다리에 올라와있는 트럭 +1대 1대(1번째), 2대(2번째), 3대(3번째) 
        }
        
        //pop 조건 
        //(1) 다리에 올라온 트럭 수 > 다리 길이
        if (count >= truck_weights.size())
        {
            answer = truck_move.back().second;   //
            break;
        }
        //(2) 다리에 올라온 트럭 수(10) != 다리 길이(100) -> count < truck_weights.size() 
        else 
        {
            Time++; // 1s, 2s, 3s 
            if (truck_move.front().second == Time+1)  
            {
                Truck_weight -= truck_move.front().first;
                truck_move.pop();
            }
        }

    }

    return answer;
}