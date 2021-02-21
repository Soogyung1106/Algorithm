#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main() {

	//입력
	int N; //회의 최대 개수
	cin >> N;

	vector<pair <int, int>> meeting;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		meeting.push_back({ start, end });
	}

	//시작시간, 종료 시간 기준 정렬
	sort(meeting.begin(), meeting.end(), compare);

	int max = 0;
	int next = 0;
	for (int i = 0; i < meeting.size(); i++) {
		int cnt = 1;
		next = meeting[i].second;
		for (int j = i+1; j < meeting.size(); j++) {
			if (meeting[j].first >= next) {
				cnt++;
				next = meeting[j].second;
			}

		}

		if (max < cnt) max = cnt;
		cnt = 0; //초기화
		
	}

	cout << max;

	return 0;
}