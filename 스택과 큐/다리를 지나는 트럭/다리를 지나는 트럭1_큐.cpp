/*
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0; //한 트럭이 다리를 통과하는 소요 시간
    queue<int> onBridge; //큐 생성
    int size = truck_weights.size(); //트럭의 개수
    int lastTruck = 0; //다리를 건너는 마지막 트럭 위치 표시
    int arr[2]={0, 0};
    
 
    int i = 0;
    int count = 0; //다리를 건넌 트럭수
    int first = 0;
    
    while(1){ //한 트럭이 다리를 완전히 건넜을 때를 주기로 반복문 돌음
         
        first++; 
        
        //종료문
        if(count == size) 
            break;
        
        //트럭 1대만 존재할 경우
        if(size == 1){ 
                answer = bridge_length + 1;
                break;
            
        }
        //트럭 2대 이상인 경우........아래
        
        time = 0; //초기화
        time++; //1초 경과, 1만큼의 거리를 건넘      *****************************
        
        if(first == 1){ //첫 번째로 도는 while문일 경우
            
            onBridge.push(truck_weights[i]); //다리를 건너는 트럭
            lastTruck = bridge_length-1; //다리를 건너는 마지막 트럭 위치 표시   
            
        }else if(i != count-1 && truck_weights[i]+truck_weights[i+1] <= weight){
                i++;
                onBridge.push(truck_weights[i]); //다리를 건너는 트럭
                lastTruck = bridge_length-2;
        }
        
 
        
            
        //다리 길이가 1인 경우
        else if(bridge_length == time){ 
                time++; //2초 경과
                onBridge.pop(); //다리를 지난 트럭
                count++;
                answer += time; // 총 소요시간에 더하기
                i++; //기다리는 트럭, 다음 인덱스 
            
        }else{ //다리 길이가 2이상인 경우 
                  
            //지탱할 수 있는 무게 판단 
            if(i != count-1 && truck_weights[i]+truck_weights[i+1] <= weight){
                i++;
                onBridge.push(truck_weights[i]); //다리를 건너는 트럭
                lastTruck = bridge_length-2;
                 
                if(bridge_length == time){ //다리길이가 2인 경우
                    time++; //3초 경과     ********************************
                    onBridge.pop(); //다리를 지난 트럭
                    lastTruck = bridge_length-1;
                    count++;
                    answer += time; // 총 소요시간에 더하기         
                } ///////////////////////////////////////////////////////다리길이가 3이상인 경우도 생각해봐야 함        
            }else{ //그 다음 트럭까지 다리가 견디지 못할 경우
                time++; //3초 경과     ********************************
                onBridge.pop(); //다리를 지난 트럭
                lastTruck = bridge_length-1;
                count++;
                answer += time; // 총 소요시간에 더하기
                i++;
            }       
        }//end else
        
     
    
        
    }//end while
 
    return answer;

}
*/