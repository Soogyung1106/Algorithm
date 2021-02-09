#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 0;

    //가장 큰 수가 되도록 내림차순 정렬 
    sort(numbers.begin(), numbers.end(), greater<int>());
    int* check = new int[numbers.size()]; 
    
    if(numbers[0] != '0'){ //000 -> 0이므로 answer = 0 리턴 
        
        //가장 큰 수 이하의 가능한 소수 모두 찾기  
        int maxNum = stoi(numbers);
        for(int i = 2;i<= maxNum ;i++){
            
            //i가 소수인지 판단 
            int count = 0;  bool primeNum = true;  
            for(int j = 1; j<=i;j++){ //1과 자기자신 외의 것으로 나누어 떨어지면 x 
                
                if(i % j == 0) count++;
                
                if(count > 2){
                    primeNum = false; break;  
                }
                
            }
            
            //소수인 경우 
            if(primeNum == true){
                
                string strNum = to_string(i);
                

                //주어진 숫자를 사용했는지 check
                fill(check, check+numbers.size(), 0);
                int checkCount = 0;
                for(int i=0;i<strNum.size();i++){
                    for(int j=0;j<numbers.size();j++){
                        
                        if(strNum[i] == numbers[j] && check[j] == 0){
                            check[j] = 1; checkCount++; //숫자 사용
                            if(i==strNum.size()-1 ){ 
                                answer++;
                            }
                            
                            break;
                        }else if(j == numbers.size()-1){ primeNum = false; }
                
                    }//end for1
                    if(primeNum == false)
                           break;
                }//end for2
            }//end if
                
 
        }//for      
    }//end if   
    
    return answer;
}