#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    string days[8] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED", ""};
    int months[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int day = 0;
    for(int i=1;i<=a-1;i++)   day += months[i];
    day += b;
    return days[day%7];
}