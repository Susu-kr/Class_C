#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//void auto_func(void);
//void static_func(void);
//int* Test(int* pA);
int main(void) {
	//int a = 10, b = 20;
	//printf("��ȯ �� a �� b�� �� : %d, %d\n", a, b);
	//{
	//	int temp = 30;
	//	int a = 50;
	//	a = b;
	//	b = temp;
	//}
	//printf("��ȯ �� a�� b�� �� : %d, %d\n", a, b);
	//printf("�Ϲ� ���� ����(auto)�� ����� �Լ�...\n");
	//for (int i = 0; i < 3; i++) {
	//	auto_func();
	//}
	//printf("���� ���� ����(static)�� ����� �Լ�...\n");
	//for (int i = 0; i < 3; i++) {
	//	static_func();
	//}
	//int a = 10;
	//int* c = Test(&a);
	//printf("%d", c);

	//int score[3][4];
	//int total;
	//double avg;
	//for (int i = 0; i < 3; i++) {
	//	printf("4������ ���� �Է� : ");
	//	for (int j = 0; j < 4; j++) {
	//		scanf("%d", &score[i][j]);
	//	}
	//}

	//for (int i = 0; i < 3; i++) {
	//	total = 0;
	//	for (int j = 0; j < 4; j++) {
	//		total += score[i][j];
	//	}
	//	avg = total / 4.0;
	//	printf("���� : %d, ��� : %.2lf\n", total, avg);
	//}
	//int *pc;
	//int *pArr[3];
	//char *str1 = "dog";
	//char *str2 = "elephant";
	//char *pStr[2];
	//pStr[0] = "dog";
	//pStr[1] = "elephant";

	int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 11,12,13,14 };
	int arr3[4] = { 21,22,23,24 };
	int* pArr[3] = { arr1, arr2, arr3 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%5d", pArr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

//int* Test(int* pA) {
//	static int c = 0;
//	c = *pA += 10;
//	return &c;
//}
//void auto_func(void) {
//	auto int a = 0;
//	a++;
//	printf("%d\n", a);
//}
//
//void static_func(void) {
//	static int a;
//	a++;
//	printf("%d\n", a);
//}