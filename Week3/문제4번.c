#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sel_sum(int *arr,int size, int target);

int main(void) {
	int N;
	printf("배열의 크기를 입력하세요 : ");
	scanf("%d", &N);
	int *arr = (int*)malloc(N * sizeof(int)); // 입력한 배열의 크기만큼 동적할당
	if (arr == NULL) {
		printf("메모리가 부족합니다!\n");
		exit(1);
	}
	printf("숫자를 입력하세요 : ");
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	} 
	int target; 
	printf("숫자 두개를 더해서 나올 합을 입력하세요 : ");
	scanf("%d", &target);
	sel_sum(arr, N, target);
	free(arr);
	return 0;
}

void sel_sum(int *arr,int size, int target) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] + arr[j] == target) {
				printf("%d, %d", i, j);
				return;
			}
		}
	}
}