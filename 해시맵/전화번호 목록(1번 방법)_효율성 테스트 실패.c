#include <string>
#include <vector>
#include <unordered_map>  // 해시맵 
#include <string> // C++의 string클래스가 선언되어 있는 헤더파일  
                //(참고) cstring과 string은 다른 헤더파일임 

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    string str1 = "";
    string str2 = "";
    string str3 = "";
    
    //(0,1)(0,2)(0,3)(1,2)(1,3)(2,3) 
    
    for(int i =0; i < size; i++){
        
        //예외처리
        if (i == size) { 
            answer = true; 
            break;
        }           
        for(int j = i + 1; j <size ;j++ ){
            
            //(1)비교쌍 중에 길이가 더 긴것을 알아내기 
            
            str1 = phone_book[i];
            str2 = phone_book[j]; 
            
            //(2)더 긴 문자열을 더 짧은 문자열 사이즈만큼 슬라이싱
            if(str1.size()>str2.size()) {//str1이 더 길다면
                str3 = str1.substr(0, str2.size()); //슬라이싱
                if (str3.compare(str2) == 0){
                    answer = false;
                    break;
                }
            }else if (str1.size()<str2.size()){ //str2가 더 길다면
                
                str3 = str2.substr(0, str1.size()); 
                if (str3.compare(str1) == 0){
                    answer = false;
                    break;
                }
            }else{ //str1과 str2의 길이가 같을 경우
                if (str2.compare(str1) == 0){
                    answer = false;
                    break;
                }
            }
                
            /*
            if (str1.at(0)  == str2.at(0)){
                if(str1.at(1)  == str2.at(1)){  //맨 앞자리부터 2개 이상 겹칠 때, false 
                    answer = false;
                    break;
                }
            }
            */
            
        }
    }
    
    return answer;
}