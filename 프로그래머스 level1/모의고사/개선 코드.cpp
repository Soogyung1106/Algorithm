#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {

    int one[5] = {1, 2, 3, 4, 5}; 
    int two[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int three[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> cnt(4);
    for(int i=0;i<answers.size();i++){
        if(answers[i] == one[i%5]) cnt[1]++;
        if(answers[i] == two[i%8]) cnt[2]++;
        if(answers[i] == three[i%10]) cnt[3]++;
    }
    
    
    vector<int> answer;
    int Max = *max_element(cnt.begin(), cnt.end());
    for(int i=1;i<4;i++){
        if(Max == cnt[i]) answer.push_back(i);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}