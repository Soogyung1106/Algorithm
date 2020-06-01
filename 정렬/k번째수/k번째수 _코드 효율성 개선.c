#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp; 
    
    
    for(int j=0;j<commands.size();j++){
        
        /*
        //자르기  
        for(int i= commands[j][0]-1 ;i <commands[j][1]; i++){
            temp.push_back(array[i]);
        }
        */
        temp = array;
        
        //특정구간만 오름차순 정렬
        sort(temp.begin()+commands[j][0]-1, temp.begin()+commands[j][1]); //start를 포함하고 end를 포함하지 않는 구간을 정렬
        
        //k번째 수
        int value = temp[commands[j][0]-1 + commands[j][2]-1];
        answer.push_back(value);
        
        
    }
    
    return answer;

    
}