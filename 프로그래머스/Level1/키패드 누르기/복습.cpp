#include <string>
#include <vector>

using namespace std;

//0, 1, 2, 3, 4, 5, 6, 7, 8의 위치 (row, col)
vector<pair <int, int>> v = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}; 
pair<int, int> left = make_pair(3, 0); //처음 왼손 위치 * 
pair<int, int> right = make_pair(3, 2); //처음 오른손 위치 # 

char whichHand(int number, string hand){
    int leftDist = abs(left.first - v[number].first)+abs(left.second - v[number].second);
    int rightDist = abs(right.first - v[number].first)+abs(right.second - v[number].second);
    
    if(leftDist > rightDist) return 'R';
    else if(leftDist < rightDist) return 'L';
    else{
        if(hand == "right") return 'R';
        else return 'L';
    } 
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i =0;i<numbers.size();i++){
        char tmp = '0';
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){ //왼손
            tmp = 'L';
        }else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){ //오른
            tmp = 'R';
        }else{ //더 가까운 손으로
            if(whichHand(numbers[i], hand) == 'R')  tmp = 'R';
            else  tmp = 'L';
        }
        
        answer += tmp;
        if(tmp =='L'){ //위치 갱신
            left.first = v[numbers[i]].first;
            left.second = v[numbers[i]].second;
        }else{
            right.first = v[numbers[i]].first;
            right.second = v[numbers[i]].second;
        }
        
    }
    
    return answer;
}