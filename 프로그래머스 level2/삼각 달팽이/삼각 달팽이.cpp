#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    
    vector<vector <int>> v(n, vector<int>(n, 0)); v[0][0] = 1;
    
    int i = 1; int num = 1; int curX = 0; int curY = 0; 
    for(i =1;i<=n;i++){
        
        if(i % 3 == 1){ //↓    
        
            while(1){
                curX++; 
                if(curX>= n || v[curX][curY]){
                    curX--;
                    break;  
                }
                if(v[curX][curY]==0) v[curX][curY] = ++num;
                  
            }
          
        }else if(i % 3 == 2){ //→
            
            while(1){
                curY++;
                if(curY >= n || v[curX][curY]){
                    curY--;
                    break;  
                } 
                if(v[curX][curY]==0)  v[curX][curY] = ++num;
            }
        
        }else{ //↖
            
            while(1){
                curX--; curY--;
                if(v[curX][curY]){
                    curX++; curY++;
                    break;  
                } 
                if(v[curX][curY]==0)  v[curX][curY] = ++num; 
            }
            
        }
     
    }
    
    vector<int> answer;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++)  answer.push_back(v[i-1][j-1]);   
    }
    return answer;
}