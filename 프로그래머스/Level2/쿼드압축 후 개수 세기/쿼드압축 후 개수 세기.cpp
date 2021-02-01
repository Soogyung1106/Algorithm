#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer{0, 0};
vector<vector<int>> v;

void recursion(int len, int startX, int startY){
    //왼쪽 상단 시작 위치 인덱스(startX, startY)에서 시작해서 len 길이만큼 압축하는 함수
    //만약 압축할 수 없다면 영역 4개로 분할해서 재귀호출
    
    //1. 기저조건
    int cmp = v[startX][startY]; 
    if(len == 1){ 
        if(cmp == 1) answer[1]++;
        else answer[0]++;
        return; //종료
    }
    
    
    //2. 동작
    bool flag = true;
    for(int i = startX; i<=startX+len-1 ;i++){
        for(int j = startY; j<=startY+len-1 ;j++){
            if(cmp != v[i][j]){
                flag = false; 
                break;
            } 
        }
        if(flag == false) break;
    }
    
    //3. 재귀호출
    if(flag == false){
        recursion(len/2, startX, startY); //왼쪽 상단 
        recursion(len/2, startX + len/2, startY); //오른쪽 상단
        recursion(len/2, startX, startY + len/2); //왼쪽 하단
        recursion(len/2, startX + len/2, startY + len/2); //오른쪽 하단
    }
    else{ //압축
        if(cmp == 1) answer[1]++;
        else answer[0]++;
        return; //종료
    }
    
}


vector<int> solution(vector<vector<int>> arr) {

    v = arr;
    recursion(arr.size(), 0, 0);
    return answer;
}