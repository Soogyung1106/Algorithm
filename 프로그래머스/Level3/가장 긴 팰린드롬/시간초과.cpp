#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int max = 1;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=s.size()-i;j++){ //길이
            string before = s.substr(0, j);
            string after = before;
            reverse(after.begin(), after.end());
            
            if(before == after){
                if(max < j) max = j;
            } 
        }   
    }
    
    return max;

}