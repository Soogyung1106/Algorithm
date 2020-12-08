#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
   sort(people.begin(), people.end()); //오름차순 정렬
    
    int answer = 0; int sum = 0;
    int right = people.size()-1; int left = 0; //인덱스(맨 앞, 맨 뒤)
	
	while (left <= right) {
	    
        if(left == right) sum = people[right];
        else sum = people[right] + people[left];
 
		if( sum <= limit){
            
            while(sum <= limit){
                left++;
                sum = sum + people[left];    
            }
                
            right--; answer++;
            
        }else{ answer++; right--; }
             
	}

	return answer; 
    
}