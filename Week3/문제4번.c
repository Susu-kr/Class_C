#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sel_sum(int *arr,int size, int target);

int main(void) {
	int N;
	printf("�迭�� ũ�⸦ �Է��ϼ��� : ");
	scanf("%d", &N);
	int *arr = (int*)malloc(N * sizeof(int)); // �Է��� �迭�� ũ�⸸ŭ �����Ҵ�
	if (arr == NULL) {
		printf("�޸𸮰� �����մϴ�!\n");
		exit(1);
	}
	printf("���ڸ� �Է��ϼ��� : ");
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	} 
	int target; 
	printf("���� �ΰ��� ���ؼ� ���� ���� �Է��ϼ��� : ");
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