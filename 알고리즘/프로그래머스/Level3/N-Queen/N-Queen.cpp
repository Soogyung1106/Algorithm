#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int answer = 0;
vector<int> qRow; //퀸의 각 행에서의 위치(열)을 저장

bool checkLocation(int curRow){ 
    //row 행에서의 퀸 위치(열)가 적당한지 체크함. 
    
    for(int i=0;i<curRow;i++){
        //같은 열에 있는지 판단.
        if(qRow[curRow] == qRow[i]) return false;
        //대각선에 있는지 판단.
        if(abs(qRow[curRow]-qRow[i]) == abs(curRow-i)) return false;
    }
    
    return true;
}

void setQueen(int row){
    //row 행에서 퀸의 위치를 정하는 함수. 
    
    //기저조건: 행이 size를 넘어갔을 경우 조건에 만족. answer++ 
    if(row == qRow.size()){
        answer++;
        return;
    }
    
    for(int col=0;col<qRow.size();col++){
        //row 행에서 퀸의 위치가 col(열)인 경우 
        qRow[row] = col;
        if(checkLocation(row))
            setQueen(row+1); //그 다음 행의 퀸을 정함. 
    } 
    
}

int solution(int n) {
    
    qRow.resize(n);
    setQueen(0); //퀸의 위치 0번째 행부터 정함.  
    return answer;

}