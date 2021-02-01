#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;
    for(auto word : skill_trees){
        
        bool flag = true; int index = 0;
        for(auto e : word){ // 단어
            
            for(int k =0;k<skill.size();k++){
                if(e == skill[k]){
                    if(k == index){
                        index++; break;
                    }else{
                        flag = false; break;
                    }
                }     
            }//1중
            if(flag == false) break;
            
        }//2중
        if(flag == true) answer++;
    }//3중
    
    
    return answer;
}