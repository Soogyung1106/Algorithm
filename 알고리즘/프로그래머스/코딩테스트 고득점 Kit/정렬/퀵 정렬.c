#include <stdio.h>

int getLeft(int arr[], int start, int end, int pivot, int result[]) {
	//arr의 start부터 end까지 숫자들 중에서 
	//pivot보다 작은 값들을 result에 채우는 함수
	//또한, 피벗의 왼쪽에 있는 원소들의 갯수를 반환
	
	int idx = 0;

	for (int i = start; i <= end; i++) {
		if (arr[i] <= pivot)
			result[idx++] = arr[i];
	}

	return idx; 
}


int getRight(int arr[], int start, int end, int pivot, int result[]) {
	//arr의 start부터 end까지 숫자들 중에서 
	//pivot보다 큰 값들을 result에 채우는 함수 
	//또한, 피벗의 오른쪽에 있는 원소들의 갯수를 반환

	int idx = 0;

	for (int i = start; i <= end; i++) {
		if (arr[i] > pivot)
			result[idx++] = arr[i];
	}

	return idx;

}



void quickSort(int arr[], int start, int end) {
	//arr을 start부터 end까지 퀵정렬하는 함수 

	//기저조건
	if (start >= end) //숫자가 하나밖에 없을 때 혹은 아예 x
		return;

	//피벗 기준 분류
	int pivot = arr[start]; //피봇 기준 : 맨 앞 원소 
	int left[100], right[100];
		
	int left_cnt = getLeft(arr, start+1, end, pivot, left); // arr배열의 pivot을 기준으로 작은 값들을 left 배열에 반환 
	int right_cnt = getRight(arr, start+1, end, pivot, right); // arr배열의 pivot을 기준으로 큰 값들을 right 배열에 반환 


	for (int i = 0; i < left_cnt; i++)
		arr[start+i] = left[i];

	arr[start + left_cnt] = pivot;

	for (int i = 0; i < right_cnt; i++)
		arr[start+left_cnt+1+i] = right[i];


	// 2 2 1 2 3 (4)  6 7 5 8 -> 현재 상태 


	//피벗 기준 정렬하기(-> start와 end 위치가 매번 바뀌게 됨)
	quickSort(arr, start, start+left_cnt-1); //왼쪽 정렬
	quickSort(arr, start + left_cnt + 1, end); //오른쪽 정렬


}

int main() {

	//입력
	int n;	scanf("%d", &n);
	
	int arr[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	//퀵정렬
	quickSort(arr, 0, n-1);

	//출력
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);


	return 0;


}