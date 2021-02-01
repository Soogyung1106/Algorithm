#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void moveDisk(int n, int from, int tmp, int to){
    //n개의 원반을 from에서 tmp를 거쳐 to로 옮기는 함수.
    //중간 중간에 경로 저장. 
    
    //기저 조건: 기둥에 마지막 한 개가 남았을 때 3번으로 옮기고 경로 저장
    vector<int> path = {from, to};
    if(n == 1) answer.push_back(path);
    else{
        moveDisk(n-1, from, to, tmp); //from에 있는 것을 to를 거쳐 tmp로 이동
        answer.push_back(path);
        moveDisk(n-1, tmp, from, to); //tmp에 있는 것을 from을 거쳐 to로 이동
    }
    
}

vector<vector<int>> solution(int n) {
    
    moveDisk(n, 1, 2, 3);
    return answer;
}