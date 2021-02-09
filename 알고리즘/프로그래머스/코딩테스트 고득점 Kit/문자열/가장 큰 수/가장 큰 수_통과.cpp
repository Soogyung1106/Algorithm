#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){

    string case1 = a + b;
    string case2 = b + a;
    return case1 > case2; 
    
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strNumbers;
    
    //int to string 
    for(int i=0;i<numbers.size();i++){
        strNumbers.push_back(to_string(numbers[i]));
    }
    
    //숫자를 사전순으로 정렬(3, 30, 31)
    sort(strNumbers.begin(), strNumbers.end(), compare);
    
    //가장 큰 수로 정렬된 문자열 요소들 합치기
    for(int i=0;i<numbers.size();i++){
        answer.append(strNumbers[i]);
    }
    
    if(answer[0] == '0')
        return answer = "0";
    
    return answer;
}