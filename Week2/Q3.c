#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	/*
		����3.
		int �� ���� num1, num2�� ����� ���ÿ� ���� 10�� 20���� �ʱ�ȭ �ϰ�,
		int�� ������ ���� ptr1, ptr2�� �����Ͽ� ���� num1, num2�� ����Ű�� ����.
		ptr1 -> num1, ptr2 -> num2;
		�� ���¿��� ������ ���� ptr1�� ptr2�� �̿��ؼ� num1�� ���� 10����
		num2�� ���� 10 ���ҽ�Ų �� �� ������ ���� ptr1�� ptr2�� ����Ű�� ����� ���� �ٲ۴�.
		ptr1 -> num2, prt2 -> num1;
		���������� ptr1�� ptr2�� ����Ű�� ������ ����� ���� ����϶�.
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