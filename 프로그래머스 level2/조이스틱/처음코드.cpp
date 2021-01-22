#include <string>
#include <vector>
#include <iostream>

using namespace std;

int moving = 0; //움직인 횟수 누적
int cursor = 0; //초기 커서의 위치 : 인덱스 0  

//커서 위 아래 움직였을 때 최소한의 움직임 계산해 커서 위치 갱신
void upDown(string name, int i){
    //cursor~i 와 i~cursor
    int size = name.size();
    int a = abs(cursor-i);
    int b = 0;
    
    if(cursor< i) b = cursor + size-i;
    else b = i + size - cursor;
    
    moving += (a < b) || (a==b)? a: b;
    cursor = i;
}

//좌우 이동해 최소한의 움직임 계산해 단어 변환
void rightLeft(char c){
    int a = c - 'A';
    int b = 'Z' - c + 1;
    moving += (a > b) ? b : a;
}

int solution(string name) {
    
    
    for(int i=0;i<name.size();i++){
        if(name[i] == 'A') continue; //'A' 아닌 경우만 고려
        
        //커서의 위치가 현 인덱스와 다른 위치에 있을 경우
        if(cursor != i) upDown(name, i); //커서 이동
        rightLeft(name[i]);//단어 변환
    }
    
    return moving;
}