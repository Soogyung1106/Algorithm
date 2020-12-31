#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());

    int answer = 1;
    for(int i=1;i<nums.size();i++){
        if(answer >= nums.size()/2) break;
        if(nums[i] != nums[i-1]) answer++;
    }

    return answer>= nums.size()/2 ? nums.size()/2 : answer;
}