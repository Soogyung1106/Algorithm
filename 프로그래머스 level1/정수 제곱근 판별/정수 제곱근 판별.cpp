#include <string>
#include <cmath>
using namespace std;

long long solution(long long n) {

    int x = sqrt(n);
    if(sqrt(n) - x == 0) return pow(x+1, 2);  
    else return -1;
}