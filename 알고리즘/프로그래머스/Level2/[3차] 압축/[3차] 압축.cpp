#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    
    //사전 초기화
    unordered_map<string, int> dic; 
    for(int i = 0;i<26;i++){
        char c = 'A' +i;
        char arr[2] = {c};
        string str(arr); 
        dic.insert(make_pair(str, i+1));
    }
    
    //msg 처음부터 돌면서 사전에서 일치하는 가장 긴 문자열 찾음. -> answer에 push_back
    //없으면 현재 인덱스 사전에서 찾아 -> answer에 push_back 그리고 dic에 그 다음 
    int maxlen = 1; //사전에 저장된 문자의 최대 길이
    int dicNum = 26; //사전에 저장할 번호
    vector<int> answer;
    for(int i = 0;i<msg.size();i++){
        //maxlen, maxlen-1, .., 1개의 길이까지 dic 맵에서 검색.
        //answer에 해당 dic 숫자 push_back하고 사전에 현재 index + 1 글자 합쳐서 추가 
        for(int j=maxlen;j>=1;j--){ 
            if(i+j-1<=msg.size()-1){ //인덱스 범위 넘어가는 것 조심.
                string search = msg.substr(i, j);
                
                if(dic.find(search) != dic.end()){ //찾으면..
                    answer.push_back(dic[search]);
                
                    //사전에 새로 등록할 단어
                    search += msg[i+j]; 
                    dicNum += 1;
                    dic.insert(make_pair(search, dicNum));
                    
                    //사전에 저장된 문자 최대 길이 갱신
                    if(search.size() > maxlen) maxlen = search.size();
                    
                    i = i+j-1; //i인덱스 jump
                    break;
                }    
            }
                 
        }//end for    
    }//end for

    
    return answer;
}