#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[100001]; //메모이제이션

int solution(int n, vector<int> money) {
    
    sort(money.begin(), money.end()); //오름차순 정렬
    
    d[0] = 1; //0원을 만드는 방법 
    for(int i = money[0];i <= n;i += money[0]) //가장 작은 돈으로 만들 수 있는 가짓수
        d[i] = 1;
    
    //total 돈을 만드는 방법 
    for(int i=1;i<money.size();i++){
        int m = money[i]; //사용하는 돈.
        for(int total = 0;total<=n;total++)
            if(total >= m)
                d[total] += d[total-m]; //total을 money를 이용해 만드는 경우의 수
    }

    return d[n];
}