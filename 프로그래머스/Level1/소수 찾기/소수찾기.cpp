
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n) {
    int* arr = new int[n+1]; fill(arr, arr+n+1, 0);

    int i=2;
    while(i<=n){ //에라토스테네스의 체

        if(arr[i] != 1){  //i=2 j=1,2,3,4,5,..
            for(int j=2;j*i<=n;j++) arr[i*j] = 1;
        }
        i++;
    }

    //소수의 갯수 세기 
    int answer = 0;
    for(int i=2;i<=n;i++){
        if(arr[i] == 0) answer++;
    }

    return answer;
}