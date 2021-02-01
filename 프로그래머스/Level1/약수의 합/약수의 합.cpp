using namespace std;

int solution(int n) {
    int i = 1; int answer = 0;
    while(i<=n){
        if(n % i == 0) answer += i;
        i++;
    }
    return answer;
    
}