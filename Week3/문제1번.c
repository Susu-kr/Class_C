#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char name[10];
	int age = 0;
	printf("�̸� : ");
	scanf("%s", &name);
	printf("���� : ");
	scanf("%d", &age);
	printf("%s ���� ���̴� %d�� �Դϴ�.", name, age);
	return 0; 
}