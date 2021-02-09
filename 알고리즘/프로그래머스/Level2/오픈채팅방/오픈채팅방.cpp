#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>
 
using namespace std;

vector<string> solution(vector<string> record) {
    
    
    //토큰으로 분리해서 v에 저장 → Enter/아이디/이름
    vector<vector <string>> v; vector<string> tokens;
    for(auto elem : record){
        string buf = ""; stringstream ss(elem);
        while(ss >> buf){
            tokens.push_back(buf);
        }
        v.push_back(tokens);
        tokens.clear();
    }
    

    //Map에 최종 이름 저장 
    unordered_map<string, string> m;
    for(auto elem : v){
        if(elem[0] == "Enter"){
            if(m.find(elem[1]) == m.end()) m.insert({elem[1], elem[2]});
            else m[elem[1]] = elem[2];
        }if(elem[0] == "Change") m[elem[1]] = elem[2];
        
    }
    
    //answer에 담기
    vector<string> answer; 
    for(auto elem : v){
        string s = "";
        if(elem[0] == "Enter")  s = m[elem[1]]+"님이 들어왔습니다.";      
        else if(elem[0] == "Leave") s = m[elem[1]]+"님이 나갔습니다.";    
        else continue;
        answer.push_back(s);
    }
    
    return answer;
    
}