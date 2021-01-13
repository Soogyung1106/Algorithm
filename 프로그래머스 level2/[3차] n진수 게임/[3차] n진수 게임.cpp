#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string elem = "0123456789ABCDEF";

//N진수로 number를 바꿈. 
string changeToN(int N, int number){
    
    string result = ""; 
    while(number != 0){
        result += elem[number % N];
        number /= N; //그 다음 자리수 위해..
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    
    //n: n진수, t:출력해야 할 개수, m: 참가 인원, p: 튜브의 순서 
    
    //숫자 number를 n진수로 변환 -> result에 붙여 넣기
    //result의 길이가 m*t 개보다 커지면 종료 
    string result = "0";
    for(int num=1; result.size()<=m*t;num++){
        result += changeToN(n, num);
    }
    
    //p번째마다 t개 answer에 넣기 
    string answer = "";
    for(int i=0;i<t;i++)
        answer += result[m*i+p-1];
    
    return answer;
    
    
}