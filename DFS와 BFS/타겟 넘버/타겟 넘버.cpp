#include <string>
#include <vector>

using namespace std;

int answer = 0; //전역변수 

void dfs(vector<int> numbers, int target, int index = 0, int sum = 0){ 
    //함수 정의: numbers의 index가 맨 앞에서부터 돌면서 +와 -연산을 모든 경우의 수에 대해서 시도 
    //더한 값이 target이 되는 연산식을 카운팅함.
    
    //기저 조건
    if(index == numbers.size() -1){
        if( sum + numbers[index] == target)  answer++;
        if( sum - numbers[index] == target)  answer++;
        return;
    }

    dfs(numbers, target, index+1, sum + numbers[index] );
    dfs(numbers, target, index+1, sum - numbers[index] ); 
    
} 


int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target);
    
    return answer;
}