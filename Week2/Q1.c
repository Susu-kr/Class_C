#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
	 ����1. ���̰� 5�� int �� �迭�� �����ϰ�, 
	 ����ڷκ��� 5���� ������ �Է¹޾� ������ ������ ����϶�.
	 1. �Էµ� ������ �ִ밪
	 2. �Էµ� ������ �ּڰ�
	 3. �Էµ� ������ ����
	*/
	int arr[5] = { 0 };
	int max, min, tot = 0;
	for (int i = 0; i < 5; i++) {
		printf("���� �Է��ϼ��� : ");
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
	printf("1. �Էµ� ������ �ִ밪 : %d\n", max);
	printf("2. �Էµ� ������ �ּڰ� : %d\n", min);
	printf("3. �Էµ� ������ ���� : %d\n", tot);

	return 0;
}