#include <string>
#include <vector>

using namespace std;

int answer = 0; //target을 만들 수 있는 경우의 수 
    
void dfs(int idx, int result, vector<int> numbers, int target){
    //numbers의 idx위치 숫자를 더하거나 빼고 
    //idx가 numbers.size일 경우 result가 target인지 검사
    if(idx==numbers.size()){
        if(result == target) answer++;
        return;
    }else{
        //그 다음 인덱스에 result를 넘겨줌
        dfs(idx+1, result-numbers[idx], numbers, target); 
        dfs(idx+1, result+numbers[idx], numbers, target);
    }
 
}

int solution(vector<int> numbers, int target) {
    
    dfs(0, 0, numbers, target); //numbers 0번째부터 탐색 시작, 초기 값은 0
    return answer;
}