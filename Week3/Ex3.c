#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cracker {
	int price;
	int calories;
};

int main(void) {
	struct cracker A;
	printf("�ٻ���� ���ݰ� ������ �Է��ϼ��� : ");
	scanf("%d%d", &(A.price), &(A.calories));
	printf("�ٻ���� ���� : %d��\n", A.price);
	printf("�ٻ���� ���� : %dkcal\n", A.calories);
	return 0;
}
