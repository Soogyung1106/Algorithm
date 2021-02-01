#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<vector<int>> sets;
int N;

int getSum(vector<int> tmp){
    int sum =0;
    for(auto t : tmp)
        sum += t;
    return sum;
}

void getSets(int s, int depth, vector<int> tmp){
    //1~s 사이의 수를 이용해 N개의 조합(N중 for문)으로 합이 s인 집합을 구하는 함수 
    
    //기저조건
    if(depth == N+1) return;    
    else{
        for(int i=1;i<=s;i++){
            tmp.push_back(i);
            getSets(s, depth+1, tmp);//depth 다음의 for문 구하러..
            
            if(getSum(tmp) == s && tmp.size()==N){
                sort(tmp.begin(), tmp.end());
                if(sets.find(tmp) == sets.end()) sets.insert(tmp);        
                else return; //중복된다면..
            }
            tmp.pop_back(); 
        }//end for
    }//end else
   
}

vector<int> solution(int n, int s) {
    
    N = n;
    //n개의 자연수로 합이 s인 모든 집합들을 구함.
    vector<int> tmp;
    getSets(s, 1, tmp);
    
    //테스트
    /*
    for(auto elem : sets){
        for(int i=0;i<elem.size();i++)
            cout<<elem[i]<<" ";
        cout<<endl;
    }
    */

    vector<int> answer;
    //if sets가 비어있다면 -1 반환
    if(sets.empty()){
        answer.push_back(-1);
        return answer;
    }
    
    //집합들 중 곱했을 때 가장 큰 값을 answer에 저장 
    int max = 0;
    for(auto elem : sets){
        int x = 1;
        for(int i=0;i<elem.size();i++)
            x *= elem[i];
        if(max < x){
            max = x;
            answer = elem;
        }
    }

    return answer;
}