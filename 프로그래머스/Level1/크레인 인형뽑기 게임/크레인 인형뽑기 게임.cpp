#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    //재구성
    vector<vector<int>> v(board.size());
    for(int i=0;i<board.size();i++){ 
        for(int j=board.size()-1;j>=0;j--){
            if(board[j][i] != 0) v[i].push_back(board[j][i]);
        }
    }
    
    // 바구니에 담기 (스텍)
    vector<int> s; 
    int answer = 0;
    for(int i=0;i<moves.size();i++){
        if(!v[moves[i]-1].empty()){
            s.push_back(v[moves[i]-1].back()); //넣기
            v[moves[i]-1].pop_back(); //빼기 
            //터뜨리기
            if(s[s.size()-2] == s[s.size()-1]){
                s.pop_back(); s.pop_back();
                answer += 2;
            }
        }
    }
    
    return answer;
}