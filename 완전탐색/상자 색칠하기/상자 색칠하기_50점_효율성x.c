#include <iostream>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	//2차원 벡터 생성
	vector<vector<int>> color_num; 	vector<int> v1, v2;
	color_num.push_back(v1); color_num.push_back(v2);


	for (int i = 0; i < n; i++) {
		int color;
		cin >> color;

		if (i == 0) {
			color_num[0].push_back(color);
			color_num[1].push_back(1);
		}else {
			
			//test
			for (int i = 0; i < color_num[0].size(); i++) {
				cout << "(" << color_num[0][i] << ", " << color_num[1][i] << ")" << endl;;
			}


			for (int j = 0; j < color_num[0].size(); j++) {

				if (color_num[0][j] == color) { //색 이미 있으면
					color_num[1][j] += 1;
					cout << color << endl;
					
					if (color_num[1][j] > 2) //2개로 초기화 -> 3개 이상은 의미 없으므로 
						color_num[1][j] = 2;

					break;

				}if (j == color_num[0].size() - 1) { //색 없으면 
					color_num[0].push_back(color);
					color_num[1].push_back(1);
				}


			}//end for
		}//end else
	}//end for

	//test
	for (int i = 0; i < color_num[0].size(); i++) {
		cout << "(" << color_num[0][i] << ", " << color_num[1][i]<<")";
	}


	int count = 0;

	for (int i = 0; i < color_num[0].size(); i++) {
		count += color_num[1][i];
	}

	if (count >= 6) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}


	return 0;
}