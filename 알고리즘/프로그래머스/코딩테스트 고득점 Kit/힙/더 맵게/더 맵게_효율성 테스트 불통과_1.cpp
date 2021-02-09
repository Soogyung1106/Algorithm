#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int mix = 0;
    
    sort(scoville.begin(), scoville.end()); //정렬
    
    if(scoville.size() == 0 || (scoville.size() ==1 &&  scoville[0] < K)){ //불가능 case 
        answer = -1;
        return answer;
    }
       
    while(1){
        
            if(scoville.size() >= 2 && scoville[0] < K){ //mix 해야 할 경우
                mix = scoville[0]+ scoville[1]*2; // mix
                 
                scoville.erase(scoville.begin(), scoville.begin()+2); // 요소 2개 삭제 
                scoville.push_back(mix); //섞은 것 삽입 
                answer++;    
                sort(scoville.begin(), scoville.end()); // 정렬 
                
                if(scoville[0] >= K){ //mix 종료 
                    break;
                }else if(scoville.size() == 1 &&  scoville[0] < K) { //불가능 case 
                    answer = -1; 
                    break;
                }
            }//end if 
        
    }//end while
    
    return answer;
    
}