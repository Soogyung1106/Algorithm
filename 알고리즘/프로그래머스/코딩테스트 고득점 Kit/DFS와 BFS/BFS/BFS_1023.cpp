#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100;
int node, edge; //정점 개수, 간선 개수
vector<int> myGraph[MAX];

void BFS() {

	//1. 맨 앞에 있는 것 저장 FRONT 
	//2. 빼기 POP
	//3. 맨 앞의 인접 노드들 넣기 PUSH
	//4. 1, 2, 3 반복

	bool check[MAX] = { false, }; //방문했는지 여부 참고
	queue<int> Queue;

	Queue.push(1);

	while (!Queue.empty()) { // 큐에 남아있을 때까지 

		int front = Queue.front();
		check[front] = true; printf("%d ", front);//방문함. 
		Queue.pop(); //맨 앞 빼기 

		for (int i = 0; i < myGraph[front].size(); i++) {
			int child = myGraph[front][i];

			if (check[child] == false) {
				check[child] = true; //방문함. 
				Queue.push(child);
			}
		}

	}

}


int main() {

	scanf("%d %d", &node, &edge);

	for (int i = 0; i < edge; i++) {
		int a, b;

		//a와 b가 연결돼있다. 
		scanf("%d %d", &a, &b); 
		myGraph[a].push_back(b);
		myGraph[b].push_back(a);
	}

	BFS(); //BFS 순회 

	return 0;
}