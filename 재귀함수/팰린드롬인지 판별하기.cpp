#include <iostream>
#include <string>

using namespace std;

void isPalindrome(string word, int idx){
  // 입력한 문자열이 팰린드롬인지 판별해서 Yes, No를 출력해주는 함수 
   
  //기저 조건 
  if(idx == word.size()/2){ 
    cout<<"Yes";
    return;
  }else{
    if(word[idx] == word[word.size()-1-idx]){
        idx++;
        isPalindrome(word, idx);
    }else{
      cout<<"No";
      return;    
    }
  }//end else

}


int main(){
  string word;
  cin>>word;
  
  isPalindrome(word, 0);
  
}