#include <string>
#include <cmath>
using namespace std;

long long solution(long long n) {

    int x = sqrt(n);
    return sqrt(n) - x == 0 ? pow(x+1, 2) : -1;   
}