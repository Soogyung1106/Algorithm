#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<vector<int>> board)
{
    if(board.size() == 1 || board[0].size() == 1){// 예외처리
        for(int i=0;i<board.size();i++){  
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]) return 1;
            }
        }
    }
    
    int Max = 0;
    for(int i=1;i<board.size();i++){ 
        for(int j=1;j<board[i].size();j++){ 
            if(board[i][j] && board[i-1][j] && board[i-1][j-1] && board[i][j-1])
                board[i][j] = min(min(board[i-1][j], board[i-1][j-1]), board[i][j-1]) + 1;
            if(Max < board[i][j]) Max = board[i][j]; //기억
        }
    }    
  
    return pow(Max, 2);
}