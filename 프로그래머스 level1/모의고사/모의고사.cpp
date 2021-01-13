#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {

    int one[6] = {0, 1, 2, 3, 4, 5}; 
    int two[9] = {0, 2, 1, 2, 3, 2, 4, 2, 5};
    int three[11] = {0, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> cnt = {0, 0, 0, 0};
    for(int i=0, j=1, k=1, r=1;i<answers.size();i++, j++, k++, r++){
        
        if(5<j) j -= 5;
        if(8<k) k -= 8;
        if(10<r) r -= 10;
        
        if(answers[i] == one[j]) cnt[1]++;
        if(answers[i] == two[k]) cnt[2]++;
        if(answers[i] == three[r]) cnt[3]++;
    }
    
    
    vector<int> answer;
    int Max = *max_element(cnt.begin(), cnt.end());
    for(int i=1;i<4;i++){
        if(Max == cnt[i]) answer.push_back(i);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}