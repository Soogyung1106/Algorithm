#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    
    string answer = "";    
    while(n != 0){
        if(n %3 == 0){ //3의 배수일 떄
            answer += '4'; 
            n = (n/3)-1;
        }else{
            answer += to_string(n%3);
            n /= 3;
        } 
    }    
    
    reverse(answer.begin(), answer.end());
    return answer;
}