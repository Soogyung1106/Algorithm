#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow; 
    int count = 0;
    
    //약수 구하기
    int j=0; //i로 나누었을 때의 값
    int row = 0; int column = 0; //가로, 세로
    for(int i=1; i<=yellow;i++){
        if(yellow % i == 0){
            j = yellow / i; 
            if(i>j){ 
                row = i + 2;
                column = j + 2;
            }else{
                row = j + 2;
                column = i + 2;
            }
            
            //진짜 가로, 세로 
            if(row * column == total){
                answer.push_back(row);
                answer.push_back(column);
                break;
            }
            
        }//end if
    }
    
    
    
    return answer;
}