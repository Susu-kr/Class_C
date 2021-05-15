/*
	문제2. 두개의 int형 포인터 변수와 길이가 5인 int형 배열을 다음과 같이 선언한다.
	int *maxPtr;
	int *minPtr;
	int arr[5];
	MaxAndMin 이란 함수를 정의하고 이를 호출하여 위 배열과 두 포인터를 변수로 전달한다.
	이 함수의 호출이 완료되면, 포인터 변수 maxPtr에는 가장 큰 값이 저장된 배열요소의 주소값
	minPtr에는 가장 작은 값이 저장된 배열요소의 주소값이 저장되어야 한다.
	>
	arr 주소값과, 최대, 최소의 주소값
	그 주소에 저장된 값을 출력한다.
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
	printf("   arr의 주소값 : %u\n", arr);
	printf("maxPtr의 주소값 : %u, maxPtr의 값 : %d\n", maxPtr, *maxPtr);
	printf("minPtr의 주소값 : %u, minPtr의 값 : %d\n", minPtr, *minPtr);

}

void MaxAndMin(int *arr, int **max, int **min, int size) {
	int *pa = arr;
	for (int i = 0; i < size; i++) {
		if (**max < *pa) *max = pa;
		else if (**min > *pa) *min = pa;
		pa++;
	}
}