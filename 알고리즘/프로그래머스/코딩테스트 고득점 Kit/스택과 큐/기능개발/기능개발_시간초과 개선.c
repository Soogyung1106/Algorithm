#include <string>
#include <vector>
#include <algorithm> //reverse함수 사용
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    //1단계: 개발 소요일수 계산 -> 배열 
    vector<int> spendDay;
    int day = 0; 
    for(int i=0;i<progresses.size();i++){
        day = (100 - progresses[i])/speeds[i];
        
        if((100 - progresses[i])%speeds[i] != 0)
            day += 1;
        
        spendDay.push_back(day);
    }
    
    //2단계: 배열 reverse 
    reverse(begin(spendDay), end(spendDay));
    
    //3단계: reverse된 배열을 "큐"구조처럼 뒤에서부터 pop하기 
    int back = 0; 
    int count = 0; 
   
    while(1){
        
        //종료 조건
        if (spendDay.size() == 0)
            break;
        else if(spendDay.size() == 1){ //배포할게 1개만 남은 경우 
             spendDay.pop_back(); //배포하기
             answer.push_back(1);
             break;
        }
            
        back = spendDay.back();
        count = 1; //매번 초기화
        for(int i=spendDay.size()-2 ;i > -1;i--){ //뒤에서 2번째부터 생각
            if(back >= spendDay[i]){ //같이 배포해야 할 대상 찾기
                count++; //함께 배포가능한 수 ++
            }else //무조건 연속해서만 배포해야 함
                break;
            
        }//end for
        
        //count 수만큼 배포(pop)
        for(int i=0;i<count;i++){
            spendDay.pop_back(); //배포하기     
        }  
        answer.push_back(count); //배포 개수 저장
        

    }//end while
    
    return answer;
}