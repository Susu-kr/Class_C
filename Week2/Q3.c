#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
		문제3.
		int 형 변수 num1, num2를 선언과 동시에 각각 10과 20으로 초기화 하고,
		int형 포인터 변수 ptr1, ptr2를 선언하여 각각 num1, num2를 가리키게 하자.
		ptr1 -> num1, ptr2 -> num2;
		이 상태에서 포인터 변수 ptr1과 ptr2를 이용해서 num1의 값을 10증가
		num2의 값을 10 감소시킨 후 두 포인터 변수 ptr1과 ptr2가 가리키는 대상을 서로 바꾼다.
		ptr1 -> num2, prt2 -> num1;
		마지막으로 ptr1과 ptr2가 가리키는 변수에 저장된 값을 출력하라.
	*/
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1, *ptr2 = &num2;
	printf("*ptr1 : %d, *ptr2 : %d\n", *ptr1, *ptr2);
	*ptr1 += 10;
	*ptr2 -= 10;
	printf("*ptr1 : %d, *ptr2 : %d\n", *ptr1, *ptr2);
	printf("&num1 : %d, &num2 : %d\n", &num1, &num2);
	printf("ptr1 : %d, ptr2 : %d\n", ptr1, ptr2);
	int temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
	printf("&num1 : %d, &num2 : %d\n", &num1, &num2);
	printf("ptr1 : %d, ptr2 : %d\n", ptr1, ptr2);
	printf("num1 : %d, num2 : %d\n", num1, num2);
	return 0;
}