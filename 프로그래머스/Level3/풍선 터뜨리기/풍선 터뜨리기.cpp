#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    
    vector<bool> check(a.size());
    check[0] = check[a.size()-1] = true;
    
    //target 왼쪽 최솟값보다 작은지 검사
    int min = a[0];
    for(int i=1;i<a.size()-1;i++){
        if(a[i] < min){
            check[i] = true;
            min = a[i];
        }
    }
    
    //target 오른쪽 최솟값보다 작은지 검사
    min = a[a.size()-1];
    for(int i=a.size()-2;i>=1;i--){
        if(a[i] < min){
            check[i] = true;
            min = a[i];
        }
    }
    
    //true인 것 개수 세기
    int answer = 0;
    for(auto e : check)
        if(e) answer++;
    
    return answer;
}