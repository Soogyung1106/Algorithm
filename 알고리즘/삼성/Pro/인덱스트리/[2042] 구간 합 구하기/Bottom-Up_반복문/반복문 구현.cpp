/* 구간합 - 인덱스트리(Bottom-Up 구현)
참고 : https://hanbi97.tistory.com/336?category=752612
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define MAX 1000000
using namespace  std;

typedef long long ll;

ll N, M, K, OFFSET; //N은 데이터의 수, M은 수의 변경 횟수, K는 구간의 합을 구하는 횟수
ll datas[MAX + 1], tree[4 * MAX];

void init() {
	for (OFFSET = 1; OFFSET < N; OFFSET *= 2); //OFFSET 출발 지점 세팅. 
	for (ll i = 0; i < N; i++) tree[i + OFFSET] = datas[i]; //leaf 채우기 
	for (ll i = N; i < OFFSET; i++) tree[i + OFFSET] = 0; //leaf 나머지 채우기(포화이진트리) 
	for (ll i = OFFSET - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1]; //parent 채우기
}

void update(ll idx, ll value) {
	idx += OFFSET; 
	tree[idx] = value;
	idx /= 2;

	//idx의 부모노드부터 갱신시키기. 
	while (idx > 0) {
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		idx /= 2;
	}
}


ll query(ll start, ll end) {
	start += OFFSET; end += OFFSET; 
	ll ans = 0;

	while (start <= end) {
		if (start % 2 == 1) ans += tree[start++]; //start가 오른쪽 자식 노드일 경우  
		if (end % 2 == 0) ans += tree[end--]; //end가 왼쪽 자식 노드일 경우  

		start /= 2; end /= 2;
	}
	
	return ans; 
}

int main() {
	ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	cin >> N >> M >> K; 
	for (int i = 0; i < N; i++) 
		cin >> datas[i];
	
	init();

	for (ll i = 0; i < M + K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b - 1, c);
		if (a == 2) cout << query(b - 1, c - 1) << '\n';
	}

	return 0;
}