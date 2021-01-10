#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<string>> table;
vector<string> comb; //가능한 컬럼 조합

void getCombination(int k){ 
    //nCk comb에서 k=1개, 2개,...comb.size()개를 뽑았을 때의 조합을 모두 구해tj comb에서 추가
    
    //col에서 k개의 조합을 구하기
    vector<int> idx(k, 1);
    for(int i=0;i<table[0].size()-k;i++) idx.push_back(0);
    sort(idx.begin(), idx.end());
    
    do{
        string tmp = "";
        for(int i=0;i<idx.size();i++){
            if(idx[i] == 1) tmp += (char)(i+48); 
        }
        comb.push_back(tmp);
    }while(next_permutation(idx.begin(), idx.end()));
    
    //기저조건
    if(k == table[0].size()) return;
    else getCombination(k+1);

}

bool isUnique(string str){ //해당 컬럼 조합이 유일성을 만족하는지 검사하는 함수 
    
    set<string> s;
    for(int i=0;i<table.size();i++){ //행(row)
        string tmp = "";
        for(int j=0;j<str.size();j++){//열(col)
            int col = str[j]-'0';
            tmp += table[i][col];
        }
        
        if(s.find(tmp) == s.end()) s.insert(tmp); //중복 x
        else return false;  
    }
    
    return true;
}

int solution(vector<vector<string>> relation) {
    
    table = relation;
    
    //가능한 모든 조합의 컬럼을 구해야 함. 
    getCombination(1); //1개부터 size개의 조합을 구함.
    
    
    int answer = 0;
    for(int i=0;i<comb.size();i++){
        
        if(isUnique(comb[i])){ //조합이 유일성을 만족하는지 검사 -> isUnique 함수 
            answer++; 
            
            //조합 맨 뒤부터 순회하면서 기본키가 포함된 것은 삭제(최소성)
            for(int j=i+1;j<comb.size();j++){ //comb[i] 조합이 포함된 조합 모두 삭제
                string cmp = comb[j]; bool flag = true; 
                for(int k=0;k<comb[i].size();k++){
                    if(cmp.find(comb[i][k]) == string::npos){
                        flag = false;
                        break;    
                    }  
                }
                
                if(flag){
                    comb.erase(comb.begin()+j);
                    j--;
                }
            }
            
            
        }//end if
    }
    
    return answer;
}