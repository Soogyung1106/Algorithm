#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> hashmap;
    
    for(int elem : nums){
        if(hashmap.find(elem) != hashmap.end()) hashmap[elem]++;
        else hashmap.insert(make_pair(elem, 1));
    }

    return hashmap.size() >= nums.size()/2 ? nums.size()/2 : hashmap.size();
}