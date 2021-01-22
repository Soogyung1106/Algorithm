#include <vector>
#include <iostream>
using namespace std;


bool isPrime(int num){ //num은 3이상임.
    int i= 2;
    while(i < num){
        if(num % i == 0) return false;
        i++;
    }

    return true;
}

int solution(vector<int> nums) {

    int answer = 0;
    for(int i=0;i<nums.size()-2;i++){ //조합
        for(int j = i+1; j<nums.size()-1;j++){
            for(int k =j+1;k<nums.size();k++){
                if(isPrime(nums[i]+nums[j]+nums[k]))  answer++;  
            }
        }
    }

    return answer;
}