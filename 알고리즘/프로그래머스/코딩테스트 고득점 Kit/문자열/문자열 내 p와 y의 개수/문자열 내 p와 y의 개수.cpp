#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int countP = 0; int countY = 0;
    
    for(int i=0;i<s.size();i++){
        char tmp = s.at(i);
        if(tmp == 'p' || tmp == 'P')
            countP++;
        
        if(tmp == 'y' || tmp == 'Y')
            countY++;
        
    }
    
   if(countP == countY)
       answer = true;
    else if(countP != countY)
       answer = false;
    else if(countP == 0 && countY == 0) //예외처리
       answer = true;
 
    return answer;
}