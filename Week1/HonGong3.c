// 1���� 3�� HonGong Book 177p ~
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int sum(int x, int y);
//int get_num(void);
//int abs(int x);
//void input(void);
//int rec_func(int n);
int snail(int y);
void sel();
void cal(int a);
int main() {
	//int num, j, cnt = 0;
	//printf("2�̻��� ������ �Է��ϼ��� : ");
	//scanf("%d", &num);
	//for (int i = 2; i <= num; i++) {
	//	for (j = 2; j < i; j++) {
	//		if (i % j == 0) break;
	//	}
	//	if (i == j) {
	//		cnt++;
	//		printf("\t%d", i);
	//		if (cnt == 5) {
	//			cnt = 0;
	//			printf("\n");
	//		}
	//	}
	// ���� 1.
	// �Է� > n  .. n = 3;
	// ��� >
	// *
	// **
	// ***
	// **
	// *
	//int num;
	//printf("���ڸ� �Է��ϼ��� : ");
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j <= i; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//for (int i = num - 1; i > 0; i--) {
	//	for (int j = i; j > 0; j--) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//int num;
	//printf("���ڸ� �Է��ϼ��� : ");
	//scanf("%d", &num);
	//for (int i = 0; i < num*2 - 1; i++) {
	//	if (i < (num * 2) / 2) {
	//		for (int j = 0; j <= i; j++) {
	//			printf("*");
	//		}
	//		printf("\n");
	//	}
	//	else {
	//		for (int j = num*2 - 1; j > i; j--) {
	//			printf("*");
	//		}
	//		printf("\n");
	//	}
	//}
	//int num;
	//printf("���ڸ� �Է��ϼ��� : ");
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	for (int j = num - 1; j > i; j--) {
	//		printf(" ");
	//	}
	//	for (int j = 0; j <= i; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//for (int i = num-1; i > 0; i--) {
	//	for (int j = num - 1; j >= i; j--) {
	//		printf(" ");
	//	}
	//	for (int j = 0; j < i; j++) {
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//int num;
	//printf("���ڸ� �Է��ϼ��� : ");
	//scanf("%d", &num);
	//for (int i = 0; i < num; i++) {
	//	for (int j = 0; j < num; j++) {
	//		/*
	//		if (i == j || i + j == num-1) printf("*");
	//		else printf(" ");
	//		*/
	//		printf((i == j || i + j == num - 1) ? "*" : " ");
	//	}
	//	printf("\n");
	//}
	// ����2
	// ���� ���� �����ϴ� ��� A�� Z�� ���ϴ� ���α׷��� �ۼ��϶�
	//   A Z
	// + Z A
	// ------
	//   9 9
	// A = 0 Z = 9
	// Z = 9 A = 0
	// -----------
	//     9     9
	//int num1, num2;
	//for(int i = 0; i < 10; i++){
	//	num1 = i;
	//	num2 = 9 - num1;
	//	printf("A = %d Z = %d\n", num1, num2);
	//	printf("Z = %d A = %d\n", num2, num1);
	//	printf("----------------\n");
	//	printf("    %d     %d\n", num1 + num2, num1 + num2);
	//	printf("----------------\n");
	//}
	//int a = 10, b = 20;
	//int result;
	//result = sum(a, b);
	//printf("result : %d\n", result);
	// ���� 3.
	// �Լ� abs() �����ϼ���.�Է¹��� ���� ���밪�� ���ϴ� �Լ��̴�.
	// ex>
	// ���� �Է� : -34
	// ���밪�� 34 �Դϴ�.
	// �����Ϸ��� 0�� �Է��ϼ���.
	//int num;
	//printf("���� �Է��ϼ��� : ");
	//scanf("%d", &num);
	//printf("%d",rec_func(num));

	// ���� 4.
	// ����Լ��� �̿��ؼ� �ڵ带 �ۼ�.(�ݺ����� �̿��ص� ��)
	// ���� �����̰� �Ѹ��� �ִµ� �Ѵ��� ������ ��ü�� �ǰ� �� �Ѵ��� ������ ������ ���´�.
	// ���� �¾ ������ ���� �Ѵ��� ������ ��ü�� �ǰ�, �ٽ� �Ѵ� �ڿ� ������ ���´ٰ� �Ҷ�,
	// �����̰� �Ŵ� ������ ���´ٰ� �Ҷ�, n���� ��ü �������� ���� ����ϴ� ���α׷� �ۼ�
	// (����1 : �����̰� n��ȿ� ���� ���ɼ��� ����.)
	// (����2 : �ѹ��� �Ѹ������� ���´�.)
	// ���� ������ : O , ���� ������ : o
	// 1�� -> o
	// 2�� -> O
	// 3�� -> O o
	// 4�� -> O O o
	// 5�� -> O O O o o ...
	//int year;
	//printf("�⵵�� �Է��ϼ��� : ");
	//scanf("%d", &year);
	//int big, small;
	//for (int i = 1; i <= year * 12; i++) {
	//	printf("%d�� -> %d\n", i, snail(i-1));
	//}

	return 0;
}
//int snail(int m) {
//	if (m == 0 || m == 1) return 1;
//	else {
//		return snail(m - 2) + snail(m - 1);
//	}
//}
//int rec_func(int n) {
//	int tot = n;
//	if(n != 0) tot += rec_func(n - 1);
//	printf("%d ", tot);
//	return tot;
//}
//int abs(int x) {
//	if (x < 0) {
//		return -x;
//	}
//	return x;
//}
//
//void input(void) {
//	int num;
//	printf("���� �Է� : ");
//	scanf("%d", &num);
//	printf("���밪�� %d �Դϴ�.\n", abs(num));
//	printf("�����Ϸ��� 0�� �Է��ϼ���. ");
//	scanf("%d", &num);
//	if (num == 0) {
//		return;
//	}
//	input();
//}
//int sum(int x, int y) {
//	return x + y;
//}
//int get_num(void) {
//	int num;
//	printf("��� �Է� : ");
//	scanf("%d", &num);
//	return num;
//}


