#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> tmp;  
    
    for(int i=0;i<arr1.size();i++){ //행
        for(int j =0;j<arr2[0].size();j++){ //열
            
            int sum = 0;
            for(int k = 0;k<arr1[0].size();k++) sum += arr1[i][k] * arr2[k][j];
            tmp.push_back(sum);
            
        }
        answer.push_back(tmp); //한 행이 완성될때마다 행렬에 넣어주기
        tmp.clear();
    }
    
    
    return answer;
}