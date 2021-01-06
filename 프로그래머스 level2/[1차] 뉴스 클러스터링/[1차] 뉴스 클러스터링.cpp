#include <string>
#include <iostream>
#include <vector>
#include <cctype>
#include <set>

using namespace std;

vector<string> makeSet(vector<string> v, string str){
    
    for(int i=0;i<str.size();i++){

        if(i == str.size()-1) break;        
        if(isalpha(str[i])){ //알파벳 
            if(isalpha(str[i+1])){
                str[i] = tolower(str[i]); str[i+1] = tolower(str[i+1]); 
                v.push_back(str.substr(i, 2));    
            }else i+=1; //특수
        }       
    }
    
    return v;
}

int solution(string str1, string str2) {
    
    //다중집합.
    vector<string> v1; vector<string> v2;  
    v1 = makeSet(v1, str1); v2 = makeSet(v2, str2);
    double A = v1.size(); double B = v2.size();
    
    if(A == 0 && B == 0) return 1*65536; 
    
    //중복 집합 구하기 
    vector<string> v3; set<string> st; 
    for(int i=0;i<v1.size();i++){
        int j=0;
        while(j<v2.size()){
            if(v1[i] == v2[j]){
                v3.push_back(v2[j]);
                v2.erase(v2.begin()+j);
                break;
            }
            j++;
        }
    }
    double C = v3.size();
    
    double answer = C / (A + B - C) * 65536;
    return (int)answer;
}