#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
   
    sort(scoville.begin(), scoville.end()); //정렬
     
    int mix = 0;
    while(scoville[0] < K){
        
        if(scoville.size() == 1 ) { //불가능 case 
            answer = -1; 
            break;
        }
        
        mix = scoville[0]+ scoville[1]*2; // mix
                 
        scoville.erase(scoville.begin(), scoville.begin()+2); // 요소 2개 삭제 
        scoville.push_back(mix); //섞은 것 삽입 
        answer++;    
        sort(scoville.begin(), scoville.end()); // 정렬 
 
    }//end while
    
    return answer;
    
}