#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& temp, vector<string>& answer, int cnt) {

    temp.push_back(from); //temp에 노드 추가 

    if (cnt == tickets.size()) { //기저조건
        answer = temp; //가장 먼저 true 리턴하는게 답임 -> 애초에 sort로 사전정렬
        return true; 
    }

    for (int i=0 ; i<tickets.size() ; i++) { //from과 같은 노드 찾기. 
        if (tickets[i][0] == from && visit[i] == false) { //방문 안 한것중에 
            visit[i] = true; //찾았으면 true 

            bool success = dfs(tickets[i][1], tickets, visit, temp, answer, cnt+1);
            if (success) return true; 
            else visit[i] = false; //실패한 경우 visit 원상복귀 
            
            //그렇다면 실패가 되는 과정은..??!
        }
    }
    //그 다음 경로를 찾을 수 없다면 여기까지 오게됨. 찾으면 그전에 true값 리턴됨. 
    temp.pop_back();
    return false;
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer, temp;  
    vector<bool> visit(tickets.size(), false);

    sort(tickets.begin(), tickets.end()); //사전순 정렬
    dfs("ICN", tickets, visit, temp, answer, 0); //ICN에서 무조건 출발한다 했으므로.. 

    return answer;
}