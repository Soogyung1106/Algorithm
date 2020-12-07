#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {

    sort(numbers.begin(), numbers.end()); //오름차순 정렬 
    int max = numbers[numbers.size()-1] + numbers[numbers.size()-2];
    vector<int> v(max+1, 0);
    
    for(int i=0;i<numbers.size()-1;i++){
        for(int j=i+1;j<numbers.size();j++)
            v[numbers[i] + numbers[j]] = 1; //더한 값 = 배열의 인덱스 
    }
    
    vector<int> answer;
    for(int i = 0;i < v.size();i++){
        if(v[i] == 1) answer.push_back(i);
    }
    
    return answer;
}