// 1주차 3일 HonGong Book 177p ~
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
	//printf("2이상의 정수를 입력하세요 : ");
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
	// 문제 1.
	// 입력 > n  .. n = 3;
	// 출력 >
	// *
	// **
	// ***
	// **
	// *
	//int num;
	//printf("숫자를 입력하세요 : ");
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
	//printf("숫자를 입력하세요 : ");
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
	//printf("숫자를 입력하세요 : ");
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
	//printf("숫자를 입력하세요 : ");
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
	// 문제2
	// 다음 식을 만족하는 모든 A와 Z를 구하는 프로그램을 작성하라
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
	// 문제 3.
	// 함수 abs() 구현하세요.입력받은 값의 절대값을 구하는 함수이다.
	// ex>
	// 정수 입력 : -34
	// 절대값은 34 입니다.
	// 종료하려면 0을 입력하세요.
	//int num;
	//printf("수를 입력하세요 : ");
	//scanf("%d", &num);
	//printf("%d",rec_func(num));

	// 문제 4.
	// 재귀함수를 이용해서 코드를 작성.(반복문을 이용해도 됨)
	// 새끼 달팽이가 한마리 있는데 한달이 지나면 성체가 되고 또 한달이 지나면 새끼를 낳는다.
	// 새로 태어난 달팽이 역시 한달이 지나면 성체가 되고, 다시 한달 뒤에 새끼를 낳는다고 할때,
	// 달팽이가 매달 새끼를 낳는다고 할때, n년후 전체 달팽이의 수를 출력하는 프로그램 작성
	// (가정1 : 달팽이가 n년안에 죽을 가능성은 없다.)
	// (가정2 : 한번에 한마리씩만 낳는다.)
	// 성인 달팽이 : O , 새끼 달팽이 : o
	// 1달 -> o
	// 2달 -> O
	// 3달 -> O o
	// 4달 -> O O o
	// 5달 -> O O O o o ...
	//int year;
	//printf("년도를 입력하세요 : ");
	//scanf("%d", &year);
	//int big, small;
	//for (int i = 1; i <= year * 12; i++) {
	//	printf("%d달 -> %d\n", i, snail(i-1));
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
//	printf("정수 입력 : ");
//	scanf("%d", &num);
//	printf("절대값은 %d 입니다.\n", abs(num));
//	printf("종료하려면 0을 입력하세요. ");
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
//	printf("양수 입력 : ");
//	scanf("%d", &num);
//	return num;
//}


