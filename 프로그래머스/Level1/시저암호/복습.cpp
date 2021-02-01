#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
 
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            if(islower(s[i]) && s[i]+n > 'z') s[i] = 'a' + (s[i]+n-'z')-1;
            else if(isupper(s[i]) && s[i]+n > 'Z') s[i] = 'A' + (s[i]+n-'Z')-1;
            else s[i] += n;
        } 
            
    }
    
    return s;
}