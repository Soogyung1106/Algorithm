#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;
	vector<int> stride;

	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		if (i >= 1)
			stride.push_back(v[i] - v[i - 1] - 1);
	}


	int min = *min_element(stride.begin(), stride.end());
	int answer = 0; //심어야 하는 나무 수 

	while (1) {
    
		for (int i = 0; i < stride.size(); i++) {
			if ((stride[i] + 1) % (min + 1) == 0) {
				
				//심어야 하는 나무 개수 세기 
				int tree = (stride[i] + 1) / (min + 1) -1; 
				answer += tree;

				if (i == stride.size() - 1) {
					cout << answer;
					return 0; //while문 종료
				}

			}
			else {
				min -= 1; //간격 줄이기 
				answer = 0; //초기화
				break;
			}

		}//end for 
	
	}//end while

}