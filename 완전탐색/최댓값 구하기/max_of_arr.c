#include <stdio.h>

int main() {

	//Please Enter Your Code Here

	int max = 0;
	int tmp_i = 0, tmp_j = 0;
	int arr[9][9];

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j] > max) {
				max = arr[i][j];
				tmp_i = i; tmp_j = j;

			}
			else if (arr[i][j] == max) {
				continue;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d", tmp_i + 1, tmp_j + 1);


	return 0;
}