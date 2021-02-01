#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    
    sort(A.begin(), A.end(), greater<int>()); //내림차순
    sort(B.begin(), B.end()); //오름차순
    
    int answer = 0;
    for(int i=0;i<A.size();i++) answer += A[i]*B[i];
    return answer;
}