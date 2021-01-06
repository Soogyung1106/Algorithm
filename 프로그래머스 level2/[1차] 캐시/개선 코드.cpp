#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    if(cacheSize == 0)  return cities.size()*5;
    
    int answer = 0; vector<string> lru;
    for(auto elem : cities){
        
        for(int j=0;j<elem.size();j++){ //소문자로 통일
            if(isupper(elem[j])) elem[j] = tolower(elem[j]);
        }
        
        if(lru.empty()){ //비어있을 때
            lru.push_back(elem);
            answer += 5; //miss
            continue;
        }  
        
        int idx = find(lru.begin(), lru.end(), elem)-lru.begin();
        if(idx + lru.begin() == lru.end()){ //리스트에 없으면 
            if(lru.size() == cacheSize) lru.erase(lru.begin()); //캐시 크기 초과
            lru.push_back(elem);
            answer += 5; //miss
        }else{
            lru.push_back(lru[idx]);
            lru.erase(lru.begin()+idx);
            answer += 1; //hit
        }   
        
    }
    
    return answer;
}