#include <vector>
#include <iostream>
  
using namespace std;

int count =0;
vector<vector<int>> pic;

void countSizeOfArea(int i, int j, int value){
    //i행 j열부터 시작해서 상하좌우에 value 값과 같은 것이 있다면 count 값을 증가 
    // 해당 값은 0으로 초기화
    //그리고 이어서 탐색할 수 있도록 재귀호출
    //기저조건? 상하좌우에 value와 같은 값이 아무것도 없을 경우 return;
    pic[i][j] = 0;
    count++; //넓이 카운팅
    
    if(i!=0 && pic[i-1][j] == value)   
        countSizeOfArea(i-1, j, value);
    if(i!=pic.size()-1 && pic[i+1][j] == value)   
        countSizeOfArea(i+1, j, value);
    if(j!=0 && pic[i][j-1] == value)   
        countSizeOfArea(i, j-1, value);
    if(j!=pic[0].size()-1 && pic[i][j+1] == value)  
        countSizeOfArea(i, j+1, value);
    
}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int numberOfArea = 0;
    int maxSize = 0;
    pic = picture;
    
    for(int i =0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(pic[i][j] != 0){
                count = 0;
                countSizeOfArea(i, j, pic[i][j]); //영역의 넓이
                maxSize = (maxSize < count) ? count : maxSize;
                numberOfArea++; //영역개수
            }
        }
    }

    vector<int> answer{numberOfArea, maxSize};    
    return answer;
}