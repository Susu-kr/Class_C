/*
	����1.
	���̰� 6�� int�� �迭 arr�� �����ϰ� �̸� 1,2,3,4,5,6 ���� �ʱ�ȭ �� ����
	�迭�� ����� ���� ������ 6,5,4,3,2,1 �� �ǵ��� �����ϴ� ���α׷��� �ۼ�
	��, �迭�� �հ� �ڸ� ����Ű�� ������ ���� �ΰ��� �����ؼ� �̸� Ȱ��
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print_arr(int *arr, int size);
void swap_arr(int *arr, int size);
int main(void) {
	int arr[6] = { 1,2,3,4,5,6 };
	int size = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, size);
	swap_arr(arr, size / 2);
	print_arr(arr, size);
}

void print_arr(int* arr, int size) {
	printf("arr : ");
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void swap_arr(int *arr, int size) {
	printf("swap\n");
	int *p_f = arr; // arr[0]
	int *p_b = p_f + 5; // arr[5]
	for (int i = 0; i < size; i++) {
		int temp = *p_f; // temp = arr[0]
		*p_f = *p_b;
		*p_b = temp;
		p_f++; // arr[1] , arr[2]
		p_b--; // arr[4] , arr[3] 
	}
}