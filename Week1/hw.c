#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void sel();
int add(int a, int b);
int odd(int a, int b);
int mul(int a, int b);
double div(int a, int b);
int main() {
	sel();
	return 0;
}
int add(int a, int b) {
	return a + b;
}
int odd(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
double div(int a, int b) {
	return (double)a / (double)b;
}
void sel() {
	int num;
	printf("�޴��� �����ϼ���.\n");
	printf("1. ����\n2. ����\n3. ����\n4. ������\n5. ����\n");
	scanf("%d", &num);
	if (num == 5) return;
	printf("�� ���� �Է��ϼ���.\n");
	int num1, num2;
	scanf("%d%d", &num1, &num2);
	switch (num)
	{
	case 1:
		printf("%d + %d = %d\n", num1, num2, add(num1,num2));
		break;
	case 2:
		printf("%d + %d = %d\n", num1, num2, odd(num1, num2));
		break;
	case 3:
		printf("%d + %d = %d\n", num1, num2, mul(num1, num2));
		break;
	case 4:
		printf("%d + %d = %.1lf\n", num1, num2, div(num1, num2));
		break;
	}
	sel();
}