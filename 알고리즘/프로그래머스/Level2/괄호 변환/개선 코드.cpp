#include <string>
#include <vector>

using namespace std;

string answer = "";

string solution(string p){
    if(p == "") return p; //1
    
    int open = 0; int close = 0; //2
    string u= ""; string v= "";
    for(int i=0;i<p.size();i++){
        if(p[i] == '(') open++;
        else close++;
        
        if(open == close){
            u = p.substr(0, i+1);
            v = p.substr(i+1, p.size()-(i+1));
            break;
        }
    }
    
    //3
    vector<char> vt; 
    for(int i=0;i<u.size();i++){
        
        if(!vt.empty()){
            if(u[i] == ')' && vt.back() == '(') vt.pop_back();
            else vt.push_back(u[i]); 
        }else vt.push_back(u[i]); 
    }
    
    if(vt.empty()){ //올바른 문자열
        return u += solution(v);  //3-1 
    }else{
        string s = ""; s += '('; //4-1
        s += solution(v); //4-2
        s += ')'; //4-3
        //4-4
        u.erase(0, 1); u.erase(u.size()-1, 1); 
        int end = u.size();
        for(int i=0;i<end;i++){
            if(u[i] == '(') s+=')';
            else s += '(';
        }
        return s; //4-5
    } 
    
}
