#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int countP = 0; int countY = 0;
    
    for(int i=0;i<s.size();i++){
        
        if(s[i] == "p" || s[i] == "P")
            countP++;
        
        if(s[i] == "y" || s[i] == "Y")
            countY++;
        
    }
 
    return countP == countY;
}