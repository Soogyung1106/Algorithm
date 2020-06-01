#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp; 
    
    
    for(int j=0;j<commands.size();j++){
        
        //자르기     
        for(int i= commands[j][0]-1 ;i <commands[j][1]; i++){
            temp.push_back(array[i]);
        }
        
        //오름차순 정렬
        sort(temp.begin(), temp.end());
        
        //k번째 수
        int value = temp[commands[j][2]-1];
        answer.push_back(value);
        
        //temp  배열 초기화
        temp.clear();
    }
    
    return answer;

    
}