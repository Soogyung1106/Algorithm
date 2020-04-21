#include <string>
#include <vector>


using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer; //output 
    vector<int> inverse; // 뒤에서부터 원소를 저장할 벡터 
    vector<int> temp; // 뒤집힌 배열을 원상복기하기 위한 임시 벡터
    /*
    input 배열을 뒤에서부터 집어넣기
    */
    int size = heights.size(); //input한 배열의 원소 개수
    
    for(int i = size-1; i >= 0; i--){ //뒤에서부터 차례대로 앞에서부터 집어넣기 
        inverse.push_back(heights[i]); 
    }
    

    for(int i=0; i< size; i++){
        int higher = inverse[i]; // 첫 번째로 발견한 더 높은 탑(수신 탑)
        
        if(i==size-1){ //맨 뒤의 원소일 경우
            //삽입
            temp.push_back(0);
            break;
        }else{
            for(int j = i+1; j<size ; j++){
                if(inverse[j] > higher){
                    //higher = inverse[j];
                    int index = size - j;
                    //삽입
                    temp.push_back(index);
                    break;
                }else if(j == size-1){
                    temp.push_back(0);
                }
            }//end for
        }//end else
        
    }//end for
    
    //뒤집기    
    for(int i = size-1; i != -1; i--){
        answer.push_back(temp[i]);
    }

    return answer;
        
}