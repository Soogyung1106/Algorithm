#include <string>
#include <vector>
#include <unordered_map>  // 해시맵 
#include <algorithm> //sort() 함수 -> int, char, string 상관없이 정렬해줌 
#include <string> // C++의 string클래스가 선언되어 있는 헤더파일  
                //(참고) cstring과 string은 다른 헤더파일임 

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int size = phone_book.size();
    
    //1단계: 우선 길이순으로 정렬 -> 접두 부분이 비슷한것끼리 가까이 위치하게 됨
    sort(phone_book.begin(), phone_book.end()); //오름차순으로 정렬
    
    //1-1단계: 배열 내의 원소들이 길이가 모두 같은 경우인지 check ex) ["123", "456", "789"]
    int pre = 0;
    bool allSizeSame = false;
    for(int i=0;i<size;i++){
        if(i>0){ //두 번째 항부터 체크
            if(pre != phone_book[i].size()){
                allSizeSame = false;
                break; 
            }else if(i == size-1){ 
                allSizeSame = true;
            }                
        }
            
        pre = phone_book[i].size(); 
    }
    
    
    
    //2단계: (0,1)(0,2)(0,3)(1,2)(1,3)(2,3) 순서로 비교 
    
    string str1 = "";
    string str2 = "";
    string str3 = "";
    
    for(int i =0; i < size; i++){
        
        //예외처리
        if (i == size) { 
            answer = true; 
            break;
        }           
        for(int j = i + 1; j <size ;j++ ){
            
          
            
            str1 = phone_book[i];
            str2 = phone_book[j];
            
            if (allSizeSame == true){ //위치!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                if (str2.compare(str1) == 0){
                    answer = false;
                    break;
                } 
            }else{
                //(1) 더 긴 문자열을 더 짧은 문자열 사이즈만큼 슬라이싱
                if(str1.size()>str2.size()) {//str1이 더 길다면
                    str3 = str1.substr(0, str2.size()); //슬라이싱
                    if (str3.compare(str2) == 0){
                        answer = false;
                        break;
                    }
                }else { //str2가 더 길거나 같으면
                
                    str3 = str2.substr(0, str1.size()); 
                    if (str3.compare(str1) == 0){
                        answer = false;
                        break;
                    }
                }
                
            }
     
            
        }//end for j
    }//end for i
    
    return answer;
}