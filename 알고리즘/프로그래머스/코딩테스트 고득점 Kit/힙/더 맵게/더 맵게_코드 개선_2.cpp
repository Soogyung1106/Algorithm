#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
   
    
    if(scoville.size() == 0 || (scoville.size() ==1 &&  scoville[0] < K)){ //불가능 case 
        answer = -1;
        return answer;
    }else if (scoville.size() ==1 &&  scoville[0] >= K){
        return answer;
    }
    
    sort(scoville.begin(), scoville.end()); //정렬
     
    int mix = 0;
    while(1){
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

    }//end while
    
    return answer;
    
}