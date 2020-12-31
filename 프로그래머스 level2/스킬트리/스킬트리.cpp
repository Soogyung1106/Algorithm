#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0;i<skill_trees.size();i++){
        
        bool flag = true; int index = 0;
        for(int j=0;j<skill_trees[i].size();j++){ // 단어
    
            for(int k =0;k<skill.size();k++){
                if(skill_trees[i][j] == skill[k]){
                    if(k == index){
                        index++; break;
                    }else{
                        flag = false; break;
                    }
                }     
            }//end for 
            if(flag == false) break;
        }
        if(flag == true) answer++;
    }
    
    
    return answer;
}