#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    //int to string 스트링으로 바꿔 저장한 배열 
    vector<string> string_numbers; 
    for(int i=0;i<numbers.size();i++){
        string_numbers.push_back(to_string(numbers[i]));
    }
    
    //모든 경우의 수. 문자열 합치기
    int max = 0;     
    
    do{
        string str1 = string_numbers[0]; 
        for(int i=0; i<numbers.size()-1; i++){
            string str2 = string_numbers[i+1];
            str1.append(str2);
		}
        
        max = (max<stoi(str1)) ? stoi(str1): max;
        
    }while(next_permutation(string_numbers.begin(), string_numbers.end()));
     
    answer = to_string(max);
    return answer;
}