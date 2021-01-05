#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(vector<int> a, vector<int> b){
    return a.size()<b.size();
}

vector<int> solution(string s) {
    
    vector<vector <int>> v; string tmp = ""; vector<int> vt;
    for(int i=1;i<s.size()-1;i++){
        
        if(isdigit(s[i]))  tmp += s[i];
        
        if(s[i] == ',' || i == s.size()-2){ //코마를 만나면 무조건 삽입
            vt.push_back(stoi(tmp));
            tmp = "";

            if(s[i-1] == '}' || i == s.size()-2){
                v.push_back(vt);
                vt.clear();
            }
        }
    }
    
    sort(v.begin(), v.end(), compare); //개수 크기순으로 정렬
    
    vector<int> answer; set<int> st; //중복 체크용
    for(auto elem : v){
        for(int i=0;i<elem.size();i++){
            if(st.find(elem[i]) == st.end()){
                st.insert(elem[i]);
                answer.push_back(elem[i]);
            }
        }
    }
    return answer;
}