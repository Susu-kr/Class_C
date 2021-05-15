#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
	 문제1. 길이가 5인 int 형 배열을 선언하고, 
	 사용자로부터 5개의 정수를 입력받아 다음의 내용을 출력하라.
	 1. 입력된 정수중 최대값
	 2. 입력된 정수중 최솟값
	 3. 입력된 정수의 총합
	*/
	int arr[5] = { 0 };
	int max, min, tot = 0;
	for (int i = 0; i < 5; i++) {
		printf("수를 입력하세요 : ");
		scanf("%d", &arr[i]);
		if (i == 0) {
			max = arr[i];
			min = arr[i];
		}
		else if (max < arr[i]) {
			max = arr[i];
		}
		else if (min > arr[i]) {
			min = arr[i];
		}
		tot += arr[i];
	}
	printf("1. 입력된 정수중 최대값 : %d\n", max);
	printf("2. 입력된 정수중 최솟값 : %d\n", min);
	printf("3. 입력된 정수의 총합 : %d\n", tot);

	return 0;
}