#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 0;

    //오름차순 정렬 후 가장 큰 수
    sort(numbers.begin(), numbers.end(), greater<int>());
    int max = stoi(numbers); 

    //에라토스테네스의 체로 모든 소수 구하기 
    bool* arr = new bool[max+1]; fill(arr, arr+max+1, true);
    for(int i = 2 ; i <= max ; i++){ //2이면 4, 6, 8, 10...다 지우기
        if(arr[i] == true){
            for(int j = 2; i*j <= max; j++)
                arr[i*j] = false; 
        }  
    }

    //numbers 숫자 사용 여부 check 하기 
    for(int i = 2 ;i <= max ; i++){

        if(arr[i] == true){ //소수라면 
            string primeNum = to_string(i);
            bool flag = true;
            string tmp = numbers;

            //종이 조각 숫자 사용 검사
            for(int j=0;j < primeNum.size();j++){ 
                for(int k=0;k<numbers.size();k++){

                    if(primeNum[j] == tmp[k]){
                        tmp[k] = ' '; break;
                    }else if(k == numbers.size()-1){
                        flag = false; break;
                    }      
                }

                if(flag == false)
                    break;
            }//end for

            if(flag == true)
                answer++;

        }
    }


    return answer;
}