#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer; //가장 많이 맞춘 사람들만 리턴
    int cnt[3]={0, 0, 0}; //수포자 1,2,3이 각자 맞춘갯수 카운트
    vector<int> math1{1,2,3,4,5}; 
    vector<int> math2{2,1,2,3,2,4,2,5}; 
    vector<int> math3{3,3,1,1,2,2,4,4,5,5}; 
    
    
    /*
    //(1) 예외상황 처리
    int q=0; //몫 
    int r=0; // 나머지
    //수포자 1
    if (answers.size() > math1.size()){  
            q = answers.size() / math1.size();
            r = answers.size() % math1.size();
            for(int i=0;i<q-1;i++){
                math1.push_back(1);
                math1.push_back(2);
                math1.push_back(3);
                math1.push_back(4);
                math1.push_back(5);
            }
            if(r>0){
                for(int i=0;i<r;i++)
                    math1.push_back(math1[i]);
            }
                
    }
   
    
    //수포자2 
    q= 0; r = 0; //초기화
    if (answers.size() > math2.size()){  
            q = answers.size() / math2.size();
            r = answers.size() % math2.size();
        
            for(int i=0;i<q-1;i++){
                math2.push_back(2);
                math2.push_back(1);
                math2.push_back(2);
                math2.push_back(3);
                math2.push_back(2);
                math2.push_back(4);
                math2.push_back(2);
                math2.push_back(5);
            }
            if(r>0){
                for(int i=0;i<r;i++)
                    math2.push_back(math2[i]);
            }
    }
    
    //수포자3
    q= 0; r = 0; //초기화
    if (answers.size() > math3.size()){  
            q = answers.size() / math3.size();
            r = answers.size() % math3.size();
            
            for(int i=0;i<q-1;i++){
                math3.push_back(3);
                math3.push_back(3);
                math3.push_back(1);
                math3.push_back(1);
                math3.push_back(2);
                math3.push_back(2);
                math3.push_back(4);
                math3.push_back(4);
                math3.push_back(5);
                math3.push_back(5);
            }
            if(r>0){
                for(int i=0;i<r;i++)
                    math3.push_back(math3[i]);
            }
    }    
   
   */
    
    //(2) 수포자1,2,3 -> 정답 여부 판단
    //sort(math1.begin(), math1.end()); //정렬 
    //sort(answers.begin(), answers.end()); 
    
    for(int i=0;i<answers.size();i++){
        if(answers[i] == math1[i%math1.size()])
            cnt[0]++;
        if(answers[i] == math2[i%math2.size()])
            cnt[1]++;
        if(answers[i] == math3[i%math3.size()])
            cnt[2]++;
        
    }

    //(3) 가장 많이 맞춘 사람 찾기
    int max = *max_element(cnt, cnt+3); // 최대값 찾기 
    
    for(int i=0;i<3;i++){
        if(cnt[i] == max)
            answer.push_back(i+1);
    }
    

    return answer;
}