#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {

    long long x = sqrt(n);
    return sqrt(n) - (int)sqrt(n) == 0 ? pow(x+1, 2) : -1;
}