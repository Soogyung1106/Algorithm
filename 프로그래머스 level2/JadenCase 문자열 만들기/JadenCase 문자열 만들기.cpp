#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {

    //단어별로 넣기
    vector<string> v; string word = "";
    for(int i=0;i<s.size();i++){
        word += s[i];
        if(s[i] == ' '){
            v.push_back(word.substr(0, word.size()-1)); 
            word = ""; //초기화
        }if(i == s.size()-1) v.push_back(word);   
    }

    //단어별로 JadenCase로 만들기
    string answer = "";
    for(int i=0; i<v.size();i++){ 
        string str = v[i];

        for(int i=0;i<str.size();i++){
            if(isalpha(str[i])) str[i] = tolower(str[i]); //소문자로
        }

        if(!isdigit(str[0])) str[0] = toupper(str[0]); //첫글자 대문자로

        answer += str; //이어붙이기
        if(i!=v.size()-1) answer += ' ';
    }

    return answer;

}