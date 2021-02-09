#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main() {
	pq.push(3);
	pq.push(1);
	pq.push(4);
	pq.push(1);
	pq.push(5);
	pq.push(9);
	while (!pq.empty()) {
		printf("%d", pq.top());
		pq.pop();
	}
}

