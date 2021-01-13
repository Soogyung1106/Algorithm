#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(int i=0;i<moves.size();i++){
        int col = moves[i]-1;
        
        for(int j=0;j<board.size();j++){
            if(board[j][col] != 0){
                
                if(!s.empty()){
                   if(s.top() == board[j][col]){
                       answer += 2; //터뜨리기   
                       s.pop();
                   }else s.push(board[j][col]);
                }else  s.push(board[j][col]);
            
                board[j][col] = 0; 
                break;
            }
        }
    }
    
    return answer;
}