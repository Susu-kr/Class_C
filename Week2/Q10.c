/*
	����2. �ΰ��� int�� ������ ������ ���̰� 5�� int�� �迭�� ������ ���� �����Ѵ�.
	int *maxPtr;
	int *minPtr;
	int arr[5];
	MaxAndMin �̶� �Լ��� �����ϰ� �̸� ȣ���Ͽ� �� �迭�� �� �����͸� ������ �����Ѵ�.
	�� �Լ��� ȣ���� �Ϸ�Ǹ�, ������ ���� maxPtr���� ���� ū ���� ����� �迭����� �ּҰ�
	minPtr���� ���� ���� ���� ����� �迭����� �ּҰ��� ����Ǿ�� �Ѵ�.
	>
	arr �ּҰ���, �ִ�, �ּ��� �ּҰ�
	�� �ּҿ� ����� ���� ����Ѵ�.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void MaxAndMin(int *arr, int **max, int **min, int size);

int main(void) {
	int arr[5];
	int size = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < size; i++) {
		scanf("%d", &arr[i]);
	}
	int *maxPtr = &arr[0];
	int *minPtr = &arr[0];

	MaxAndMin(arr, &maxPtr, &minPtr, size);
	printf("   arr�� �ּҰ� : %u\n", arr);
	printf("maxPtr�� �ּҰ� : %u, maxPtr�� �� : %d\n", maxPtr, *maxPtr);
	printf("minPtr�� �ּҰ� : %u, minPtr�� �� : %d\n", minPtr, *minPtr);

}

void MaxAndMin(int *arr, int **max, int **min, int size) {
	int *pa = arr;
	for (int i = 0; i < size; i++) {
		if (**max < *pa) *max = pa;
		else if (**min > *pa) *min = pa;
		pa++;
	}
}