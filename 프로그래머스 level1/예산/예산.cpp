#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    
    int answer = 0; int sum = 0;
    for(int i=0;i<d.size();i++){
        sum += d[i];
        if(budget>=sum) answer++;
        else break;
    }
    
    return answer;
}