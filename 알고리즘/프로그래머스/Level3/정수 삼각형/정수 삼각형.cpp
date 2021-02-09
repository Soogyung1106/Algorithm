#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    //Bottom-up 방식
    for(int i=1;i<triangle.size();i++){
        //맨 앞 
        triangle[i][0] += triangle[i-1][0];
        
        //중간
        if(i>=2){ //2행부터 중간 값들이 생김.
            for(int j=1;j<=i-1;j++)
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        
        //맨 뒤
        triangle[i][i] += triangle[i-1][i-1];
    }
    
    return *max_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
}
