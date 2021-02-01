#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int end = n/2;
    for(int i=1;i<=end;i++) answer += "수박";

    if(n%2 == 1) answer += "수"; //홀수라면
    return answer;
}