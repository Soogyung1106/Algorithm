#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> qLocation; //퀸의 각 행에서의 위치를 저장
int answer = 0;

bool checkLocation(int curRow){
    //이전 행의 퀸 위치와 비교 
    for(int i=0;i<curRow;i++){
        if(qLocation[i]==qLocation[curRow]) return false; //열
        if(abs(qLocation[i]-qLocation[curRow]) == abs(i-curRow)) return false; //대각선
    }
    return true;
}

//row에 해당하는 퀸을 정하는 함수.
void makeQueen(int row){
    
    //기저조건
    if(row == qLocation.size()){
        answer++; // 정답 증가
        return;
    }

    for(int i=0;i<qLocation.size();i++){
        qLocation[row]=i;
        if(checkLocation(row)) makeQueen(row+1);
    }
}

int solution(int n) {
    qLocation.resize(n);
    makeQueen(0); //0행부터 퀸을 만들기 시작함.
    return answer;
}