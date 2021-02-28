/*
다익스트라 알고리즘 - 선형 탐색 O(n^2)을 이용
*/

#include <iostream>
using namespace std;

int number = 6;
int INF = 1000000000; //무한대

//전체 그래프를 초기화합니다. 
int a[6][6] = {
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

bool visited[6]; //방문한 노드 기록
int d[6]; //최단 거리 dp 저장, 1에서 i까지 가는 최단거리 저장

//가장 최소 거리를 가지는 정점을 반환합니다.
int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		//방문하지 않은 노드 중에 현재 최솟값보다 더 적은 비용의  거리가 있다면
		if (d[i] < min && !visited[i]) {
			min = d[i];
			index = i; 
		}
	}
	return index;
}

//다익스트라를 수행하는 합수입니다. 
//start 정점부터 다른 모든 정점으로 가는 최소비용을 구해주는 함수.
void dijkstra(int start) {
	
	//시작 전 초기화
	visited[start] = true; //시작점 방문 처리
	for (int i = 0; i < number; i++) 
		d[i] = a[start][i];

	//다익스트라
	for (int i = 0; i < number - 2; i++) {
		int current = getSmallIndex(); //방문하지 않은 노드 중에 최소비용의 노드 인덱스를 반환
		visited[current] = true; //방문 처리.

		//최소 비용 노드의 인접 노드를 확인
		for (int j = 0; j < 6; j++) {
			//★거쳐서 가는 비용이 더 작다면★
			if (!visited[j]) {
				if (d[current] + a[current][j] < d[j]) 
					d[j] = d[current] + a[current][j];//최소비용으로 갱신
			}
		}
	}

}


int main() {
	dijkstra(0); //0(1)번 노드트부터 모든 노드까지의 최단거리 
	for (int i = 0; i < number; i++) 
		cout << d[i]<<" ";
}