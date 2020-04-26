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
    
    //2단계: string의 find 함수 사용 -> substr보다 효율적(이 방법은 길이를 판단해야 함)
    for(int i =0; i < size; i++){
        
        //예외처리
        if (i == size) { 
            answer = true; 
            break;
        }           
        for(int j = i + 1; j <size ;j++ ){
            if (phone_book[j].find(phone_book[i]) == 0)
                answer = false;
                break;   
        }//end for j
    }//end for i

    
    return answer;
}