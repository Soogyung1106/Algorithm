#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    int months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    
    int day = 0;  
    for(int i=1;i<a;i++){
        day += months[i]; 
    }
    day += b; 
    
    //1(금),2(토), 3(일), 4(월), 5(화), 6(수), 7(목)
    string days[7] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int idx = day % 7;
    
    string answer = "";
    if(idx == 0) idx = 7; //예외처리
    answer = days[idx-1];
    
    return answer;
}