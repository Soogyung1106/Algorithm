#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  
    vector<int> v{0, 1};    
    for(int i=2;i<=n;i++)   v.push_back(v[i-1]% 1234567 + v[i-2]% 1234567);
    return v[n] % 1234567;
}