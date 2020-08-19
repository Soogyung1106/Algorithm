#include <iostream>
#include <cstdio>

using namespace std;

int greedy(int arr[], int money) {

	int count = 0;	int curr = 1000 - money;

	for (int i = 0; i < 6; i++) {
		if (curr >= arr[i] && curr != 0) {
			int tmp = curr / arr[i];
			curr = curr - tmp * arr[i];
			count += tmp;
		}
	}

	return count;

}


int main() {

	int money; cin >> money;
	int arr[6] = { 500, 100, 50, 10, 5, 1 };

	cout << greedy(arr, money);

	return 0;
}

