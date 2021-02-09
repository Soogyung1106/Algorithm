#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    //int answer = 0; 
    int h = 0; int count = 0; 

    sort(citations.begin(), citations.end()); //정렬
    int max = citations[citations.size()-1];    
    //탐색
    while(h <= max){
        
        for(int i=0;i<citations.size();i++){
            if(citations[i] >= h){
                count = citations.size() - i;
                
                if(count >= h && i <= h){
                    h++; break;
                }else{
                    return --h;
                }
            
            }else if(i==citations.size()-1){
                return --h;    
            }
            
        }//end for       
        
    }


}