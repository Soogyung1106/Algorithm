#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

 vector<vector<int>> dial{{3, 1}, {0, 0}, {0,1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2,1}, {2,2}}; // 0~9의 행렬 위치
vector<int> r{3, 0}; //처음 위치(x, y) : *
vector<int> l{3, 2}; // 처음 위치: #

char closer(string hand, int number){
    
    int dist_l = abs(dial[number][0] - l[0]) + abs(dial[number][1] - l[1]);
    int dist_r = abs(dial[number][0] - r[0]) + abs(dial[number][1] - r[1]);
       
    if(dist_l > dist_r || (dist_l == dist_r && hand == "right")){
        r[0] = dial[number][0]; r[1] = dial[number][1];
        return 'R';
    }else if(dist_l < dist_r || (dist_l == dist_r && hand == "left")){
        l[0] = dial[number][0]; l[1] = dial[number][1];
        return 'L';
    }
    
}



string solution(vector<int> numbers, string hand) {
    
    string answer = "";
    for(int i=0;i<numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            answer+= 'L';
            l[0] = dial[numbers[i]][0]; l[1] = dial[numbers[i]][1];
        }if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            answer+= 'R';
            r[0] = dial[numbers[i]][0]; r[1] = dial[numbers[i]][1];
        }if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
            answer += closer(hand, numbers[i]);
        }
    }
    
    return answer;
}