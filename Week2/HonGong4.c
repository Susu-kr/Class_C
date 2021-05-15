#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void DoublePointer(char **ppa, char **ppb);
void print_str(char **pps, int cnt);
void print_arr(int(*pa)[4]);
int sum(int, int);
int odd(int, int);
int mul(int, int);
//int div(int, int);

int main(void) {
	//int a = 10;
	//int *pi = &a;
	//int **ppi = &pi;
	//printf("--------------------------------------------\n");
	//printf("변수    변숫값     &연산     *연산    **연산\n");
	//printf("--------------------------------------------\n");
	//printf("a  %10d%10u\n", a, &a);
	//printf("pi %10u%10u%10d\n", pi, &pi, *pi);
	//printf("ppi%10u%10u%10u%10u\n", ppi, &ppi, *ppi, **ppi);

	//char *pa = "success";
	//char *pb = "failure";
	//printf("pa -> %s, %p, %p\n", pa, *pa, &pa);
	//printf("pb -> %s, %p, %p\n", pb, *pb, &pb);
	//DoublePointer(&pa, &pb);
	//printf("pa -> %s, %p, %p\n", pa, *pa, &pa);
	//printf("pb -> %s, %p, %p\n", pb, *pb, &pb);
	//char *ptr_arr[] = { "eagle", "tiger", "lion", "squirrel" };
	//int count;
	//count = sizeof(ptr_arr) / sizeof(ptr_arr[0]);
	//print_str(ptr_arr, count);
	//int arr[5];
	//printf("arr의 값 : %u\t", arr);
	//printf("arr의 주소 : %u\n", &arr);
	//printf("arr + 1의 값 : %u\t", arr + 1);
	//printf("&arr + 1의 주소 : %u\n", &arr + 1);
	//int arr[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	//print_arr(arr);
	//printf("%d\n", **(arr + 1) + 3);
	//int(*fp)(int, int);
	//int res;
	//fp = sum;
	//res = fp(10, 20);
	//printf("result : %d\n", res);
	//fp = odd;
	//res = fp(10, 20);
	//printf("result : %d\n", res);
	//fp = mul;
	//res = fp(102, 20);
	//printf("result : %d\n", res);
	//fp = div;
	//res = fp(4, 2);
	//printf("result : %d\n", res);
	//int a = 10;
	//double b = 3.5;
	//void *vp;
	//vp = &a;
	//printf("a : %d\n", *(int *)vp);
	//vp = &b;
	//printf("a : %.1lf\n", *(double *)vp);
	//int *pi;
	//pi = (int*)malloc(sizeof(int));
	//if (pi == NULL) {
	//	printf("# 메모리가 부족합니다.\n");
	//	exit(1);
	//}
	//*pi = 10;
	//printf("정수형으로 사용 : %d\n", *pi);

	//free(pi);
	//int *pi;
	//int sum = 0;
	//pi = (int*)malloc(5 * sizeof(int));
	//if (pi == NULL) {
	//	printf("메모리가 부족합니다.\n");
	//	exit(1);
	//}
	//printf("다섯 명의 나이를 입력하세요 : ");
	//for (int i = 0; i < 5; i++) {
	//	scanf("%d", &pi[i]);
	//	sum += pi[i];
	//}
	//printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
	//free(pi);

	int *pi;
	int size = 5;
	int count = 0;
	int num;
	pi = (int*)malloc(size, sizeof(int));
	// memset(pi, 0 , sizeof(int) * 5);
	// ZeroMemory(pi, sizeof(int) * 5);

	//pi = (int*)calloc(5, sizeof(int)); // 초기값 0
	// memcpy(pdset, psource, sizeof(int)*3);
	//realloc(pi, 5 * sizeof(int));
	while (1) {
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) break;
		if (count == size) {
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int));

		}
		pi[count++] = num;
	}
	for (int i = 0; i < count; i++) {
		printf("%5d", pi[i]);
	}
	free(pi);
	return 0;
}
int sum(int a, int b) {
	return (a + b);
}
int odd(int a, int b) {
	return (a - b);
}
int mul(int a, int b) {
	return (a*b);
}/*
int div(int a, int b) {
	return (a / b);
}*/
void print_arr(int(*pa)[4]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%5d", pa[i][j]);
		}
		printf("\n");
	}
}
void print_str(char **pps, int count) {
	for (int i = 0; i < count; i++) {
		printf("%s\n", pps[i]);
	}
}
void DoublePointer(char **ppa, char **ppb) {
	char *pt;
	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}